#include<iostream>

void output(char str[], int n)
{
    for(int i{}; i < n; ++i)
        std::cout << str[i];

    std::cout << ' ';
}

void gen(char str[], int n, bool& stop)
{
    int i{n - 1};
    while(i >= 0 && str[i] == 'B')
    {
        str[i] = 'A';
        --i;
    }

    if(i >= 0)
        str[i] = 'B';
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
        char str[n]{};
        for(int i{}; i < n; ++i)
            str[i] = 'A';

        bool stop{false};
        while(!stop)
        {
            output(str, n);
            gen(str, n, stop);
        }
        std::cout << '\n';
    }

    return 0;
}