/**
 * @file binarytree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

/**
 * @return The height of the binary tree. Recall that the height of a binary
 *  tree is just the length of the longest path from the root to a leaf, and
 *  that the height of an empty tree is -1.
 */
template <typename T>
int BinaryTree<T>::height() const
{
    // Call recursive helper function on root
    return height(root);
}

/**
 * Private helper function for the public height function.
 * @param subRoot
 * @return The height of the subtree
 */
template <typename T>
int BinaryTree<T>::height(const Node* subRoot) const
{
    // Base case
    if (subRoot == NULL)
        return -1;

    // Recursive definition
    return 1 + max(height(subRoot->left), height(subRoot->right));
}

/**
 * Prints out the values of the nodes of a binary tree in order.
 * That is, everything to the left of a node will be printed out before that
 * node itself, and everything to the right of a node will be printed out after
 * that node.
 */
template <typename T>
void BinaryTree<T>::printLeftToRight() const
{
    // Call recursive helper function on the root
    printLeftToRight(root);

    // Finish the line
    cout << endl;
}

/**
 * Private helper function for the public printLeftToRight function.
 * @param subRoot
 */
template <typename T>
void BinaryTree<T>::printLeftToRight(const Node* subRoot) const
{
    // Base case - null node
    if (subRoot == NULL)
        return;

    // Print left subtree
    printLeftToRight(subRoot->left);

    // Print this node
    cout << subRoot->elem << ' ';

    // Print right subtree
    printLeftToRight(subRoot->right);
}

/**
 * Flips the tree over a vertical axis, modifying the tree itself
 *  (not creating a flipped copy).
 */
template <typename T>
void BinaryTree<T>::mirror()
{
    //your code here
    mirror(root);
}

template <typename T>
void BinaryTree<T>::mirror(Node* subRoot)
{
if(subRoot==NULL)
	return;

Node * right=subRoot->right;
Node * left=subRoot->left;
subRoot->left=right;
subRoot->right=left;
mirror(subRoot->left);
mirror(subRoot->right);
return;
}
/**
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrdered() const
{
    // your code here
   return isOrdered(root);
}

template <typename T>
bool BinaryTree<T>::isOrdered(Node* subRoot)const
{
	if(subRoot==NULL) return true;
	bool Nbig=isOrderedNbig(subRoot,subRoot->left);
	bool Nsmall=isOrderedNsmall(subRoot,subRoot->right);
	if(!Nbig|| !Nsmall){
		return false;
	}
	bool left=isOrdered(subRoot->left);
	bool right=isOrdered(subRoot->right);
	bool order=left && right;
	return order;
}

template <typename T>
bool BinaryTree<T>::isOrderedNbig(Node* subRoot,Node* left)const
{	if(subRoot==NULL || left==NULL)return true;
	if(left->elem>=subRoot->elem){
		return false;
	}
	bool lchild= isOrderedNbig(subRoot,left->left);
	bool rchild= isOrderedNbig(subRoot,left->right);
	return lchild && rchild;
	}

template <typename T>
bool BinaryTree<T>::isOrderedNsmall(Node* subRoot, Node* right)const
{	if(subRoot==NULL || right==NULL) return true;
	if(right->elem<=subRoot->elem){
		return false;
	}
	bool lchild= isOrderedNsmall(subRoot,right->left);
	bool rchild= isOrderedNsmall(subRoot,right->right);
	return lchild && rchild;
}///////////////////////interesting transversal


/*template <typename T>
void BinaryTree<T>::isOrdered(Node* subRoot)
{
 bool order=TRUE;
 if(subRoot==NULL)
	return TRUE; //true??
 if(subRoot->left->data >= subRoot->data || subRoot->right->data <= subRoot->data){
	return false;
 }

//gotta compare all of left's children to make sure node is bigger and similarly smaller for right's kids
//need to do a breadth first tranversal??? 
 bool left=isOrdered(subRoot->left);
 bool right=isOrdered(subRoot->right);
order=left && right;

 return;
}*/
/**
 * creates vectors of all the possible paths from the root of the tree to any leaf
 * node and adds it to another vector.
 * Path is, all sequences starting at the root node and continuing
 * downwards, ending at a leaf node. Paths ending in a left node should be
 * added before paths ending in a node further to the right.
 * @param paths vector of vectors that contains path of nodes
 */
template <typename T>
void BinaryTree<T>::printPaths(vector<vector<T> > &paths) const
{
    // your code here
}


/**
 * Each node in a tree has a distance from the root node - the depth of that
 * node, or the number of edges along the path from that node to the root. This
 * function returns the sum of the distances of all nodes to the root node (the
 * sum of the depths of all the nodes). Your solution should take O(n) time,
 * where n is the number of nodes in the tree.
 * @return The sum of the distances of all nodes to the root
 */
template <typename T>
int BinaryTree<T>::sumDistances() const
{
    // your code here
    return -1;
}
