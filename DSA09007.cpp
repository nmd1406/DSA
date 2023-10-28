#include<bits/stdc++.h>

using namespace std;

int n, m, s, e;
vector<vector<int>> edges;
vector<bool> isVisited;
vector<int> trace;

void BFS(int s)
{
    queue<int> q;
    q.push(s);
    isVisited[s] = true;

    while(!q.empty())
    {
        int temp{q.front()};
        q.pop();

        for(auto itr : edges[temp])
        {
            if(!isVisited[itr])
            {
                isVisited[itr] = true;
                trace[itr] = temp;
                q.push(itr);
            }
        }
    }
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        cin >> n >> m >> s >> e;

        edges.resize(n + 1);
        isVisited.resize(n + 1);
        trace.resize(n + 1);

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

        BFS(s);

        if(!isVisited[e])
            cout << "-1\n";
        else
        {
            vector<int> path;

            while(s != e)
            {
                path.push_back(e);
                e = trace[e];
            }

            path.push_back(s);
            reverse(path.begin(), path.end());

            for(auto itr : path)
                cout << itr << ' ';

            cout << '\n';
        }
    }

    return 0;
}