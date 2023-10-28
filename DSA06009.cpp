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
        int arr[n]{};
        for(int i{}; i < n; ++i)
            std::cin >> arr[i];

        int count{};
        std::unordered_map<int, int> m{};
        for(int i{}; i < n; ++i)
        {
            auto itr{m.find(k - arr[i])};
            if(itr != m.end())
                count += m[k - arr[i]];

            m[arr[i]]++;
        }

        std::cout << count << '\n';
    }
}