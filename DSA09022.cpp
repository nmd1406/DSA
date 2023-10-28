#include<bits/stdc++.h>

using namespace std;

void dfs(const vector<vector<int>>& matrix, int u, vector<bool>& isVisited)
{
    cout << u << ' ';
    isVisited[u] = true;

    int n = matrix.size();

    for(int i{1}; i < n; ++i)
    {
        if(matrix[u][i] && !isVisited[i])
            dfs(matrix, i, isVisited);
    }
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

        vector<vector<int>> matrix(v + 1, vector<int>(v + 1));
        for(int i{}; i < e; ++i)
        {
            int fv{};
            int sv{};
            cin >> fv >> sv;

            matrix[fv][sv] = 1;
        }

        vector<bool> isVisited(v + 1, false);
        dfs(matrix, u, isVisited);
        cout << '\n';
    }

    return 0;
}