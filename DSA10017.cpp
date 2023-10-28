#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int n{};
        int m{};
        cin >> n >> m;

        vector<tuple<int, int, int>> edges{};
        for(int i{1}; i <= m; ++i)
        {
            int fv{};
            int sv{};
            int w{};
            cin >> fv >> sv >> w;
            edges.push_back(make_tuple(fv, sv, w));
        }

        vector<int> dist(n + 1, 1e9);
        dist[1] = 0;

        for(int i{1}; i <= n - 1; ++i)
        {
            for(auto [u, v, w] : edges)
            {
                if(dist[u] + w < dist[v])
                    dist[v] = dist[u] + w;
            }
        }

        bool flag{false};
        for(auto [u, v, w] : edges)
        {
            if(dist[u] + w < dist[v])
            {
                flag = true;
                break;
            }
        }

        if(flag)
            cout << "1\n";
        else    
            cout << "0\n";
    }

    return 0;
}