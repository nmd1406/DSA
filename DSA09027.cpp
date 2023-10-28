#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> edges;
vector<bool> isVisited;
vector<int> trace;

void DFS(int s)
{
    isVisited[s] = true;
    for(auto itr : edges[s])
    {
        if(!isVisited[itr])
        {
            isVisited[itr] = true;
            trace[itr] = s;
            DFS(itr);
        }
    }
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        cin >> n >> m;

        edges.resize(n + 1);
        trace.resize(n + 1);
        isVisited.resize(n + 1);

        for(int i{1}; i <= n; ++i)
        {
            edges[i].clear();
            isVisited[i] = false;
            trace[i] = 0;
        }

        while(m--)
        {
            int fv, sv;
            cin >> fv >> sv;
            edges[fv].push_back(sv);
            edges[sv].push_back(fv);
        }

        int q;
        cin >> q;
        while(q--)
        {
            int s, e;
            cin >> s >> e;
            for(int i{1}; i <= n; ++i)
            {
                trace[i] = 0;
                isVisited[i] = false;
            }
            DFS(s);

            if(!isVisited[e])
                cout << "NO\n";
            else
                cout << "YES\n";
        }
    }

    return 0;
}