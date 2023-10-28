#include<iostream>
#include<unordered_map>

int main()
{
    std::ios_base::sync_with_stdio(0); 
    std::cin.tie(NULL); 
    std::cout.tie(NULL);

    int test{};
    std::cin >> test;

    while(test--)
    {
        int n{};
        std::cin >> n;

        int arr[n]{};
        std::unordered_map<int, int> m{};
        for(int i{}; i < n; ++i)
        {
            std::cin >> arr[i];
            m[arr[i]]++;
        }

        std::cout << m[0] << '\n';
    }

    return 0;
}