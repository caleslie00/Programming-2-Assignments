#include <cstddef>

template <typename T>
struct Node {
    T     data;
    Node<T>* left;
    Node<T>* right;
};
    
template <typename T>
struct Tree {
    Node<T>* root;
};

// provided functions
template <typename T>
void initialize(Tree<T> &t)
{
    t.root = NULL;
}

// This is the recursive destroy function, accepting a Node* argument.
template <typename T>
void destroy(Node<T>* n)
{
    if( n == NULL )
        return;
    
    destroy(n->left);  // Recursively destroy left subtree
    destroy(n->right); // Recursively destroy right subtree
    delete n;          // Delete this node
}

// This is the function called by the user, to destroy a Tree.
// It will call the recursive function, beginning with the root node.
template <typename T>
void destroy(Tree<T> &t)
{
    destroy(t.root);
    t.root = NULL;
}

template <typename T>
void insert(Tree<T> &t, T value)
{
    // Create new node to add to the tree
    Node<T>* newNode = new Node<T>;
    newNode->data  = value;
    newNode->left  = NULL;
    newNode->right = NULL;
    
    if( t.root == NULL ) { // empty tree
        t.root = newNode;
        return;
    }
        
    Node<T>* walker = t.root;
    while( true )
    {
        if( value < walker->data )
        {
            if( walker->left == NULL )
            {
                walker->left = newNode;
                return;
            }
            else
                walker = walker->left;
        }
        else // value >= walker->data
        {
            if( walker->right == NULL )
            {
                walker->right = newNode;
                return;
            }
            else
                walker = walker->right;            
        }
    }
}

// Return depth (level) at which value appears
//    or 0 if value is not in tree
template <typename T>
int contains(Tree<T> &t, T value)
{
    Node<T>* walker = t.root;
    int depth = 1;
    while( walker != NULL )
    {
        if( walker->data == value )
            return depth;
        else if( value < walker->data )
            walker = walker->left;
        else // value >= walker->data
            walker = walker->right;
        depth++;
    }
    return 0;
}

// implement these functions
template <typename T>
int  countNodes(Tree<T> &t) //counts the number of Nodes from the root
{
    if(t.root == NULL)
    {
        return 0;
    }
    return countNodes(t.root);
}
template <typename T>
int  countNodes(Node<T>* &p) //counts the number of Nodes from the Node which you passed it recursively
{
    if(p == NULL)
    {
        return 0;
    }
    return countNodes(p->left) + countNodes(p->right) + 1;
}
template <typename T>
int  height(Tree<T> &t) //finds the max height of a tree
{
    if(t.root == NULL)
    {
        return 0;
    }
    return height(t.root);
}
template <typename T>
int  height(Node<T>* &p) //finds the max height from the node you pass it recursively
{
    if(p == NULL)
    {
        return 0;
    }
    return 1 + ((height(p->left) > height(p->right)) ? height(p->left) : height(p->right));
}
template <typename T>
int  countLeaf(Tree<T> t) //counts the number of leaves in a tree
{
    if(t.root == NULL)
        return 0;
    return countLeaf(t.root);
}
template <typename T>
int  countLeaf(Node<T>* p) //counts as 1 if it is a leaf, otherwise branches out to look for a leaf, if it's NULL returns 0
{
    if(p == NULL)
        return 0;
    if(p->left != NULL || p->right != NULL)
        return countLeaf(p->left) + countLeaf(p->right);
    return 1;
}
template <typename T>
int  countDouble(Tree<T> t) //count Nodes with two children
{
    if(t.root == NULL)
        return 0;
    return countDouble(t.root);
}
template <typename T>
int  countDouble(Node<T>* p) //counts all Nodes with two children
{
    if(p == NULL)
        return 0;
    if(p->left != NULL && p->right != NULL)
        return 1 + countDouble(p->left) + countDouble(p->right);
    return countDouble(p->left) + countDouble(p->right);
}
template <typename T>
T    kthValue(Tree<T> t, int k) //returns the kth lowest value in the list
{
    return kthValue(t.root, k);
    
}
template <typename T>
T    kthValue(Node<T>* p, int k) //returns the kth value from the Node passed
{
    if(countNodes(p->left)+1 == k) //if we are at the kth node, return it's value
        return p->data;
    else if(countNodes(p->left)+1 < k) //if we are to the left of the kth value, go right
        return kthValue(p->right, k-(countNodes(p->left)+1));
    else //otherwise, we are to the right of it and need to go left
        return kthValue(p->left, k);
}