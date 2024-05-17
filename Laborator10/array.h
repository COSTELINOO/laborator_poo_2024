#pragma once
#include <iostream>
#include <exception>
using namespace std;
class Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};

class OutOfRangeException : public exception
{
public:
    virtual const char* what() const throw()
    {
        return "Indexul este în afara domeniului!";
    }
};

class AllocationFailureException : public exception
{
public:
    virtual const char* what() const throw()
    {
        return "Eșec la alocarea memoriei!";
    }
};


template<class T>
class ArrayIterator
{
private:
    int Current;
    T** List;
    int Size;
public:
    ArrayIterator() : Current(0), List(nullptr), Size(0) {}
    ArrayIterator(T** list, int size) : Current(0), List(list), Size(size) {}
    ArrayIterator(T** list, int size, int poz) : Current(poz), List(list), Size(size) {}

    ArrayIterator& operator++() { ++Current; return *this; }
    ArrayIterator& operator--() { --Current; return *this; }

    bool operator==(ArrayIterator<T>& other) { return Current == other.Current && List == other.List; }
    bool operator!=(const ArrayIterator<T>& other) const { return Current != other.Current || List != other.List; }

    T* GetElement() { return (Current < Size && Current >= 0) ? List[Current] : nullptr; }
};

template<class T>
class Array
{
private:
    T** List;
    int Capacity;
    int Size;

public:
    Array() : List(nullptr), Capacity(0), Size(0) {}

    Array(int capacity) : Capacity(capacity), Size(0)
    {
        List = new (nothrow) T * [Capacity];
        if (!List)
            throw AllocationFailureException();
    }

    Array(const Array<T>& other) : Capacity(other.Capacity), Size(other.Size)
    {
        List = new (nothrow) T * [Capacity];
        if (!List)
            throw AllocationFailureException();
        for (int i = 0; i < Size; ++i)
            List[i] = new T(*other.List[i]);
    }

    ~Array()
    {
        for (int i = 0; i < Size; ++i)
            delete List[i];
        delete[] List;
    }

    T& operator[] (int index)
    {
        if (index < 0 || index >= Size)
            throw OutOfRangeException();
        return *List[index];
    }

    const Array<T>& operator+=(const T& newElem)
    {
        if (Size >= Capacity)
        {
            Capacity = Capacity ? Capacity * 2 : 1;
            T** newList = new (nothrow) T * [Capacity];
            if (!newList)
                throw AllocationFailureException();
            for (int i = 0; i < Size; ++i)
                newList[i] = List[i];
            delete[] List;
            List = newList;
        }
        List[Size++] = new T(newElem);
        return *this;
    }

    const Array<T>& Insert(int index, const T& newElem)
    {
        if (index < 0 || index > Size)
            throw OutOfRangeException();
        if (Size >= Capacity)
        {
            Capacity = Capacity ? Capacity * 2 : 1;
            T** newList = new (nothrow) T * [Capacity];
            if (!newList)
                throw AllocationFailureException();
            for (int i = 0; i < Size; ++i)
                newList[i] = List[i];
            delete[] List;
            List = newList;
        }
        for (int i = Size; i > index; --i)
            List[i] = List[i - 1];
        List[index] = new T(newElem);
        ++Size;
        return *this;
    }

    const Array<T>& Insert(int index, const Array<T> otherArray)
    {
        if (index < 0 || index > Size)
            throw OutOfRangeException();
        while (Size + otherArray.Size > Capacity)
        {
            Capacity = Capacity ? Capacity * 2 : 1;
            T** newList = new (nothrow) T * [Capacity];
            if (!newList)
                throw AllocationFailureException();
            for (int i = 0; i < Size; ++i)
                newList[i] = List[i];
            delete[] List;
            List = newList;
        }
        for (int i = Size - 1; i >= index; --i)
            List[i + otherArray.Size] = List[i];
        for (int i = 0; i < otherArray.Size; ++i)
            List[index + i] = new T(*otherArray.List[i]);
        Size += otherArray.Size;
        return *this;
    }

