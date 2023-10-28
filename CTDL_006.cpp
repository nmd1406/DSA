#include<iostream>
#include<vector>
#include<unordered_map>

int main()
{
    int n{};
    std::cin >> n;

    int arr[n]{};
    for(int i{}; i < n; ++i)
        std::cin >> arr[i];

    std::vector<int> v{};
    std::unordered_map<int, bool> m{};

    for(int i{}; i < n; ++i)
    {
        if(!m.count(arr[i]))
        {
            v.push_back(arr[i]);
            m[arr[i]] = true;
        }
    }

    for(int num : v)
        std::cout << num << ' ';

    return 0;
}