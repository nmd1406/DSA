#include<iostream>
#include<string>
#include<algorithm>

void gen(int arr[], int n, bool& stop)
{
    int i{n - 2};
    while(i >= 0 && arr[i] > arr[i + 1])
        --i;

    if(i >= 0)
    {
        int j{n - 1};
        while(arr[i] > arr[j])
            --j;

        std::swap(arr[i], arr[j]);

        int l{i + 1};
        int r{n - 1};
        while(l <= r)
        {
            std::swap(arr[l], arr[r]);
            ++l;
            --r;
        }
    }
    else
        stop = true;
}

int main()
{
    int test{};
    std::cin >> test;

    while(test--)
    {
        std::string str{};
        std::cin >> str;

        int n = str.size();
        int arr[n]{};
        for(int i{}; i < n; ++i)
            arr[i] = i + 1;

        bool stop{false};
        while(!stop)
        {
            for(int i{}; i < n; ++i)
                std::cout << str[arr[i] - 1];

            gen(arr, n, stop);
            std::cout << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}