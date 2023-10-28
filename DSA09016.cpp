#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<int> color(1001);
vector<vector<int>> edges(1001);

bool dfs(int u)
{
    color[u] = 1;
    for(int v : edges[u])
    {
        if(color[v] == 0)
        {
            if(dfs(v))
                return true;
        }
        else if(color[v] == 1)
            return true;
    }

    color[u] = 2;

    return false;
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
            edges[i].clear();
            color[i] = 0;
        }

        while(m--)
        {
            int fv, sv;
            cin >> fv >> sv;
            edges[fv].push_back(sv);
        }

        bool flag{false};

        for(int i{1}; i <= n; ++i)
        {
            if(color[i] == 0)
            {
                if(dfs(i))
                {
                    flag = true;
                    break;
                }
            }
        }

        if(flag)
            cout << "YES\n";
        else
            cout << "NO\n"; 
    }

    return 0;
}