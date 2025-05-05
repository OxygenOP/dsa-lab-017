#include <iostream>
using namespace std;

int main()
{
    int num = 10;
    int *ptr = &num;

    cout << "value of num: " << num << endl;

    *ptr = 20;

    cout << "value of num: " << num << endl;
    cout << "Value of ptr: " << *ptr << endl;

    return 0;
}
