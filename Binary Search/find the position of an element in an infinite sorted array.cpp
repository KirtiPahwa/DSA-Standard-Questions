#include <iostream>
using namespace std;
// 1 2 3 5 5 5 9 .......
// TC:-O(log(key))
int binary_search(int arr[], int low, int high, int key)
{
    int l = low;
    int r = high;
    int ans = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == key)
        {
            ans = mid;
            break;
        }
        else if (arr[mid] > key)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}

int searchInInfiniteSortedArray(int arr[], int key)
{
    int low = 0;
    int high = 1;
    while (key > arr[high])
    {
        low = high;
        high = high * 2;
    }
    return binary_search(arr, low, high, key);
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    cout << searchInInfiniteSortedArray(arr, 3) << endl;

    return 0;
}