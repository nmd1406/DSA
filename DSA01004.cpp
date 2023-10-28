#include<iostream>

void output(int arr[], int k)
{
    for(int i{}; i < k; ++i)
        std::cout << arr[i];

    std::cout << ' ';
}

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
    int test{};
    std::cin >> test;

    while(test--)
    {
        int n{};
        int k{};
        std::cin >> n >> k;

        int arr[k]{};
        for(int i{}; i < k; ++i)
            arr[i] = i + 1;

        bool stop{false};
        while(!stop)
        {
            output(arr, k);
            gen(arr, n, k, stop);
        }

        std::cout << '\n';
    }

    return 0;
}