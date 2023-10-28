#include<bits/stdc++.h>

using namespace std;


int main()
{
    int n{};
    int m{};
    int arr[101][101]{};
    cin >> n >> m;

    for(int i{1}; i <= n; ++i)
    {
        for(int j{1}; j <= n; ++j)
            arr[i][j] = 1e9;

        arr[i][i] = 0;
    }

    while(m--)
    {
        int u{};
        int v{};
        int w{};
        cin >> u >> v >> w;

        arr[u][v] = arr[v][u] = w;
    }

    // for(int i{1}; i <= n; ++i)
    // {
    //     for(int j{1}; j <= n; ++j)
    //         cout << arr[i][j] << ' ';

    //     cout << "\n";
    // }


    for(int k{1}; k <= n; ++k)
    {
        for(int i{1}; i <= n; ++i)
        {
            for(int j{1}; j <= n; ++j)
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
        }
    }

    int q{};
    cin >> q;
    while(q--)
    {
        int s{};
        int e{};
        cin >> s >> e;
        cout << arr[s][e] << '\n';
    }

    return 0;
}