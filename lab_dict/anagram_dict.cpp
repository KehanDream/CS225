/**
 * @file anagram_dict.cpp
 * Implementation of the AnagramDict class.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include "anagram_dict.h"

#include <algorithm> /* I wonder why this is included... */
#include <fstream>

using std::string;
using std::vector;
using std::ifstream;

/**
 * Constructs an AnagramDict from a filename with newline-separated
 * words.
 * @param filename The name of the word list file.
 */
AnagramDict::AnagramDict(const string& filename)
{
    /* Your code goes here! */
	string currWord;
	ifstream filePtr(filename);
	filePtr.open(filename);
	while(filePtr.good())	{
		getline(filePtr, currWord);
		string temp;
		std::sort(temp.begin(), temp.end());
		dict[temp].push_back(currWord);
	}
}

/**
 * Constructs an AnagramDict from a vector of words.
 * @param words The vector of strings to be used as source words.
 */
AnagramDict::AnagramDict(const vector<string>& words)
{
    /* Your code goes here! */
	//std::vector<string>::const_iterator it;
	for(auto it = words.begin(); it != words.end(); it++)	{
		string temp = *it;
		std::sort(temp.begin(), temp.end());	
    		dict[temp].push_back(*it);
	}
}

/**
 * @param word The word to find anagrams of.
 * @return A vector of strings of anagrams of the given word. Empty
 * vector returned if no anagrams are found or the word is not in the
 * word list.
 */
vector<string> AnagramDict::get_anagrams(const string& word) const
{
    /* Your code goes here! */
	//vector<string> anagramList;
	string copy = word;
	std::sort(copy.begin(), copy.end());
	//std::vector<string>::const_iterator it;
	/*std::string::const_iterator it;
	for(it = word.begin(); it != word.end(); it++)	{
		
	}*/
	if(dict.find(copy) != dict.end())	{
		return dict.find(copy)->second;
	}
    return vector<string>();
}

/**
 * @return A vector of vectors of strings. Each inner vector contains
 * the "anagram siblings", i.e. words that are anagrams of one another.
 * NOTE: It is impossible to have one of these vectors have less than
 * two elements, i.e. words with no anagrams are ommitted.
 */
vector<vector<string>> AnagramDict::get_all_anagrams() const
{
    /* Your code goes here! */
	vector<vector<string>> ret;
	/*std::map<std::string, std::vector<std::string>>::iterator it;
	for(it = dict.begin(); it != dict.end(); it++)	{
		if(it->second.size() > 1)	{
			ret.push_back(it->second);
		}
	}*/
	/*for(const std::pair<string, vector<string>> & key_val : dict)	{
		if(key_val.second.size() > 1)       {
                        ret.push_back(key_val.second);
                }
	}*/
	for(auto it = dict.begin(); it != dict.end(); it++)	{
    		if(it->second.size() > 1)	{
  	  		ret.push_back(it->second);
		}
	}	
	if(ret.size() > 0)	{
		return ret;
	}
    return vector<vector<string>>();
}
