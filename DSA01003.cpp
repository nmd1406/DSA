#include<iostream>
#include<algorithm>

void output(int arr[], int n)
{
    for(int i{}; i < n; ++i)
        std::cout << arr[i] << ' ';

    std::cout << '\n';
}

void gen(int arr[], int n)
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
    {
        for(int k{}; k < n; ++k)
            arr[k] = k + 1;
    }
}

int main()
{
    int test{};
    std::cin >> test;

    while(test--)
    {
        int n{};
        std::cin >> n;

        int arr[n]{};
        for(int i{}; i < n; ++i)
            std::cin >> arr[i];

        gen(arr, n);
        output(arr, n);
    }

    return 0;
}