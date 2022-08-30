#include <iostream>
using namespace std;
int binary_search(int arr[], int n, int key)
{
    int l = 0;
    int r = n - 1;
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

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    cout << binary_search(arr, 5, 3) << endl;
    cout << binary_search(arr, 5, 9) << endl;
    return 0;
}