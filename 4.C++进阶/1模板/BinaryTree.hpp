#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__
#include <string>
template<typename T1, typename T2>
struct Pair
{
    T1 key;
    T2 value;
};

template <typename T>
struct HashPair : public Pair<std::string, T>//模板的偏特化：部分模板明确类型
{ };

// template <>
// struct HashPair : public Pair<std::string, int>模板的全特化
// { };

template<typename T1,typename T2>
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
    TreeNode* root;
};

template<typename T1,typename T2>
class MyMap: public BinaryTree<Pair<T1,T2>>
{

};

#endif