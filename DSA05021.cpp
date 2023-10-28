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

        vector<pair<int, int>> v{};
        for(int i{}; i < n; ++i)
        {
            int f{};
            int s{};
            cin >> f >> s;
            v.push_back(make_pair(f, s));
        }

        sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b)
                                    {
                                        return a.second < b.second;
                                    });

        int ans{};
        int dp[n]{};
        for(int i{}; i < n; ++i)
            dp[i] = 1;

        for(int i{1}; i < n; ++i)
        {
            for(int j{}; j < i; ++j)
            {
                if(v[j].second < v[i].first)
                    dp[i] = max(dp[i], dp[j] + 1);
            }

            ans = max(ans, dp[i]);
        }

        cout << ans << '\n';
    }

    return 0;
}