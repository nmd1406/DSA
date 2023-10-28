#include<iostream>
#include<algorithm>

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
    
}

bool check(int a[], int b[], int n)
{
    for(int i{}; i < n; ++i)
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
        std::cin >> n;

        int a[n]{};
        int b[n]{};

        for(int i{}; i < n; ++i)
        {
            std::cin >> a[i];
            b[i] = i + 1;
        }

        int count{1};
        while(!check(a, b, n))
        {
            gen(b, n);
            ++count;
        }

        std::cout << count << '\n';
    }

    return 0;
}