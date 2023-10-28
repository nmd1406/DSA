#include<iostream>
#include<algorithm>

int main()
{
    int testCase{};
    std::cin >> testCase;

    while(testCase--)
    {
        int n{};
        std::cin >> n;
        int arr[n];

        for(int i{}; i < n; ++i)
            std::cin >> arr[i];

        std::sort(arr, arr + n);
        int l{};
        int r{n - 1};

        while(l <= r)
        {
            if(l == r)
                std::cout << arr[l] << ' ';
            else
                std::cout << arr[r] << ' ' << arr[l] << ' ';

            ++l;
            --r;
        }

        std::cout << '\n';
    }

    return 0;
}