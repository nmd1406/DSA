#include<iostream>

using namespace std;

long long fibo[100];

char fiboChar(int n, long long k)
{
    if(n == 1)
        return 'A';
    if(n == 2)
        return 'B';

    if(k <= fibo[n - 2])
        return fiboChar(n - 2, k);

    return fiboChar(n - 1, k - fibo[n - 2]);
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

        cout << fiboChar(n, k) << '\n';
    }

    return 0;
}