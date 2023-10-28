#include<iostream>
#include<algorithm>


int binarySearch(int arr[], int n, int k)
{
    int l{};
    int r{n - 1};

    while(l <= r)
    {
        int mid{l + (r - l) / 2};
        if(arr[mid] == k)
            return mid + 1;

        if(arr[mid] < k)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return -1;
}

int main()
{
    int testCase{};
    std::cin >> testCase;

    while(testCase--)
    {
        int n{};
        int k{};
        std::cin >> n >> k;

        int arr[n]{};
        for(int i{}; i < n; ++i)
            std::cin >> arr[i];

        int index{binarySearch(arr, n, k)};
        if(index != -1)
            std::cout << index << '\n';
        else
            std::cout << "NO\n";
    }

    return 0;
}