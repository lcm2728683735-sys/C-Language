#include "BinaryTree.h"
#include <iostream>

BinaryTree::BinaryTree()
{
    root = nullptr;
}

BinaryTree::~BinaryTree()
{
    FreeNode(root);
}

void BinaryTree::Insert(const ElementType &element)
{
    root = InsertNode(root, element);
}

void BinaryTree::show()
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

ElementType *BinaryTree::FindElement(const ElementType &element)
{
    return FindNode(root, element);
}

void BinaryTree::RemoveByElement(const ElementType &element)
{
    root = RemoveNode(root, element);
}

BinaryTree::TreeNode *BinaryTree::InsertNode(TreeNode *node, const ElementType &element)
{
    // 终止
    if (node == nullptr)
        return new TreeNode(element);
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

void BinaryTree::PrevTravel(TreeNode *node)
{
    if (node == nullptr)
        return;
    std::cout << node->value << " ";
    PrevTravel(node->left);
    PrevTravel(node->right);
}

void BinaryTree::MidTravel(TreeNode *node)
{
    if (node == nullptr)
        return;
    MidTravel(node->left);
    std::cout << node->value << " ";
    MidTravel(node->right);
}

void BinaryTree::PostTravel(TreeNode *node)
{
    if (node == nullptr)
        return;
    PostTravel(node->left);
    PostTravel(node->right);
    std::cout << node->value << " ";
}

void BinaryTree::FreeNode(TreeNode *node)
{
    if (node == nullptr)
        return;
    FreeNode(node->left);
    FreeNode(node->right);
    delete node;
}

ElementType *BinaryTree::FindNode(TreeNode *node, const ElementType &element)
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

BinaryTree::TreeNode *BinaryTree::RemoveNode(TreeNode *node, const ElementType &element)
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
            TreeNode *min = GetMinNode(node->right);
            node->value = min->value;
            node->right = RemoveNode(node->right, min->value);
        }
        else
        {
            TreeNode *ChildNode = node->left ? node->left : node->right;
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
        if (LRDvtion(node->right)< 0 )
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

BinaryTree::TreeNode *BinaryTree::GetMinNode(TreeNode *node)
{
    TreeNode *MinNode = node;
    while (MinNode->left != nullptr)
        MinNode = MinNode->left;
    return MinNode;
}

BinaryTree::TreeNode *BinaryTree::RotateRight(TreeNode *node)
{
    TreeNode *t = node->left;
    node->left = t->right;
    t->right = node;
    return t;
}

BinaryTree::TreeNode *BinaryTree::RotateLeft(TreeNode *node)
{
    TreeNode *t = node->right;
    node->right = t->left;
    t->left = node;
    return t;
}

BinaryTree::TreeNode *BinaryTree::RotateLeftRight(TreeNode *node)
{
    node->left = RotateLeft(node->left);
    return RotateRight(node);
}

BinaryTree::TreeNode *BinaryTree::RotateRightLeft(TreeNode *node)
{
    node->right = RotateLeft(node->right);
    return RotateLeft(node);
}

int BinaryTree::GetNodeHeight(TreeNode *node)
{
    if (node == nullptr)
        return 0;
    int leftHeight = GetNodeHeight(node->left);
    int rightHeight = GetNodeHeight(node->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int BinaryTree::LRDvtion(TreeNode *node)
{
    if (node == nullptr)
        return 0;
    return GetNodeHeight(node->left) - GetNodeHeight(node->right);
}
