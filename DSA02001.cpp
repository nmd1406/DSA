#include<iostream>

void backTracking(int arr[], int n)
{
    if(n)
    {
        std::cout << '[';
        for(int i{}; i < n - 1; ++i)
            std::cout << arr[i] << ' ';
        std::cout << arr[n - 1] << ']';

        for(int i{}; i < n - 1; ++i)
            arr[i] = arr[i] + arr[i + 1];

        std::cout << '\n';
        backTracking(arr, n - 1);
    }
}

int main()
{
    int test{};
    std::cin >> test;

    while(test--)
    {
        int n{};
        std::cin >> n;
        int arr[n]{};
        for(int i{}; i < n; ++i)
            std::cin >> arr[i];

        backTracking(arr, n);
    }

    return 0;
}