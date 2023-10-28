#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int n{};
        int s{};
        cin >> n >> s;

        int arr[n]{};
        for(int i{}; i < n; ++i)
            cin >> arr[i];

        bool dp[s + 1]{};
        dp[0] = true;
        for(int i{}; i < n; ++i)
        {
            for(int j{s}; j >= arr[i]; --j)
            {
                if(dp[j - arr[i]])
                    dp[j] = true;
            }
        }

        if(dp[s])
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}