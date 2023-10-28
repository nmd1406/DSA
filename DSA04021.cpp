#include<iostream>

using namespace std;

long long fibo[93]{};

int nhiPhan(int n, long long k)
{
    if(n == 1)
        return 0;
    if(n == 2)
        return 1;

    if(k <= fibo[n - 2])
        return nhiPhan(n - 2, k);
    
    return nhiPhan(n - 1, k - fibo[n - 2]);
}

int main()
{
    int test{};
    cin >> test;

    fibo[0] = 0;
    fibo[1] = 1;
    for(int i{2}; i <= 92; ++i)
        fibo[i] = fibo[i - 1] + fibo[i - 2];

    while(test--)
    {
        int n{};
        long long k{};
        cin >> n >> k;

        cout << nhiPhan(n, k) << '\n';
    }

    return 0;
}