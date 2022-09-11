#include <iostream>
using namespace std;
// TC:- O(m+n) where m=no, of rows and n=no. of columns
pair<int, int> binary_search(int arr[3][3], int key)
{
    int n = 3;
    int i = 0;
    int j = 2;
    while (i >= 0 && i < n && j >= 0 && j < n)
    {
        if (arr[i][j] == key)
        {
            return {i, j};
        }
        else if (arr[i][j] < key)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return {-1, -1};
}

int main()
{
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << binary_search(arr, 5).first << " " << binary_search(arr, 5).second << endl;

    return 0;
}