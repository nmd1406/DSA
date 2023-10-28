#include<iostream>

using namespace std;

int binarySearch(long long arr[], int n, long long x)
{
    int l{};
    int r{n - 1};
    int pos{-1};

    while(l <= r)
    {
        int mid{l + (r - l) / 2};
        if(arr[mid] <= x)
        {
            l = mid + 1;
            pos = mid + 1;
        }
        else
            r = mid - 1;
    }

    return pos;
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int n{};
        long long x{};
        cin >> n >> x;

        long long* arr{new long long[n]{}};
        for(int i{}; i < n; ++i)
            cin >> arr[i];

        int pos{binarySearch(arr, n, x)};
        cout << pos << '\n';
    }

    return 0;
}