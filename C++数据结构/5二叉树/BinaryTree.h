#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

using ElementType = int;
class BinaryTree
{
public:
    BinaryTree();
    ~BinaryTree();

    void Insert(const ElementType & element);
    void show();
    ElementType* FindElement(const ElementType & element);
    void RemoveByElement(const ElementType & element);
private:
    struct TreeNode
    {
        TreeNode(const ElementType & element)
        {
            value = element;
            left = right = parent = nullptr; 
        }
        ElementType value;
        TreeNode* left;
        TreeNode* right;
        TreeNode* parent;
    };
    TreeNode* InsertNode(TreeNode * node ,const ElementType & element);
    void PrevTravel(TreeNode * node);
    void MidTravel(TreeNode * node);
    void PostTravel(TreeNode * node);
    void FreeNode(TreeNode* node);
    ElementType* FindNode(TreeNode *node,const ElementType & element); 
    BinaryTree::TreeNode * RemoveNode(TreeNode* node ,const ElementType & element);
    TreeNode* GetMinNode(TreeNode* node);
    TreeNode* RotateRight(TreeNode* node);
    TreeNode* RotateLeft(TreeNode* node);
    TreeNode* RotateLeftRight(TreeNode* node);
    TreeNode* RotateRightLeft(TreeNode* node);
    int GetNodeHeight(TreeNode * node);
    int LRDvtion(TreeNode * node);
    TreeNode* root;
};



#endif