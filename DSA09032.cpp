#include<bits/stdc++.h>

using namespace std;

int n;
int m;
int parent[100000];
int num[100000];
int ans{};

void init()
{
    ans = 0;
    for(int i{1}; i <= n; ++i)
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
    ans = max(ans, num[a]);
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        cin >> n >> m;
        init();

        while(m--)
        {
            int u{};
            int v{};
            cin >> u >> v;

            Union(u, v);
        }

        cout << ans << '\n';
    }

    return 0;
}