#include<iostream>

bool stop{false};

void gen(int arr[], int n)
{
    int i{n - 1};

    while(i >= 0 && arr[i])
    {
        arr[i] = 0;
        --i;
    }

    if(i >= 0)
        arr[i] = 1;
    else
        stop = true;
}

bool check(int a[], int b[], int n, int k)
{
    int sum{};
    for(int i{}; i < n; ++i)
    {
        if(b[i])
            sum += a[i];
    }

    if(sum == k)
        return true;

    return false;
}

void output(int a[], int b[], int n)
{
    for(int i{}; i < n; ++i)
    {
        if(b[i])
            std::cout << a[i] << ' ';
    }

    std::cout << '\n';
}

int main()
{
    int n{};
    int k{};
    std::cin >> n >> k;

    int a[n]{};
    int b[n]{};

    for(int i{}; i < n; ++i)
        std::cin >> a[i];

    int count{};
    while(!stop)
    {
        if(check(a, b, n, k))
        {
            output(a, b, n);
            ++count;
        }
        gen(b, n);
    }

    std::cout << count;
    return 0;
}