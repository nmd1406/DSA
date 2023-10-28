#include<iostream>

int main()
{
    int n{};
    std::cin >> n;
    int arr[n];

    for(int i{}; i < n; ++i)
        std::cin >> arr[i];

    int k{};
    std::cin >> k;

    for(int i{}; i < n; ++i)
    {
        if(arr[i] != k)
            std::cout << arr[i] << ' ';
    }

    return 0;
}