#include <iostream>
using namespace std;
int IstOccurence(int arr[], int l, int h, int key)
{
    int ans = -1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (arr[mid] == key)
        {
            ans = mid;
            h = mid - 1;
        }
        else if (arr[mid] > key)
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
}
int findIndexInInfiniteSortedArray(int arr[], int key)
{
    int low = 0;
    int high = 1;
    while (key > arr[high])
    {
        low = high;
        high = high * 2;
    }
    return IstOccurence(arr, low, high, key);
}

int main()
{
    int arr[] = {0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5};
    cout << findIndexInInfiniteSortedArray(arr, 1) << endl;

    return 0;
}