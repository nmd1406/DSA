#include<bits/stdc++.h>

using namespace std;

bool solve(int n, int m)
{
    vector<vector<int>> edges(n + 1);
    while(m--)
    {
        int fv, sv;
        cin >> fv >> sv;

        edges[fv].push_back(sv);
        edges[sv].push_back(fv);
    }

    for(int i{1}; i <= n; ++i)
    {
        for(auto u : edges[i])
            if(edges[i].size() != edges[u].size())
                return false;
    }

    return true;
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int n, m;
        cin >> n >> m;

        if(solve(n, m))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}