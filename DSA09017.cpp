#include<bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> edges;

void dfs(int u, bool isVisited[])
{
    isVisited[u] = true;

    for(auto itr : edges[u])
    {
        if(!isVisited[itr])
            dfs(itr, isVisited);
    }
}

bool isConnected()
{
    bool isVisited[n + 1]{};
    dfs(1, isVisited);

    for(int i{1}; i <= n; ++i)
        if(!isVisited[i])
            return false;

    return true;
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        cin >> n;
        edges.resize(n + 1);

        for(int i{1}; i <= n; ++i)
            edges[i].clear();

        for(int i{1}; i < n; ++i)
        {
            int fv, sv;
            cin >> fv >> sv;
            edges[fv].push_back(sv);
            edges[sv].push_back(fv);
        }

        if(isConnected())
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}