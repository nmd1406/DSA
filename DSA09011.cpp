#include<bits/stdc++.h>

using namespace std;

int n, m;
int row[]{-1, -1, -1, 0, 0, 1, 1, 1};
int col[]{-1, 0, 1, -1, 1, -1, 0, 1};
int mtx[505][505];
bool isVisited[505][505];

bool check(int u, int v)
{
    return (u && v && u <= n && v <= m && (mtx[u][v] && !isVisited[u][v]));
}

void DFS(int u, int v)
{
    isVisited[u][v] = true;

    for(int i{}; i < 8; ++i)
    {
        if(check(u + row[i], v + col[i]))
            DFS(u + row[i], v + col[i]);
    }
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {   
        cin >> n >> m;
        memset(mtx, 0, sizeof(mtx));
        memset(isVisited, false, sizeof(isVisited));

        for(int i{1}; i <= n; ++i)
            for(int j{1}; j <= m; ++j)
                cin >> mtx[i][j];

        int count{};
        for(int i{1}; i <= n; ++i)
        {
            for(int j{1}; j <= m; ++j)
            {
                if(mtx[i][j] && !isVisited[i][j])
                {
                    ++count;
                    DFS(i, j);
                }
            }
        }

        cout << count << '\n';
    }

    return 0;
}