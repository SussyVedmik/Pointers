#include "Pointers.h"
#include <iostream>

template <typename T>
MyUniquePtr<T>::MyUniquePtr(T* p) : ptr(p) {}

template <typename T>
MyUniquePtr<T>::~MyUniquePtr()
{
    delete ptr;
}

template <typename T>
MyUniquePtr<T>::MyUniquePtr(MyUniquePtr&& other) noexcept : ptr(other.ptr)
{
    other.ptr = nullptr;
}

template <typename T>
MyUniquePtr<T>& MyUniquePtr<T>::operator=(MyUniquePtr&& other) noexcept
{
    if (this != &other)
    {
        delete ptr;
        ptr = other.ptr;
        other.ptr = nullptr;
    }
    return *this;
}

template <typename T>
T& MyUniquePtr<T>::operator*() const
{
    return *ptr;
}

template <typename T>
T* MyUniquePtr<T>::operator->() const
{
    return ptr;
}

template <typename T>
T* MyUniquePtr<T>::get() const
{
    return ptr;
}

template <typename T>
T* MyUniquePtr<T>::release()
{
    T* temp = ptr;
    ptr = nullptr;
    return temp;
}

template <typename T>
void MyUniquePtr<T>::reset(T* p)
{
    delete ptr;
    ptr = p;
}

template <typename T>
MySharedPtr<T>::MySharedPtr(T* p) : ptr(p), ref_count(new int(1)) {}

template <typename T>
MySharedPtr<T>::MySharedPtr(const MySharedPtr& other) : ptr(other.ptr), ref_count(other.ref_count)
{
    (*ref_count)++;
}

template <typename T>
MySharedPtr<T>& MySharedPtr<T>::operator=(const MySharedPtr& other)
{
    if (this != &other)
    {
        release();
        ptr = other.ptr;
        ref_count = other.ref_count;
        (*ref_count)++;
    }
    return *this;
}

template <typename T>
MySharedPtr<T>::~MySharedPtr()
{
    release();
}

template <typename T>
T& MySharedPtr<T>::operator*() const
{
    return *ptr;
}

template <typename T>
T* MySharedPtr<T>::operator->() const
{
    return ptr;
}

template <typename T>
T* MySharedPtr<T>::get() const
{
    return ptr;
}

template <typename T>
int MySharedPtr<T>::use_count() const
{
    return *ref_count;
}

template <typename T>
void MySharedPtr<T>::release()
{
    if (--(*ref_count) == 0)
    {
        delete ptr;
        delete ref_count;
    }
}
