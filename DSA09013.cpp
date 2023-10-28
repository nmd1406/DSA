#include<bits/stdc++.h>

using namespace std;

int v{};
int e{};
vector<vector<int>> mtx{};
vector<pair<int, int>> edgeList{};
vector<bool> isVisited{}; 

void dfs(int u)
{
    isVisited[u] = true;
    for(int ver : mtx[u])
        if(!isVisited[ver])
            dfs(ver);
}

void boCanh(int u, int fv, int sv)
{
    isVisited[u] = true;

    for(int ver : mtx[u])
    {
        if((u == fv && ver == sv) || (u == sv && ver == fv))
            continue;
        if(!isVisited[ver])
            boCanh(ver, fv, sv);
    }
}

void canhCau()
{
    int tplt{};
    for(int i{1}; i <= v; ++i)
    {
        if(!isVisited[i])
        {
            ++tplt;
            dfs(i);
        }
    }

    for(auto itr : edgeList)
    {
        int fv{itr.first};
        int sv{itr.second};

        isVisited.clear();
        isVisited.resize(v + 1, false);

        int count{};
        for(int i{1}; i <= v; ++i)
        {
            if(!isVisited[i])
            {
                ++count;
                boCanh(i, fv, sv);
            }
        }

        if(count > tplt)
            cout << fv << ' ' << sv << ' ';
    }

    cout << '\n';
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        cin >> v >> e;
        mtx.clear();
        mtx.resize(v + 1);
        isVisited.clear();
        isVisited.resize(v + 1, false);    
        edgeList.clear();

        for(int i{}; i < e; ++i)
        {
            int fv{};
            int sv{};
            cin >> fv >> sv;

            edgeList.push_back({fv, sv});

            mtx[fv].push_back(sv);
            mtx[sv].push_back(fv);
        }

        canhCau();
    }

    return 0;
}