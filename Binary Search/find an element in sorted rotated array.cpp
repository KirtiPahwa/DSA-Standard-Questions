#include <iostream>
using namespace std;

int binary_search(int arr[], int l, int r, int key)
{
    int ans = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] == key)
        {
            ans = mid;
            break;
        }
        else if (arr[mid] < key)
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

int search(int arr[], int n, int key)
{
    int l = 0;
    int r = n - 1;
    int ans = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] < arr[(mid - 1 + n) % n] && arr[mid] < arr[mid + 1] % n)
        {
            ans = mid;
            break;
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
    int s1 = binary_search(arr, 0, ans - 1, key);
    int s2 = binary_search(arr, ans, n - 1, key);
    if (s1 == -1 && s2 == -1)
    {
        return -1;
    }
    else if (s1 == -1)
    {
        return s2;
    }
    else
    {
        return s1;
    }
}
int main()
{
    int arr[8] = {11, 12, 13, 15, 18, 2, 3, 4};

    std::cout << search(arr, 8, 9) << endl;
    return 0;
}