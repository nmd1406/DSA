#include<iostream>

bool check(int arr[], int n)
{
    for(int i{}; i < n - 1; ++i)
    {
        if(arr[i] == arr[i + 1] && arr[i] == 1)
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

        if(n == 2)
        {
            std::cout << "HA\n"; 
            continue;
        }

        int arr[n]{};
        arr[0] = 1;
        arr[n - 1] = 0;

        bool stop{false};
        while(!stop)
        {
            if(check(arr, n))
            {
                for(int i{}; i < n; ++i)
                {
                    if(arr[i])
                        std::cout << 'H';
                    else
                        std::cout << 'A';
                }
                std::cout << '\n';
            }

            int i{n - 2};
            while(i >= 1 && arr[i])
            {
                arr[i] = 0;
                --i;
            }
            if(i >= 1)
                arr[i] = 1;
            else
                stop = true;
        }

    }

    return 0;
}