#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

void gen(int arr[], int n, int k, bool& stop)
{
    int i{k - 1};
    while(i >= 0 && arr[i] == n - k + i + 1)
        --i;

    if(i >= 0)
    {
        ++arr[i];
        for(int j{i + 1}; j < k; ++j)
            arr[j] = arr[i] + j - i;
    }
    else
        stop = true;
}

int main()
{
    int n{};
    int k{};
    std::cin >> n >> k;

    int arr[n]{};
    std::vector<int> v{};
    std::unordered_map<int, bool> m{};
    for(int i{}; i < n; ++i)
    {
        std::cin >> arr[i];
        if(!m.count(arr[i]))
        {
            v.push_back(arr[i]);
            m[arr[i]] = true;
        }
    }

    for(int i{}; i < v.size(); ++i)
        arr[i] = i + 1;

    std::sort(v.begin(), v.end());

    bool stop{false};
    while(!stop)
    {
        for(int i{}; i < k; ++i)
            std::cout << v[arr[i] - 1] << ' ';

        gen(arr, v.size(), k, stop);
        std::cout << '\n';
    }

    return 0;
}