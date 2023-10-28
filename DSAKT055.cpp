#include<bits/stdc++.h>

using namespace std;

int knapSack(int n, int maxWeight, int value[], int weight[])
{
    int dp[n + 1][maxWeight + 1];
    for(int i{}; i <= n; ++i)
    {
        for(int j{}; j <= maxWeight; ++j)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(weight[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
            {
                int include{value[i - 1] + dp[i - 1][j - weight[i - 1]]};
                int exclude{dp[i - 1][j]};

                dp[i][j] = max(include, exclude);
            }
        }
    }

    return dp[n][maxWeight];
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int n{};
        int maxWeight{};
        cin >> n >> maxWeight;

        int weights[n]{};
        int value[n]{};
        for(int i{}; i < n; ++i)
            cin >> weights[i];
        for(int i{}; i < n; ++i)
            cin >> value[i];

        cout << knapSack(n, maxWeight, value, weights) << '\n';
    }

    return 0;
}