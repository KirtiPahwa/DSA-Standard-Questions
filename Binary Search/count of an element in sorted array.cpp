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
int count_element(int arr[], int n, int key)
{
    return last_occurence(arr, n, key) - first_occurence(arr, n, key) + 1;
}

int main()
{
    int arr[5] = {3, 3, 3, 3, 5};
    cout << count_element(arr, 5, 3) << endl;

    return 0;
}