#include <iostream>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void heapify(int arr[], int n, int i)
{
    while (true)
    {
        int left = 2 * i, right = 2 * i + 1;
        if (left >= n)
            break;
        if (right >= n)
        {
            if (arr[left] < arr[i])
                swap(arr[i], arr[left]);
            break;
        }

        if (arr[left] < arr[right])
        {
            if (arr[i] > arr[left])
            {
                swap(arr[i], arr[left]);
                i = left;
            }
            else
                break;
        }
        else
        {
            if (arr[i] > arr[right])
            {
                swap(arr[i], arr[right]);
                i = right;
            }
            else
                break;
        }
    }
}

int main()
{
    int arr[] = {-999999, 10, 8, 11, 4, 2, 1};
    int n = sizeof(arr) / 4;
    print(arr, n);
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
    print(arr, n);
}