#include <iostream>
#include "Pointers.h"

using namespace std;

int main()
{
    cout << "Testing MyUniquePtr:" << endl;
    MyUniquePtr<int> uniquePtr(new int(42));
    cout << "Value: " << *uniquePtr << endl;

    uniquePtr.reset(new int(100));
    cout << "Value after reset: " << *uniquePtr << endl;

    int* rawPtr = uniquePtr.release();
    cout << "Value after release: " << *rawPtr << endl;
    delete rawPtr;

    cout << "\nTesting MySharedPtr:" << endl;
    MySharedPtr<int> sharedPtr1(new int(50));
    cout << "Value: " << *sharedPtr1 << ", Use count: " << sharedPtr1.use_count() << endl;

    {
        MySharedPtr<int> sharedPtr2 = sharedPtr1;
        cout << "Value: " << *sharedPtr2 << ", Use count: " << sharedPtr2.use_count() << endl;
    }

    cout << "Use count after scope: " << sharedPtr1.use_count() << endl;

    return 0;
}
