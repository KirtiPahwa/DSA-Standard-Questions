#include <iostream>
using namespace std;
int minDiff(int arr[], int n, int key)
{
    int l = 0;
    int h = n - 1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (arr[mid] == key)
        {

            return mid;
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
    return (abs(l - key) > abs(h - key) ? h : l);
}

int main()
{
    int arr[] = {2, 3, 4, 5, 8, 9, 12};
    cout << minDiff(arr, 7, 7) << endl;

    return 0;
}