    const Array<T>& Delete(int index)
    {
        if (index < 0 || index >= Size)
            throw OutOfRangeException();
        delete List[index];
        for (int i = index; i < Size - 1; ++i)
            List[i] = List[i + 1];
        --Size;
        return *this;
    }

    bool operator=(const Array<T>& other)
    {
        if (this == &other)
            return true;
        for (int i = 0; i < Size; ++i)
            delete List[i];
        delete[] List;
        Capacity = other.Capacity;
        Size = other.Size;
        List = new (nothrow) T * [Capacity];
        if (!List)
            throw AllocationFailureException();
        for (int i = 0; i < Size; ++i)
            List[i] = new T(*other.List[i]);
        return true;
    }

    void Sort()
    {
        for (int i = 0; i < Size - 1; ++i)
        {
            for (int j = i + 1; j < Size; ++j)
            {
                if (*List[i] > *List[j])
                {
                    T* temp = List[i];
                    List[i] = List[j];
                    List[j] = temp;
                }
            }
        }
    }

    void Sort(int(*compare)(const T&, const T&))
    {
        for (int i = 0; i < Size - 1; ++i)
        {
            for (int j = i + 1; j < Size; ++j)
            {
                if (compare(*List[i], *List[j]) > 0)
                {
                    T* temp = List[i];
                    List[i] = List[j];
                    List[j] = temp;
                }
            }
        }
    }

    void Sort(Compare* comparator)
    {
        for (int i = 0; i < Size - 1; ++i)
        {
            for (int j = i + 1; j < Size; ++j)
            {
                if (comparator->CompareElements(List[i], List[j]) > 0)
                {
                    T* temp = List[i];
                    List[i] = List[j];
                    List[j] = temp;
                }
            }
        }
    }

    
    int BinarySearch(const T& elem)
    {
        int st = 0, dr = Size - 1;
        while (st <= dr)
        {
            int mij = st + (dr - st) / 2;
            if (*List[mij] == elem)
                return mij;
            if (*List[mij] < elem)
                st = mij + 1;
            else
                dr = mij - 1;
        }
        return -1;
    }

    int BinarySearch(const T& elem, int(*compare)(const T&, const T&))
    {
        int st = 0, dr = Size - 1;
        while (st <= dr)
        {
            int mij = st + (dr - st) / 2;
            if (compare(*List[mij], elem) == 0)
                return mij;
            if (compare(*List[mij], elem) < 0)
                st = mij + 1;
            else
                dr = mij - 1;
        }
        return -1;
    }

    int BinarySearch(const T& elem, Compare* comparator)
    {
        int st = 0, dr = Size - 1;
        while (st <= dr)
        {
            int mij = st + (dr - st) / 2;
            if (comparator->CompareElements(List[mij], (void*)&elem) == 0)
                return mij;
            if (comparator->CompareElements(List[mij], (void*)&elem) < 0)
                st = mij + 1;
            else
                dr = mij - 1;
        }
        return -1;
    }

    
    int Find(const T& elem)
    {
        for (int i = 0; i < Size; ++i)
        {
            if (*List[i] == elem)
                return i;
        }
        return -1;
    }

    int Find(const T& elem, int(*compare)(const T&, const T&))
    {
        for (int i = 0; i < Size; ++i)
        {
            if (compare(*List[i], elem) == 0)
                return i;
        }
        return -1;
    }

    int Find(const T& elem, Compare* comparator)
    {
        for (int i = 0; i < Size; ++i)
        {
            if (comparator->CompareElements(List[i], (void*)&elem) == 0)
                return i;
        }
        return -1;
    }

    int GetSize() { return Size; }
    int GetCapacity() { return Capacity; }

    ArrayIterator<T> GetBeginIterator() { return ArrayIterator<T>(List, Size); }
    ArrayIterator<T> GetEndIterator() { return ArrayIterator<T>(List , Size, Size); }

    
};

