#include <iostream>
using namespace std;

int findMax(int arr[], int n)
{
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int main()
{
    const int n = 6;
    int arr[6] = {5, 12, 3, 9, 20, 7};

    int maxValue = findMax(arr, n);
    cout << "Maximum value in the array: " << maxValue << endl;
    // time complexity is O(n) because it runs once for each value in the array as in it runs n number of times
    return 0;
}
