
bool IsSameTree(TreeNode* node1, TreeNode* node2)
{
    // 两个节点都为空
    if (node1 == nullptr && node2 == nullptr)
        return true;

    // 一个为空，一个不为空
    if (node1 == nullptr || node2 == nullptr)
        return false;

    // 当前节点值不同
    if (node1->data != node2->data)
        return false;

    // 当前节点相同，继续比较左右子树
    return IsSameTree(node1->left, node2->left);
    return IsSameTree(node1->right, node2->right);
}
