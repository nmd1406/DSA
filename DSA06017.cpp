#include<iostream>
#include<algorithm>

int main()
{
    std::ios_base::sync_with_stdio(0); 
    std::cin.tie(NULL); 
    std::cout.tie(NULL);

    int test{};
    std::cin >> test;

    while (test--)
    {
        int n{};
        int m{};
        std::cin >> n >> m;

        int arr[n + m]{};
        for(int i{}; i < n + m; ++i)
            std::cin >> arr[i];

        std::sort(arr, arr + n + m);

        for(int i{}; i < n + m; ++i)
            std::cout << arr[i] << ' ';

        std::cout << '\n';
    }
    

    return 0;
}