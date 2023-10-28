#include<iostream>


void gen(int arr[], int n, int k)
{
    int i{k - 1};
    while(i >= 0 && arr[i] == n - k + i + 1)
        --i;

    if(i >= 0)
    {
        arr[i]++;

        for(int j{i + 1}; j < k; ++j)
            arr[j] = arr[i] + j - i;
    }
    else
    {
        for(int j{}; j < k; ++j)
            arr[j] = j + 1;
    }
}

void output(int arr[], int k)
{
    for(int i{}; i < k; ++i)
        std::cout << arr[i] << ' ';

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
        int arr[k]{};
        for(int i{}; i < k; ++i)
            std::cin >> arr[i];
        
        gen(arr, n, k);
        output(arr, k);
    }

    return 0;
}