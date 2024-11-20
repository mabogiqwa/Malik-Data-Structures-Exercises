#include <iostream>
using namespace std;

template <class elemType>
struct nodeType
{
    elemType info;
    nodeType<elemType> *lLink;
    nodeType<elemType> *rLink;
};

template <class elemType>
class binaryTreeType
{
public:
    const binaryTreeType<elemType>& operator =(const binaryTreeType<elemType>&);
    //Overload the assignment operator

    bool isEmpty() const;
    //Determines whether binary tree is empty
    //Postcondition: Returns true if binary tree is empty

    void inorderTraversal() const;
    //Inorder traversal of a binary tree
    //Nodes are printed inorder sequence

    void preorderTraversal() const;
    //Preorder traversal of a binary tree
    //Postcondition: Nodes are printed in preorder sequence

    void postorderTraversal() const;
    //Postorder traversal of the binary tree.
    //Postcondition: Nodes are printed in postorder sequence

    int treeHeight() const;
    //Determines the height of a binary tree
    //Postcondition: Returns the heeight of the binary tree.

    int treeNodeCount() const;
    //Determines the number of nodes in a binary tree
    //Postcondition: Returns the number of nodes in the binary tree

    int treeLeavesCount() const;
    //Function to determine leaves in a binary tree
    //Postcondition: Returns number of leaves in the binary tree

    int destroyTree();
    //Function to destroy binary tree
    //Postcondition: Memory space occupied by each node is deallocated.

    virtual bool search(const elemType& insertItem) = 0;
    //Function to determine if searchItem in the binary tree
    //Returns true if search item is foudn in the binary tree

    virtual void insert(const elemType& insertItem) = 0;
    //Function to determine if insertItem in the binary tree
    //Postcondition: If there is no node in the binary tree with the same info
    //as the insertItem, a node with the info insertItem is created and inserted in 
    //the binary search tree.

    virtual void deleteNode(const elemType& deleteItem) = 0;
    //Function to delete deleteIem from the binary tree
    //Postcondition: If a node with same info as the deleyeItem is found, it is deleted
    //from the binary tree.

    binaryTreeType(const binaryTreeType<elemType>& otherTree);
    //Copy Constructor

    binaryTreeTyep();
    //Default constructor

protected:
    nodeType<elemType> *root;

private:
    void copyTree(nodeType<elemType>* &copiedTreeRoot,
                  nodeType<elemType>* otherTreeRoot);
    //Makes a copy of the binary tree to which
    //otherTreeRoot points.
    //Postcondition: The pointer copiedTreeRoot points to
    //               the root of the copied binary tree.
    void destroy(nodeType<elemType>* &p);
    //Function to destroy the binary tree to which p points.
    //Postcondition: Memory space occupied by each node, in
    //               the binary tree to which p points, is
    //               deallocated.
    //               p = nullptr;
    void inorder(nodeType<elemType> *p) const;
    //Function to do an inorder traversal of the binary
    //tree to which p points.
    //Postcondition: Nodes of the binary tree, to which p
    //               points, are printed in inorder sequence.
    void preorder(nodeType<elemType> *p) const;
    //Function to do a preorder traversal of the binary
    //tree to which p points.
    //Postcondition: Nodes of the binary tree, to which p
    //    points, are printed in preorder
    //    sequence.
    void postorder(nodeType<elemType> *p) const;
    //Function to do a postorder traversal of the binary
    //tree to which p points.
    //Postcondition: Nodes of the binary tree, to which p
    //               points, are printed in postorder
    //               sequence.
    int height(nodeType<elemType> *p) const;
    //Function to determine the height of the binary tree
    //to which p points.
    //Postcondition: Height of the binary tree to which
    //               p points is returned.
    int max(int x, int y) const;
    //Function to determine the larger of x and y.
    //Postcondition: Returns the larger of x and y.
    int nodeCount(nodeType<elemType> *p) const;
    //Function to determine the number of nodes in
    //the binary tree to which p points.
    //Postcondition: The number of nodes in the binary
    //               tree to which p points is returned.
    int leavesCount(nodeType<elemType> *p) const;
    //Function to determine the number of leaves in
    //the binary tree to which p points
    //Postcondition: The number of leaves in the binary
    //               tree to which p points is returned.
};

