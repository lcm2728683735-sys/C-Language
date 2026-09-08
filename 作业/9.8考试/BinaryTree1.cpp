#include "BinaryTree1.h"
#include <iostream>

BinaryTree1::BinaryTree1()
{
    root = nullptr;
}

BinaryTree1::~BinaryTree1()
{
    FreeNode(root);
}

void BinaryTree1::Insert(const ElementType &element)
{
    root = InsertNode(root, element);
}

void BinaryTree1::show()
{
    std::cout << "前：";
    PrevTravel(root);
    std::cout << std::endl;

    std::cout << "中：";
    MidTravel(root);
    std::cout << std::endl;

    std::cout << "后：";
    PostTravel(root);
    std::cout << std::endl;
}

ElementType *BinaryTree1::FindElement(const ElementType &element)
{
    return FindNode(root, element);
}


void BinaryTree1::RemoveByElement(const ElementType &element)
{
    root = RemoveNode(root, element);
}

BinaryTree1::TreeNode1 *BinaryTree1::InsertNode(TreeNode1 *node, const ElementType &element)
{
    // 终止
    if (node == nullptr)
        return new TreeNode1(element);
    // 数据已经存在
    if (node->value == element)
        return node;
    if (node->value > element)
    {
        // 递归插入左子树
        node->left = InsertNode(node->left, element);
        if (LRDvtion(node) > 1)
        {
            // 左左失衡
            if (element < node->left->value)
            {
                node = RotateRight(node);
            }
            // 左右
            else
            {
                node = RotateLeftRight(node);
            }
        }
    }
    else
    {
        // 递归插入右子树
        node->right = InsertNode(node->right, element);
        // 右失衡
        if (LRDvtion(node) < -1)
        {
            // 右右失衡
            if (element > node->right->value)
            {
                node = RotateLeft(node);
            }
            // 右左
            else
            {
                node = RotateRightLeft(node);
            }
        }
    }
    return node;
}

void BinaryTree1::PrevTravel(TreeNode1 *node)
{
    if (node == nullptr)
        return;
    std::cout << node->value << " ";
    PrevTravel(node->left);
    PrevTravel(node->right);
}

void BinaryTree1::MidTravel(TreeNode1 *node)
{
    if (node == nullptr)
        return;
    MidTravel(node->left);
    std::cout << node->value << " ";
    MidTravel(node->right);
}

void BinaryTree1::PostTravel(TreeNode1 *node)
{
    if (node == nullptr)
        return;
    PostTravel(node->left);
    PostTravel(node->right);
    std::cout << node->value << " ";
}

void BinaryTree1::FreeNode(TreeNode1 *node)
{
    if (node == nullptr)
        return;
    FreeNode(node->left);
    FreeNode(node->right);
    delete node;
}

ElementType *BinaryTree1::FindNode(TreeNode1 *node, const ElementType &element)
{
    if (node == nullptr)
        return nullptr;

    if (node->value == element)
        return &node->value;
    if (node->value < element)
        return FindNode(node->right, element);
    if (node->value > element)
        return FindNode(node->left, element);
    return nullptr;
}

BinaryTree1::TreeNode1 *BinaryTree1::RemoveNode(TreeNode1 *node, const ElementType &element)
{
    if (node == nullptr)
    {
        node = nullptr;
    }
    if (node->value < element)
    {
        node->right = RemoveNode(node->right, element);
    }
    else if (node->value > element)
    {
        node->left = RemoveNode(node->left, element);
    }
    else
    {
        if (node->left == nullptr && node->right == nullptr)
        {
            delete node;
            return nullptr;
        }
        else if (node->left != nullptr && node->right != nullptr)
        {
            TreeNode1 *min = GetMinNode(node->right);
            node->value = min->value;
            node->right = RemoveNode(node->right, min->value);
        }
        else
        {
            TreeNode1 *ChildNode = node->left ? node->left : node->right;
            delete node;
            node = ChildNode;
        }
    }
    if (LRDvtion(node) > 1)
    {
        // 左左失衡
        if (LRDvtion(node->left) > 0)
        {
            node = RotateRight(node);
        }
        // 左右
        else
        {
            node = RotateLeftRight(node);
        }
    }
    if (LRDvtion(node) < -1)
    {
        // 右右失衡
        if (LRDvtion(node->right) < 0)
        {
            node = RotateLeft(node);
        }
        // 右左
        else
        {
            node = RotateRightLeft(node);
        }
    }
    return node;
}

BinaryTree1::TreeNode1 *BinaryTree1::GetMinNode(TreeNode1 *node)
{
    TreeNode1 *MinNode = node;
    while (MinNode->left != nullptr)
        MinNode = MinNode->left;
    return MinNode;
}

BinaryTree1::TreeNode1 *BinaryTree1::RotateRight(TreeNode1 *node)
{
    TreeNode1 *t = node->left;
    node->left = t->right;
    t->right = node;
    return t;
}

BinaryTree1::TreeNode1 *BinaryTree1::RotateLeft(TreeNode1 *node)
{
    TreeNode1 *t = node->right;
    node->right = t->left;
    t->left = node;
    return t;
}

BinaryTree1::TreeNode1 *BinaryTree1::RotateLeftRight(TreeNode1 *node)
{
    node->left = RotateLeft(node->left);
    return RotateRight(node);
}

BinaryTree1::TreeNode1 *BinaryTree1::RotateRightLeft(TreeNode1 *node)
{
    node->right = RotateLeft(node->right);
    return RotateLeft(node);
}

BinaryTree1::TreeNode1 *BinaryTree1::CommonAncestor(TreeNode1 *a, TreeNode1 *b)
{
    if (a == nullptr || b == nullptr)
        return nullptr;
    int depthA = 0, depthB = 0;
    TreeNode1 * tempA = a;
    TreeNode1 * tempB = b;
    while(tempA != root && tempA != nullptr)
    {
        tempA = tempA->parent;
        depthA++;
    }
    while(tempB != root && tempB != nullptr)
    {
        tempB = tempB->parent;
        depthB++;
    }
    while(depthA > depthB)
    {
        a=a->parent;
        depthA--;
    }
    while(depthB > depthA)
    {
        b=b->parent;
        depthB--;
    }
    while (a != b)
    {
        a = a->parent;
        b = b->parent;
    }
    return a;
}

BinaryTree1::TreeNode1 *BinaryTree1::FindNodeByValue(const ElementType &element)
{
    return FindNodeByValue(root,element);
}

BinaryTree1::TreeNode1 *BinaryTree1::FindNodeByValue(TreeNode1 *node, const ElementType &element)
{
    if(node == nullptr)
        return nullptr;
    if(element == node->value)
        return node;
    if(element > node->value)
        return FindNodeByValue(node->right,element);
    else
        return FindNodeByValue(node->left,element);
}

ElementType *BinaryTree1::CommonAncestor(const ElementType &a, const ElementType &b)
{
    TreeNode1 * A = FindNodeByValue(a);
    TreeNode1 * B = FindNodeByValue(b);
    TreeNode1 * C = CommonAncestor(A,B);
    if(C != nullptr)
        return &(C->value);

    return nullptr;
}



int BinaryTree1::GetNodeHeight(TreeNode1 *node)
{
    if (node == nullptr)
        return 0;
    int leftHeight = GetNodeHeight(node->left);
    int rightHeight = GetNodeHeight(node->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int BinaryTree1::LRDvtion(TreeNode1 *node)
{
    if (node == nullptr)
        return 0;
    return GetNodeHeight(node->left) - GetNodeHeight(node->right);
}


