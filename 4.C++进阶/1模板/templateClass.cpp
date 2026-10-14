#include <iostream>

template <typename T>
class DynamicArray
{
public:
    DynamicArray()
    {
        capacity = 15;
        size = 0;
        array = new T[capacity];
    }

    ~DynamicArray()
    {
    std::cout << "析构函数!\n";
    delete[] array;
    }

    void Insert(const T & element)
    {
        if (size == capacity)
        {
            capacity *= 2;
            T *newP = new T[capacity];
            for (int i = 0; i < size; i++)
                newP[i] = array[i];
            delete[] array;
            array = newP;
        }
        array[size++] = element;
    }

    DynamicArray(const DynamicArray<T> &other)
    {
        capacity = other.capacity;
        size = other.size;
        array = new T[capacity];
        for (int i = 0; i < size; i++)
            array[i] = other.array[i];
    }

    // 赋值运算符
    DynamicArray<T> &operator=(const DynamicArray<T> &a)
    {
        if (this == &a)
            return *this;

        delete[] array;

        capacity = a.capacity;
        size = a.size;
        array = new T[capacity];
        for (int i = 0; i < size; i++)
            array[i] = a.array[i];

        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const DynamicArray<T> &a)
    {
        for (int i = 0; i < a.size; i++)
            os << a.array[i] << " ";
        os << std::endl;
        return os;
    }
private:
    T *array;
    int capacity;
    int size;
};



int main()
{
    DynamicArray<DynamicArray<int>> a;
    // for(int i = 0;i < 20;i++)
    //     a.Insert(i + 1);
    DynamicArray<int> a1;
    for (int i = 0; i < 20; i++)
    {
        a1.Insert(i + 1);
    }

    DynamicArray<int> a2;
    for (int i = 0; i < 20; i++)
    {
        a2.Insert(i + 20);
    }

    a.Insert(a1);
    a.Insert(a2);
    std::cout << "a1: " << a1 << "\n";
    std::cout << "a2: " << a2 << "\n";
    std::cout << "a: " << a << "\n";
    return 0;
}