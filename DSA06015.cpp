#include<iostream>
#include<algorithm>

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

        std::sort(arr, arr + n);
        for(int i{}; i < n; ++i)
            std::cout << arr[i] << ' ';

        std::cout << '\n';
    }

    return 0;
}