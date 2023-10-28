#include<iostream>

using namespace std;

int binarySearch(int arr[], int n, int x)
{
    int l{};
    int r{n - 1};

    while(l <= r)
    {
        int mid{l + (r - l) / 2};

        if(arr[mid] == x)
            return 1;

        if(arr[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return -1;
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int n{};
        int x{};
        cin >> n >> x;

        int arr[n]{};
        for(int i{}; i < n; ++i)
            cin >> arr[i];

        cout << binarySearch(arr, n ,x) << '\n';
    }

    return 0;
}