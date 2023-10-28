#include<iostream>

void gen(int arr[], int n, bool& stop)
{
    int i{n - 2};
    while(i >= 1 && arr[i] == 8)
    {
        arr[i] = 6;
        --i;
    }
    if(i >= 1)
        arr[i] = 8;
    else
        stop = true;
}

bool check(int arr[], int n)
{
    int count6{};
    int count8{};

    for(int i{}; i < n; ++i)
    {
        if(arr[i] == 6)
        {
            ++count6;
            count8 = 0;
        }
        else
        {
            ++count8;
            count6 = 0;
        }

        if(count6 > 3 || count8 > 1)
            return false;
    }

    return true;
}

int main()
{
    int n{};
    std::cin >> n;
    if(n == 2)
        std::cout << 86;
    else
    {
        int arr[n]{};
        arr[0] = 8; 
        for(int i{1}; i < n; ++i)
            arr[i] = 6;

        bool stop{false};
        while(!stop)
        {
            if(check(arr, n))
            {
                for(int i{}; i < n; ++i)
                    std::cout << arr[i];

                std::cout << '\n';
            }
            gen(arr, n, stop);
        }
    }

    return 0;
}