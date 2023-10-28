#include<bits/stdc++.h>

using namespace std;

int n, m, e;
bool stop{false};
vector<vector<int>> edges;
bool isVisited[1005];
int trace[1005];

void DFS(int u, int par)
{
    if(stop)
        return;
        
    isVisited[u] = true;

    for(auto v : edges[u])
    {
        if(!isVisited[v])
        {
            trace[v] = u;
            DFS(v, u);
        }
        else if(v != trace[u] && v == 1)
        {
            e = u;
            stop = true;
            return;
        }
    }
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        stop = false;
        edges.clear();
        cin >> n >> m;

        memset(trace, 0, sizeof(trace));
        memset(isVisited, false, sizeof(isVisited));
        edges.resize(n + 1);

        while(m--)
        {
            int fv, sv;
            cin >> fv >> sv;
            edges[fv].push_back(sv);
            edges[sv].push_back(fv);
        }

        for(int i{1}; i <= n; ++i)
            sort(edges[i].begin(), edges[i].end());

        DFS(1, 0);
        if(stop)
        {
            stack<int> st;
            cout << 1 << ' ';
            while(trace[e])
            {
                st.push(e);
                e = trace[e];
            }

            while(!st.empty())
            {
                cout << st.top() << ' ';
                st.pop();
            }

            cout << 1 << '\n';
        }
        else
            cout << "NO\n";
    }

    return 0;
}