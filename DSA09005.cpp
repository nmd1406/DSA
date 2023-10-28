#include<bits/stdc++.h>

using namespace std;

void bfs(vector<vector<int>> mtx, int u)
{
    int n = mtx.size();
    vector<bool> isVisited(n, false);

    queue<int> q{};
    q.push(u);
    isVisited[u] = true;

    while(!q.empty())
    {
        int currV{q.front()};
        q.pop();

        cout << currV << ' ';
        for(int i{1}; i < n; ++i)
        {
            if(mtx[currV][i] && !isVisited[i])
            {
                q.push(i);
                isVisited[i] = true;
            }
        }
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
        int u{};
        cin >> v >> e >> u;

        vector<vector<int>> mtx(v + 1, vector<int>(v + 1, 0));
        for(int i{}; i < e; ++i)
        {
            int fv{};
            int sv{};
            cin >> fv >> sv;
            mtx[fv][sv] = 1;
            mtx[sv][fv] = 1;
        }

        bfs(mtx, u);
    }

    return 0;
}