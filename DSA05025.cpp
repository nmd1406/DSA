#include<iostream>

using namespace std;

long long ech(int n)
{
    if(n == 0 || n == 1)
        return 1;

    long long dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;

    for(int i{2}; i <= n; ++i)
    {
        long long ans{};
        for(int j{1}; j <= 3; ++j)
        {
            if(i - j >= 0)
                ans += dp[i - j];
        }

        dp[i] = ans;
    }

    return dp[n];
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {   
        int n{};
        cin >> n;

        cout << ech(n) << '\n';
    }

    return 0;
}