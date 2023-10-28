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

        int arr1[n]{};
        int arr2[n]{};

        for(int i{}; i < n; ++i)
        {
            std::cin >> arr1[i];
            arr2[i] = arr1[i];
        }

        std::sort(arr1, arr1 + n);

        for(int i{}; i < n; ++i)
        {
            if(arr1[i] != arr2[i])
            {
                std::cout << i + 1 << ' ';
                break;
            }
        }

        for(int i{n - 1}; i >= 0; --i)
        {
            if(arr1[i] != arr2[i])
            {
                std::cout << i + 1 << ' ';
                break;
            }
        }

        std::cout << '\n';
    }

    return 0;
}