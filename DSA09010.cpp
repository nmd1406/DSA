#include<bits/stdc++.h>

using namespace std;

int v{};
int e{};
vector<vector<int>> mtx(1001);
vector<vector<int>> rMtx(1001);
vector<bool> isVisited(1001);
stack<int> s{};

void dfs1(int u)
{
    isVisited[u] = true;
    
    for(auto itr : mtx[u])
    {
        if(!isVisited[itr])
            dfs1(itr);
    }

    s.push(u);
}

void dfs2(int u)
{
    isVisited[u] = true;

    for(auto itr : rMtx[u])
    {
        if(!isVisited[itr])
            dfs2(itr);
    }
}

int scc()
{
    isVisited.clear();
    isVisited.resize(1001, false);

    for(int i{1}; i <= v; ++i)
    {
        if(!isVisited[i])
            dfs1(i);
    }

    isVisited.clear();
    isVisited.resize(1001, false);

    int count{};
    while(!s.empty())
    {
        int u{s.top()};
        s.pop();

        if(!isVisited[u])
        {
            dfs2(u);
            ++count;
        }
    }

    return count;
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        cin >> v >> e;

        for(int i{1}; i <= v; ++i)
        {
            mtx[i].clear();
            rMtx[i].clear();
            isVisited[i] = false;
        }

        while(e--)
        {
            int fv{};
            int sv{};
            cin >> fv >> sv;

            mtx[fv].push_back(sv);
            rMtx[sv].push_back(fv);
        }

        cout << scc();

        // if(scc() == 1)
        //     cout << "YES\n";
        // else
        //     cout << "NO\n";
    }

    return 0;
}