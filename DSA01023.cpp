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

bool check(int a[], int b[], int k)
{
    for(int i{}; i < k; ++i)
    {
        if(a[i] != b[i])
            return false;
    }

    return true;
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
            b[i] = i + 1;
        }

        int count{1};
        while(!check(a, b, k))
        {
            gen(b, n, k);
            ++count;
        }

        std::cout << count << '\n';
    }

    return 0;
}