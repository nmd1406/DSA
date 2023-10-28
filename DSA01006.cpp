#include<iostream>
#include<algorithm>

void output(int arr[], int n)
{
    for(int i{}; i < n; ++i)
        std::cout << arr[i];

    std::cout << ' ';
}

void gen(int arr[], int n, bool& stop)
{
    int i{n - 2};
    while(i >= 0 && arr[i] < arr[i + 1])
        --i;

    if(i >= 0)
    {
        int j{n - 1};
        while(arr[i] < arr[j])
            --j;

        std::swap(arr[i], arr[j]);
        std::reverse(arr + i + 1, arr + n);
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
        std::cin >> n;
        int arr[n]{};

        for(int i{}; i < n; ++i)
            arr[i] = n - i;

        bool stop{false};

        while(!stop)
        {
            output(arr, n);
            gen(arr, n, stop);
        }

        std::cout << '\n';
    }

    return 0;
}