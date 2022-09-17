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
    type * array;

public:
    
    CircularDynamicArray()
    {
        size = 0;
        cap = 2;
        front = 0;
        array = new type[cap];
    }

    CircularDynamicArray(int s)
    {
        size = s;
        cap = s;
        front = 0;
        array = new type[cap];
    }

    ~CircularDynamicArray()
    {
        delete [] array;
    }

    type & operator[](int i)
    {
        return *(array + i);
    }

    void addEnd(type value)
    {
        if (size == cap)
        {
            type * newArray;
            cap = cap * 2;
            newArray = new type[cap];
            for(int i = 0; i < size; i++)
            {
                newArray[i] = array[i];
            }
            for(int j = size; j < cap; j++)
            {
                newArray[j] = 0;
            }
            delete [] array;
            array = newArray;
            front = 0;
        }
        array[(front + size) % cap] = value;
        size++;
    }

    void addFront(type value)
    {
        
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
        delete [] array;
        CircularDynamicArray();
    }

};