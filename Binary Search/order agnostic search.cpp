//  here we don't know that array is in ascending or descending order
#include <iostream>
using namespace std;
int binary_search(int arr[], int n, int key)
{
    int l = 0;
    int r = n - 1;
    int ans = -1;
    bool asc;
    if (arr[0] < arr[1])
    {
        asc = 1;
    }
    else
    {
        asc = 0;
    }
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
            if (asc == 1)
                r = mid - 1;
            else
                l = mid + 1;
        }
        else
        {
            if (asc == 1)
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int arr1[5] = {5, 4, 3, 2, 1};

    cout << binary_search(arr, 5, 3) << endl;
    cout << binary_search(arr1, 5, 1) << endl;
    return 0;
}