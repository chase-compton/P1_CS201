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

    CircularDynamicArray(const CircularDynamicArray &rhs)
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
                newArray[i] = *(array + ((front + i) % cap));
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
            front = (front - 1 + cap) % cap;
            array[front] = value;
            size++;
            newArray = new type[cap];
            for (int i = 0; i < size; i++)
            {
                newArray[i] = *(array + ((front + i) % cap));
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
                newArray[i] = *(array + ((front + i) % cap));
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
                newArray[i] = *(array + ((front + i) % cap));
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
        type *tempArray = new type[size];
        for(int i = 0; i < size; i++)
        {
            tempArray[i] = *(array + ((front + i) % cap));
        }
        mergeSort(tempArray, 0, size - 1);
        delete[] array;
        array = tempArray;
        front = 0;
    }

    void mergeSort(type tempArray[], int begin, int end)
    {
        if (begin >= end)
        {
            return;
        }
        int mid = begin + (end - begin) / 2;
        mergeSort(tempArray, begin, mid);
        mergeSort(tempArray, mid + 1, end);
        merge(tempArray, begin, mid, end);
    }

    void merge(type tempArray[], int left, int mid, int right)
    {
        int subOne = mid - left + 1;
        int subTwo = right - mid;

        type *leftArray = new type[subOne];
        type *rightArray = new type[subTwo];

        for (int i = 0; i < subOne; i++)
        {
            leftArray[i] = tempArray[left + i];
        }
        for (int j = 0; j < subTwo; j++)
        {
            rightArray[j] = tempArray[mid + 1 + j];
        }

        int indexOne = 0, indexTwo = 0;
        int indexMerged = left;

        while (indexOne < subOne && indexTwo < subTwo)
        {
            if (leftArray[indexOne] <= rightArray[indexTwo])
            {
                tempArray[indexMerged] = leftArray[indexOne];
                indexOne++;
            }
            else
            {
                tempArray[indexMerged] = rightArray[indexTwo];
                indexTwo++;
            }
            indexMerged++;
        }
        while (indexOne < subOne)
        {
            tempArray[indexMerged] = leftArray[indexOne];
            indexOne++;
            indexMerged++;
        }
        while (indexTwo < subTwo)
        {
            tempArray[indexMerged] = rightArray[indexTwo];
            indexTwo++;
            indexMerged++;
        }
        delete [] leftArray;
        delete [] rightArray;
    }

    int linearSearch(type e)
    {
        for (int i = 0; i < size; i++)
        {
            if (*(array + ((front + i) % cap)) == e)
            {
                return i;
            }
        }
        return -1;
    }

    int binSearch(type e)
    {
        int left = front;
        int right = (front + size - 1) % cap;
        int mid;

        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (array[mid] == e)
            {
                return mid;
            }
            else if (array[mid] > e)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return -1;
    }
};