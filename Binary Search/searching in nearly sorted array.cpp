#include <iostream>
using namespace std;
int modified_binary_search(int arr[], int n, int key)
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
        if (mid - 1 >= l && arr[mid - 1] == key)
        {
            ans = mid - 1;
            break;
        }
        if (mid + 1 <= r && arr[mid + 1] == key)
        {
            ans = mid + 1;
            break;
        }
        else if (arr[mid] > key)
        {
            r = mid - 2;
        }
        else
        {
            l = mid + 2;
        }
    }
    return ans;
}
int main()
{
    int arr[5] = {2, 1, 9, 8, 34};
    cout << modified_binary_search(arr, 5, 2) << endl;

    return 0;
}