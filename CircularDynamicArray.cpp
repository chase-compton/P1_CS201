#include <iostream>
#include <cstdlib>

using namespace std;

template <class type>
class CircularDynamicArray
{
protected:
    int size;
    int cap;
    int front;
    type *array;

public:
    CircularDynamicArray()
    {
        size = 0;
        cap = 2;
        array = new type[cap];
        front = 0;
    }

    CircularDynamicArray(int s)
    {
        size = s;
        cap = s;
        array = new type[cap];
        front = 0;
    }

    CircularDynamicArray(const CircularDynamicArray& rhs)
    {
        size = rhs.size;
        cap = rhs.cap;
        array = rhs.array;
        front = rhs.front;
    }

    ~CircularDynamicArray()
    {
        delete[] array;
    }

    type &operator[](int i)
    {
        return *(array + ((front + i) % cap));
    }

    void addEnd(type value)
    {
        if (size == cap)
        {
            type *newArray;
            cap = cap * 2;
            newArray = new type[cap];
            for (int i = 0; i < size; i++)
            {
                newArray[i] = array[i];
            }
            for (int j = size; j < cap; j++)
            {
                newArray[j] = 0;
            }
            delete[] array;
            array = newArray;
            front = 0;
        }
        array[(front + size) % cap] = value;
        size++;
    }

    void addFront(type value)
    {
        if (size == cap)
        {
            type *newArray;
            cap = cap * 2;
            size++;
            newArray = new type[cap];
            newArray[0] = value;
            for (int i = 1; i < size; i++)
            {
                newArray[i] = array[i - 1];
            }
            for (int j = size; j < cap; j++)
            {
                newArray[j] = 0;
            }
            delete[] array;
            array = newArray;
            front = 0;
        }
        else
        {
            front = (front - 1 + cap) % cap;
            array[front] = value;
            size++;
        }
    }

    void delEnd()
    {
        size--;
        if (size <= cap / 4)
        {
            type *newArray;
            cap = cap / 2;
            newArray = new type[cap];
            for (int i = 0; i < size; i++)
            {
                newArray[i] = array[i];
            }
            for (int j = size; j < cap; j++)
            {
                newArray[j] = 0;
            }
            delete[] array;
            array = newArray;
            front = 0;
        }
    }

    void delFront()
    {
        size--;
        front = (front + 1 + cap) % cap;
        if (size <= cap / 4)
        {
            type *newArray;
            cap = cap / 2;
            newArray = new type[cap];
            for (int i = 0; i < size; i++)
            {
                newArray[i] = array[i];
            }
            for (int j = size; j < cap; j++)
            {
                newArray[j] = 0;
            }
            delete[] array;
            array = newArray;
            front = 0;
        }
    }

    int length()
    {
        return size;
    }

    int capacity()
    {
        return cap;
    }

    void clear()
    {
        delete[] array;
        CircularDynamicArray();
    }

    type QuickSelect(int k)
    {

    }

    type WCSelect(int k)
    {

    }

    void stableSort()
    {

    }

    int linearSearch(type e)
    {
        for (int i = 0; i < size; i++)
        {
            if (*(array + ((front + i) % cap)) == e)
            {
                return  i;
            }
        }
        return -1;
    }

    int binSearch(type e)
    {
        return -1;
    }
};