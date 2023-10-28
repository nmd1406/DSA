#include<iostream>
#include<climits>

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

        int minSum = INT_MAX;
        for(int i{0}; i < n - 1; ++i)
        {
            for(int j{i + 1}; j < n; ++j)
            {
                int sum = abs(arr[i] + arr[j]);
                if(sum < abs(minSum))
                {
                    minSum = sum;
                    minSum = arr[i] + arr[j];
                }
            }
        }

        std::cout << minSum << '\n';
    }

    return 0;
}