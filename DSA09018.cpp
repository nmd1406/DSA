#include<bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>>& mtx, int u, vector<bool>& isVisited)
{
    isVisited[u] = true;
    int n = mtx.size();
    for(int i{1}; i < n; ++i)
    {
        if(mtx[u][i] && !isVisited[i])
            dfs(mtx, i, isVisited);
    }
}

void dinhTru(vector<vector<int>>& mtx, vector<bool>& isVisited)
{
    int n = mtx.size();
    int tplt{};
    for(int i{1}; i < n; ++i)
    {
        if(!isVisited[i])
        {
            ++tplt;
            dfs(mtx, i, isVisited);
        }
    }

    for(int i{1}; i < n; ++i)
    {
        isVisited.clear();
        isVisited.resize(n, false);

        isVisited[i] = true;
        int count{};
        for(int j{1}; j < n; ++j)
        {
            if(!isVisited[j])
            {
                ++count;
                dfs(mtx, j, isVisited);
            }
        }

        if(count > tplt)
            cout << i << ' ';
    }

    cout << '\n';
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int v{};
        int e{};
        cin >> v >> e;

        vector<vector<int>> mtx(v + 1, vector<int>(v + 1));
        for(int i{}; i < e; ++i)
        {
            int fv{};
            int sv{};
            cin >> fv >> sv;

            mtx[fv][sv] = 1;
            mtx[sv][fv] = 1;
        }

        vector<bool> isVisited(v + 1, false);
        dinhTru(mtx, isVisited);
    }

    return 0;
}