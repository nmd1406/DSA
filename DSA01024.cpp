#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
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
    std::vector<std::string> v1{};
    for(int i{}; i < n; ++i)
    {
        std::string str{};
        std::cin >> str;
        v1.push_back(str);
    }

    std::vector<std::string> v2{};
    std::unordered_map<std::string, bool> m{};
    for(int i{}; i < n; ++i)
    {
        if(!m.count(v1[i]))
        {
            v2.push_back(v1[i]);
            m[v1[i]] = true;
        }
    }

    std::sort(v2.begin(), v2.end());

    int arr[k]{};
    for(int i{}; i < k; ++i)
        arr[i] = i + 1;

    bool stop{false};
    while(!stop)
    {
        for(int i{}; i < k; ++i)
        {
            std::cout << v2[arr[i] - 1] << ' ';
        }
        gen(arr, v2.size(), k, stop);

        std::cout << '\n';
    }

    return 0;
}