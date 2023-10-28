#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> mtx(1001);
vector<bool> isVisited(1001);
int v{};
int e{};

void BFS(int u)
{
    queue<int> q{};
    q.push(u);

    isVisited[u] = true;

    while(!q.empty())
    {
        int temp{q.front()};
        q.pop();

        isVisited[temp] = true;

        for(int itr : mtx[temp])
        {
            if(!isVisited[itr])
            {
                q.push(itr);
                isVisited[itr] = true;
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
        cin >> v >> e;
        
        for(int i{1}; i <= v; ++i)
        {
            mtx[i].clear();
            isVisited[i] = false;
        }

        while(e--)
        {
            int fv{};
            int sv{};
            cin >> fv >> sv;

            mtx[fv].push_back(sv);
            mtx[sv].push_back(fv);
        }

        int tplt{};
        for(int i{1}; i <= v; ++i)
        {
            if(!isVisited[i])
            {
                ++tplt;
                BFS(i);
            }
        }

        cout << tplt << '\n';
    }

    return 0;
}