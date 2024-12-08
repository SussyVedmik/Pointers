#include <cstring>
using namespace std;

template <typename T>
class MyUniquePtr
{
private:
    T* ptr;

public:
    explicit MyUniquePtr(T* p = nullptr);
    ~MyUniquePtr();

    MyUniquePtr(const MyUniquePtr&) = delete;
    MyUniquePtr& operator=(const MyUniquePtr&) = delete;

    MyUniquePtr(MyUniquePtr&& other) noexcept;
    MyUniquePtr& operator=(MyUniquePtr&& other) noexcept;

    T& operator*() const;
    T* operator->() const;
    T* get() const;
    T* release();
    void reset(T* p = nullptr);
};

template <typename T>
class MySharedPtr
{
private:
    T* ptr;
    int* ref_count;

public:
    explicit MySharedPtr(T* p = nullptr);
    MySharedPtr(const MySharedPtr& other);
    MySharedPtr& operator=(const MySharedPtr& other);
    ~MySharedPtr();

    T& operator*() const;
    T* operator->() const;
    T* get() const;
    int use_count() const;

private:
    void release();
};

