#include<bits/stdc++.h>

using namespace std;

int v{};
int e{};
int parent[1001]{};
int num[1001]{};

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

        vector<pair<int, int>> edges{};
        for(int i{}; i < e; ++i)
        {
            int fv{};
            int sv{};
            cin >> fv >> sv;

            edges.push_back({fv, sv});
        }

        bool flag{false};
        for(auto& edge : edges)
        {
            if(!Union(edge.first, edge.second))
            {
                flag = true;
                break;
            }
        }

        if(!flag)
            cout << "NO\n";
        else
            cout << "YES\n";
    }

    return 0;
}