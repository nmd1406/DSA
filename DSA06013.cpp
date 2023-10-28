#include<iostream>
#include<unordered_map>

int main()
{
    int test{};
    std::cin >> test;

    while(test--)
    {
        int n{};
        int k{};
        std::cin >> n >> k;

        std::unordered_map<int, int> m{};
        for(int i{}; i < n; ++i)
        {
            int temp{};
            std::cin >> temp;
            m[temp]++;
        }

        if(m[k])
            std::cout << m[k] << '\n';
        else
            std::cout << -1 << '\n';
    }

    return 0;
}