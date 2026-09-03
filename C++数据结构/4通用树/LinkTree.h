#ifndef __LINKTREE_H__
#define __LINKTREE_H__
#include <string>
#include "DynamicArray.h"
using ElementType = std::string;
class TreeNode
{
public:
    TreeNode(const ElementType & element);
    //绑定
    void Connect(TreeNode *parent);
    //解绑
    void Disconnect(TreeNode* parent);
    static void FreeNode(TreeNode * node);
    static TreeNode * FindNode(TreeNode *node,const ElementType & element);
    static void FindNode(TreeNode *node,const ElementType & element,DARRAY::DynamicArray & a);
    void show(TreeNode * node,int depth);
    static int GetTreeHeight(TreeNode * node);
    TreeNode * GetParent();
    std::string & GetData();
    void SetData(const ElementType& element);
private:
    ElementType data;        //数据域
    TreeNode *parent;        //双亲节点
    TreeNode *FirstChild;    //第一个孩子节点
    TreeNode *nextSbling;    //下一个兄弟节点
};

class LinkTree
{
public:
    LinkTree();
    LinkTree(const ElementType& element);
    ~LinkTree();
    TreeNode * GetRoot();
    void show();
    DARRAY::DynamicArray FindByElement(const ElementType & element);
    int GetTreeHeight();
    std::string GetNodePath(TreeNode * node);

private:
    TreeNode *root;
};


#endif