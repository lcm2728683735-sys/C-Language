#include "HashMap.h"
#include <iostream>

HashMap::HashMap(int Size):size(Size)
{
    array = new Node *[Size];
    for (int i=0;i<size;i++)
    {
        array[i] = nullptr;
    }
}

HashMap::~HashMap()
{
    for(int i = 0;i < size ; i++)
    {
        Node* travelPoint = array[i];
        while(travelPoint != nullptr)
        {
            Node* temp = travelPoint->next;
            delete travelPoint;
            travelPoint= temp;
        }
    }
    delete[] array;
}

void HashMap::Insert(const std::string &key, const ElementType &element)
{
    Node* node = new Node(key,element);
    //计算哈希值
    int index = Hash(key);
        node->next = array[index];
        array[index] = node;
}

void HashMap::show()
{
    for(int i = 0; i< size ;i++)
    {
        Node* travelPoint = array[i];
        while(travelPoint != nullptr)
        {
            std::cout <<"hash值:"<<Hash(travelPoint->key)<<" "
                      <<"key :"<<travelPoint->key<< " "
                      <<"value :"<<travelPoint->value<< " "<<std::endl;
            travelPoint = travelPoint->next;
        }
    }
}

void HashMap::showByGroup()
{
    for(int i = 0; i< size ;i++)
    {
        Node* travelPoint = array[i];
        if(travelPoint == nullptr)
            continue;
        while(travelPoint != nullptr)
        {
            std::cout <<travelPoint->value<< " ";
            travelPoint = travelPoint->next;
        }
        std::cout<<std::endl;
    }
}

ElementType *HashMap::Get(const std::string &key)
{
    Node* node = array[Hash(key)];
    while(node!=nullptr)
    {
        if(node->key == key)
            return &node->value;
        node = node->next;
    }
    return nullptr;
}

ElementType &HashMap::operator[](const std::string &key)
{
    ElementType* data =Get(key);
    if(data)
        return *data; 
    else
    {
        Insert(key,"");
        return *Get(key);
    }
}

void HashMap::Remove(const std::string &key)
{
    Node * node = array[Hash(key)];
    if(node == nullptr)
        return;
    if(node->key == key)
    {
        array[Hash(key)] = node->next;
        delete node;
        return;
    }
    while(node != nullptr)
    {
        if(node->next->key == key)
        {
            Node* freeNode = node->next;
            node->next = freeNode->next;
            delete freeNode;
            return;
        }
        node = node->next; 
    }
}

int HashMap::Hash(const std::string &key)
{
    int hash = 0;
    for(int i = 0;i < key.size(); i++)
    {
        hash = (hash * 31 + key[i]) % size;
    }
    return hash;
}