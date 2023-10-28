#include<bits/stdc++.h>

using namespace std;

struct Edge
{
    int fv{};
    int sv{};
    int w{};
};

int parent[101]{};
int num[101]{};
int v{};
int e{};

void init()
{
    for(int i{1}; i <= v; ++i)
    {
        parent[i] = i;
        num[i] = 1;
    }
}

int Find(int u)
{
    if(u == parent[u])
        return u;

    return Find(parent[u]);
}

bool Union(int u, int v)
{
    int a{Find(u)};
    int b{Find(v)};

    if(a == b)
        return false;

    if(num[a] < num[b])
        swap(a, b);

    parent[b] = a;
    num[a] += num[b];

    return true;
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        cin >> v >> e;
        init();

        vector<Edge> edges{};
        for(int i{}; i < e; ++i)
        {
            int fv{};
            int sv{};
            int w{};
            cin >> fv >> sv >> w;
            edges.push_back({fv, sv, w});
        }

        sort(edges.begin(), edges.end(), [](Edge& a, Edge& b)
                                        {
                                            return a.w < b.w;
                                        });

        int res{};
        for(auto& edge : edges)
        {
            if(Union(edge.fv, edge.sv))
                res += edge.w;
        }

        cout << res << '\n';
    }

    return 0;
}