int main()
{

    return 0;
}

template <class elemType>
bool binaryTreeType<elemType>::isEmpty() const
{
    return (root == nullptr);
}
template <class elemType>
binaryTreeType<elemType>::binaryTreeType()
{
    root = nullptr;
}
template <class elemType>
void binaryTreeType<elemType>::inorderTraversal() const
{
    inorder(root);
}
template <class elemType>
void binaryTreeType<elemType>::preorderTraversal() const
{
    preorder(root);
}
template <class elemType>
void binaryTreeType<elemType>::postordertraversal() const
{
    postorder(root);
}
template <class elemType>
void binaryTreeType<elemType>::treeHeight() const
{
    return height(root);
}
template <class elemType>
int binaryTreeType<elemType>::treeNodeCount() const
{
    return nodeCount(root);
}
template <class elemType>
void binaryTreeType<elemType>::inorder(nodeType<elemType> *p) const
{
    if(p != nullptr)
    {
        inorder(p->lLink);
        cout << p->info << " ";
        inorder(p->rLink);
    }
}
template <class elemType>
void binaryTreeType<elemType>::preorder(nodeType<elemType> *p) const
{
    if (p != nullptr)
    {
        cout << p->info << " ";
        preorder(p->lLink);
        preorder(p->rLink);
    }
}
template <class elemType>
void binaryTreeType<elemType>::postorder(nodeType<elemType> *p) const
{
    if (p != nullptr)
    {
        postorder(p->lLink);
        postorder(p->rLink);
        cout << p->info << " ";
    }
}
template<class elemType>
int binaryTreeType<elemType>::height(nodeType<elemType> *p) const
{
    if (p == nullptr)
        return 0;
    else
        return 1 + max(height(p->lLink), height(p->rLink));
}
template <class elemType>
int binaryTreeType<elemType>::max(int x, int y) const
{
    if (x >= y)
        return x;
    else
        return y;
}
template <class elemType>
void binaryTreeType<elemType>::copyTree(nodeType<elemType>* &copiedTreeRoot, nodeType<elemType>* otherTreeRoot)
{
    if (otherTreeRoot == nullptr)
        copiedTreeRoot = nullptr;
    else
    {
        copiedTreeRoot = new nodeType<elemType>;
        copiedTreeRoot->info = otherTreeRoot->info;
        copyTree(copiedTreeRoot->lLink, otherTreeRoot->lLink);
        copyTree(copiedTreeRoot->rLink, otherTreeRoot->rLink);
    }
} 
template <class elemType>
void binaryTreeType<elemType>::destroy(nodeType<elemType>* &p)
{
 if (p != nullptr)
    {
        destroy(p->lLink);
        destroy(p->rLink);
        delete p;
        p = nullptr;
    }
}
template <class elemType>
void binaryTreeType<elemType>::destroyTree()
{
   destroy(root);
}
//copy constructor
template <class elemType>
binaryTreeType<elemType>::binaryTreeType(const binaryTreeType<elemType>& otherTree)
{
    if (otherTree.root == nullptr) //otherTree is empty
        root = nullptr;
    else
        copyTree(root, otherTree.root);
}
//Destructor
//Deallocates memory when binaryTree object goes out of scope.
template <class elemType>
binaryTreeType<elemType>::~binaryTreeType()
{
    destroy(root);
}
template <class elemType>
const binaryTreeType<elemType>& binaryTreeType<elemType>::operator=(const binaryTreeType<elemType>& otherTree)
{ 
    if (this != &otherTree) //avoid self-copy
    {
        if (root != nullptr)  //if the binary tree is not empty,
        //destroy the binary tree
            destroy(root);
        if (otherTree.root == nullptr) //otherTree is empty
            root = nullptr;
        else
            copyTree(root, otherTree.root);
    }//end else
    return *this; 
}