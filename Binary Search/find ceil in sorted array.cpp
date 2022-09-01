#include <iostream>
using namespace std;
int binary_search(int arr[], int n, int key)
{
    int l = 0;
    int r = n - 1;
    int ans = 0;
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
            ans = mid;

            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return arr[ans];
}

int main()
{
    int arr[5] = {1, 2, 8, 9, 34};
    cout << binary_search(arr, 5, 7) << endl;
    return 0;
}