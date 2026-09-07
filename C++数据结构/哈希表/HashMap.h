#ifndef __HASHMAP_H__
#define __HASHMAP_H__
#include <string>
using ElementType = std::string;
const int Size = 10; 
class HashMap
{
public:
    HashMap(int Size);
    ~HashMap();
    void Insert(const std::string& key,const ElementType&element);
    void show();
    void showByGroup();
    ElementType* Get(const std::string& key) ;
    ElementType& operator[](const std::string & key);

    void Remove(const std::string& key);
private:
    struct Node//节点
    {
        Node(const std::string& key, const ElementType& element)
        {
            this->key = key;
            this->value = element;
        } 
        std::string key;//键
        ElementType value;//值
        Node* next;//链表中指向下一个节点的指针
    };
    Node**array;
    const int size;
    //哈希函数：将字符串转成int的方法
    int Hash(const std::string& key);
};

#endif