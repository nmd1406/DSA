#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<int> degree(1001);
vector<vector<int>> edges(1001);

bool kahn()
{
    queue<int> q;
    for(int i{1}; i <= n; ++i)
    {
        if(!degree[i])
            q.push(i);
    }

    int count{};
    while(!q.empty())
    {
        int u{q.front()};
        q.pop();

        ++count;

        for(int v : edges[u])
        {
            --degree[v];
            if(!degree[v])
                q.push(v);
        }
    }

    return count == n;
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        cin >> n >> m;
        for(int i{1}; i <= n; ++i)
        {
            degree[i] = 0;
            edges[i].clear();
        }

        while(m--)
        {
            int fv, sv;
            cin >> fv >> sv;
            edges[fv].push_back(sv);
            ++degree[sv];
        }

        if(kahn())
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}