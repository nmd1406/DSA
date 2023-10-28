#include<iostream>
#include<algorithm>

int main()
{
    int test{};
    std::cin >> test;
    while(test--)
    {
        int n{};
        int x{};
        std::cin >> n >> x;
        int arr[n]{};
        for(int i{}; i < n; ++i)
            std::cin >> arr[i];

        std::stable_sort(arr, arr + n, [=](const int a, const int b)
                                        {
                                            return std::abs(x - a) < std::abs(x - b);
                                        });

        for(int i{}; i < n; ++i)
            std::cout << arr[i] << ' ';

        std::cout << '\n';
    }

    return 0;
}