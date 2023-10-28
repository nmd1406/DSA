#include<bits/stdc++.h>

using namespace std;

int v{};
int e{};
int parent[1001];
int num[1001];

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
    if(u != parent[u])
       parent[u] = Find(parent[u]);

    return parent[u];
}

void Union(int u, int v)
{
    int a{Find(u)};
    int b{Find(v)};

    if(a == b)
        return;

    if(num[a] < num[b])
        swap(a, b);

    parent[b] = a;
    num[a] += num[b];
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        cin >> v >> e;
        init();
        while(e--)
        {
            int u{};
            int v{};
            cin >> u >> v;
            Union(u, v);
        }

        int count{};
        for(int i{1}; i <= v; ++i)
        {
            if(parent[i] == i)
                ++count;
        }

        cout << count << '\n';
    }

    return 0;
}