#include "LinkTree.h"
#include <iostream>
#include "DynamicArray.h"
TreeNode::TreeNode(const ElementType & element):data(element)
{
    parent = FirstChild = nextSbling = nullptr;
} 

void TreeNode::Connect(TreeNode *parent)
{
    if(!parent )
        return;
    this->parent = parent;
    this->nextSbling = parent->FirstChild;
    parent->FirstChild = this;
}

void TreeNode::Disconnect(TreeNode *parent)
{
    if(parent == nullptr || this->parent != parent)
        return;
    TreeNode * travelPoint = parent->FirstChild;
    if(this == parent->FirstChild)
    {
        parent->FirstChild= this->nextSbling;
    } 
    else
    {
        while(travelPoint->nextSbling != nullptr)
        {
            if(travelPoint->nextSbling == this)
            {
                travelPoint->nextSbling = this->nextSbling;
                break;
            }
            travelPoint = travelPoint->nextSbling;
        }
    }
    parent = nextSbling = nullptr;
}

void TreeNode::FreeNode(TreeNode *node)
{
    if(node ==nullptr)
        return;
    FreeNode(node->FirstChild);
    FreeNode(node->nextSbling);
    delete node;
}


void TreeNode::show(TreeNode *node,int depth)
{
    //终止条件
    if(node == nullptr)
        return;
    for(int i = 0; i < depth;i++)
        std::cout<<" ";
    //排除根节点打印
    if(node->parent != nullptr)
        std::cout<<node->data<<std::endl;
    //深度优点遍历
    show(node->FirstChild,depth+1);
    show(node->nextSbling,depth);
    
}

int TreeNode::GetTreeHeight(TreeNode *node)
{
    if(node == nullptr)
        return 0;
    int MaxHeight =0;
    TreeNode *travelPoint = node->FirstChild;
    while(travelPoint != nullptr)
    {
        int height = GetTreeHeight(travelPoint);
        MaxHeight = MaxHeight > height ? MaxHeight : height;
        travelPoint = travelPoint->nextSbling;
    }
    return MaxHeight + 1;
}

TreeNode *TreeNode::GetParent()
{
    return parent;
}


std::string &TreeNode::GetData()
{
    return data;
}

void TreeNode::SetData(const ElementType &element)
{
    data = element;
}

LinkTree::LinkTree()
{
    root = new TreeNode("");
}

LinkTree::LinkTree(const ElementType &element)
{
    root = new TreeNode(element);
}

LinkTree::~LinkTree()
{
    TreeNode::FreeNode(root);
}

TreeNode *LinkTree::GetRoot()
{
    return root;
}

void LinkTree::show()
{
    root ->show(root,-1);
}

TreeNode *TreeNode::FindNode(TreeNode *node, const ElementType &element)
{
    if(node == nullptr)
        return nullptr;
    
    if(node->data == element && node->parent!=nullptr)
        return node;

    TreeNode * target = FindNode(node->FirstChild,element);
    if(target)
        return target;
    target = FindNode(node->nextSbling,element);
    if(target)
        return target;
    return nullptr;
     
}

void TreeNode::FindNode(TreeNode *node, const ElementType &element, DARRAY::DynamicArray &a)
{
    if(node == nullptr)
        return;
    
    if(node->data == element && node->parent!=nullptr)
    {
        a.InsertTail(node);
    }
    FindNode(node->FirstChild,element,a);
    FindNode(node->nextSbling,element,a);
}

DARRAY::DynamicArray LinkTree::FindByElement(const ElementType & element)
{
    DARRAY::DynamicArray a;
    TreeNode::FindNode(root,element,a);
    return a;
}

int LinkTree::GetTreeHeight()
{
    return TreeNode::GetTreeHeight(root)-1;
}

std::string LinkTree::GetNodePath(TreeNode *node)
{
    if(node == nullptr)
        return std::string();
    
    std::string path = node->GetData();
    while(node->GetParent() != nullptr)
    {
        path = node->GetParent()->GetData()+ "/" + path;
        node = node->GetParent();
    }
    return path;
}
