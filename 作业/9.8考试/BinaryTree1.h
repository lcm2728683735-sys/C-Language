#ifndef __BinaryTree1_H__
#define __BinaryTree1_H__

using ElementType = int;
class BinaryTree1
{
public:
    BinaryTree1();
    ~BinaryTree1();
    void Insert(const ElementType & element);
    void show();
    ElementType* FindElement(const ElementType & element);
    void RemoveByElement(const ElementType & element);
    ElementType* CommonAncestor(const ElementType &a, const ElementType &b);
private:
    struct TreeNode1
    {
        TreeNode1(const ElementType & element)
        {
            value = element;
            left = right = parent = nullptr; 
        }
        ElementType value;
        TreeNode1* left;
        TreeNode1* right;
        TreeNode1* parent;
    };
    TreeNode1* InsertNode(TreeNode1 * node ,const ElementType & element);
    void PrevTravel(TreeNode1 * node);
    void MidTravel(TreeNode1 * node);
    void PostTravel(TreeNode1 * node);
    void FreeNode(TreeNode1* node);
    ElementType* FindNode(TreeNode1 *node,const ElementType & element); 
    BinaryTree1::TreeNode1 * RemoveNode(TreeNode1* node ,const ElementType & element);
    TreeNode1* GetMinNode(TreeNode1* node);
    TreeNode1* RotateRight(TreeNode1* node);
    TreeNode1* RotateLeft(TreeNode1* node);
    TreeNode1* RotateLeftRight(TreeNode1* node);
    TreeNode1* RotateRightLeft(TreeNode1* node);
    TreeNode1* CommonAncestor(TreeNode1* a, TreeNode1* b);
    TreeNode1* FindNodeByValue(const ElementType & element);
    TreeNode1* FindNodeByValue(TreeNode1* node,const ElementType & element);
    int GetNodeHeight(TreeNode1 * node);
    int LRDvtion(TreeNode1 * node);
    TreeNode1* root;
};



#endif