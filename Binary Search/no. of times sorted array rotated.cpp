#include <iostream>
using namespace std;
int count(int arr[], int n)
{
    int l = 0;
    int r = n - 1;
    int ans = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] < arr[(mid - 1 + n) % n] && arr[mid] < arr[mid + 1] % n)
        {
            return n - mid;
        }

        else if (arr[mid] > arr[r])
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return ans;
}
int main()
{
    int arr[8] = {11, 12, 13, 14, 18, 19, 20, 21};
    cout << count(arr, 8) << endl;
    return 0;
}