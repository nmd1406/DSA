#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int n{};
        cin >> n;

        int arr[n]{};
        int sum{};
        for(int i{}; i < n; ++i)
        {
            cin >> arr[i];
            sum += arr[i];
        }

        if(sum % 2 == 1)
            cout << "NO\n";
        else
        {
            int k{sum / 2};
            bool dp[k + 1]{};
            dp[0] = true;

            for(int i{}; i < n; ++i)
            {
                for(int j{k}; j >= arr[i]; --j)
                {
                    if(dp[j - arr[i]])
                        dp[j] = true;
                }
            }

            if(dp[k])
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        
    }

    return 0;
}