#ifndef __DYNAMICARRAY_H_
#define __DYNAMICARRAY_H_
 

using ElementType = int;
class DynamicArray
{
public: 
    DynamicArray(int capacity = 10);   
    DynamicArray(const DynamicArray & a);
    void operator = (const DynamicArray& a);
    ~DynamicArray();

    void InsertTail(const ElementType& element);
    void show();
private:

    ElementType *array;
    int size;
    int capacity;
};
#endif
