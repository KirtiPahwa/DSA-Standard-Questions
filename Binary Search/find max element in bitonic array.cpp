#include <iostream>
using namespace std;
// 10 20 15 2 23 90 67
int findPeakElement(int arr[], int n)
{
    int l = 0;
    int h = n - 1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if ((mid == 0 || arr[mid - 1] < arr[mid]) && (arr[mid + 1] < arr[mid] || mid == n - 1))
        {
            return mid;
        }
        else if (arr[mid + 1] > arr[mid] && mid < n - 1)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {10, 20, 15, 2, 23, 90, 67};
    cout << findPeakElement(arr, 7) << endl;

    return 0;
}