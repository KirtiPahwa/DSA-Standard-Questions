#include <iostream>
using namespace std;
int first_occurence(int arr[], int n, int key)
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
            r = mid - 1;
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
int last_occurence(int arr[], int n, int key)
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
            l = mid + 1;
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
    int arr[5] = {3, 3, 3, 4, 5};
    cout << first_occurence(arr, 5, 3) << endl;
    cout << last_occurence(arr, 5, 3) << endl;
    return 0;
}