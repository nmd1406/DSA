#include<iostream>

void output(int arr[], int n)
{
    for(int i{}; i < n; ++i)
        std::cout << arr[i];

    std::cout << '\n';
}

void gen(int arr[], int n, bool& stop, int& count)
{
    int i{n - 1};
    while(i >= 0 && arr[i])
    {
        arr[i] = 0;
        --i;
    }
    if(i >= 0)
    {
        arr[i] = 1;
        for(int j{}; j < n; ++j)
        {
            if(arr[j])
                ++count;
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
        int n{};
        int k{};
        std::cin >> n >> k;

        int arr[n]{};

        bool stop{false};
        while(!stop)
        {
            int count{};
            gen(arr, n, stop, count);
            if(count == k)
                output(arr, n);
        }
    }

    return 0;
}