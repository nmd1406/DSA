#include<bits/stdc++.h>

using namespace std;

int countPair(int num, int y[], int m, int c[])
{
    if(num == 0)
        return 0;
    
    if(num == 1)
        return c[0];

    auto idx = upper_bound(y, y + m, num);
    int ans = y + m - idx;

    ans += c[0] + c[1];

    if(num == 2)
        ans -= (c[3] + c[4]);

    if(num == 3)
        ans += c[2];

    return ans;
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int n, m;
        cin >> n >> m;
        int x[n], y[m];

        for(int i{}; i < n; ++i)
            cin >> x[i];

        for(int i{}; i < m; ++i)
            cin >> y[i];

        sort(y, y + m);

        int c[5]{};
        for(int i{}; i < m; ++i)
        {
            if(y[i] < 5)
                c[y[i]]++;
        }

        int count{};
        for(int i{}; i < n; ++i)
            count += countPair(x[i], y, m, c);

        cout << count << '\n';
    }

    return 0;
}