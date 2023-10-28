#include<iostream>

int arr[100]{};
bool isStop{false};

bool check(int arr[], int n)
{
    for(int i{1}; i <= n / 2; ++i)
    {
        if(arr[i] != arr[n - i + 1])
            return false;
    }

    return true;
}

void gen(int n)
{
    int i{n};
    while(i > 0 && arr[i])
    {
        arr[i] = 0;
        --i;
    }

    if(i > 0)
        arr[i] = 1;
    else
        isStop = true;
}

void print(int arr[], int n)
{
    for(int i{1}; i <= n; ++i)
        std::cout << arr[i] << ' ';

    std::cout << '\n';
}

int main()
{
    int n{};
    std::cin >> n;

    while(!isStop)
    {
        if(check(arr, n))
            print(arr, n);
        
        gen(n); 
    }

    return 0;
}