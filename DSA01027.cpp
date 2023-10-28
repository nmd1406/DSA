#include<iostream>
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
    int n{};
    std::cin >> n;
    int a[n]{};
    for(int i{}; i < n; ++i)
        std::cin >> a[i];

    std::sort(a, a + n);

    int b[n]{};
    for(int i{}; i < n; ++i)
        b[i] = i + 1;

    bool stop{false};
    while(!stop)
    {
        for(int i{}; i < n; ++i)
            std::cout << a[b[i] - 1] << ' ';
        
        gen(b, n, stop);
        std::cout << '\n';
    }

    return 0;
}