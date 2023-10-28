#include<bits/stdc++.h>

using namespace std;

int n{};
int m{};
int s{};
int e{};
vector<vector<int>> edges{};
vector<bool> visited{};
vector<int> trace{};

void DFS(int s)
{
    visited[s] = true;

    for(auto itr : edges[s])
    {
        if(!visited[itr])
        {
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
        cin >> n >> m >> s >> e;


        edges.resize(n + 1);
        visited.resize(n + 1);
        trace.resize(n + 1);

        for(int i{1}; i <= n; ++i)
        {
            edges[i].clear();
            trace[i] = 0;
            visited[i] = false;
        }

        while(m--)
        {
            int fv{};
            int sv{};
            cin >> fv >> sv;

            edges[fv].push_back(sv);
        }

        DFS(s);
        vector<int> res;
        if(!visited[e])
            cout << "-1\n";
        else
        {
            while(e != s)
            {
                res.push_back(e);
                e = trace[e];
            }

            res.push_back(s);
            reverse(res.begin(), res.end());

            for(auto i : res)
                cout << i << ' ';

            cout << '\n';
        }
    }

    return 0;
}