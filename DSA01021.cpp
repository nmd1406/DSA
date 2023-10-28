#include<iostream>

void gen(int arr[], int n, int k)
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
}

void output(int arr[], int k)
{
    for(int i{}; i < k; ++i)
        std::cout << arr[i];

    std::cout << '\n';
}

int main()
{
    int test{};
    std::cin >> test;

    while(test--)
    {
        int n{};
        int k{};
        std::cin >> n >> k;

        int a[k]{};
        int b[k]{};

        for(int i{}; i < k; ++i)
        {
            std::cin >> a[i];
            b[i] = a[i];
        }

        gen(a, n, k);
        int count{};
        for(int i{}; i < k; ++i)
        {
            for(int j{}; j < k; ++j)
            {
                if(a[i] == b[j])
                    ++count;
            }
        }
        if(k != count)
            std::cout << k - count << '\n';
        else
            std::cout << k << '\n';

        // output(a, k);
    }

    return 0;
}