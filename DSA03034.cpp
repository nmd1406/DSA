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
        int k{};
        cin >> n >> m >> k;

        int a[n]{};
        int b[m]{};
        int c[k]{};

        for(int i{}; i < n; ++i)
            cin >> a[i];
        
        for(int i{}; i < m; ++i)
            cin >> b[i];

        for(int i{}; i < k; ++i)
            cin >> c[i];

        int x{};
        int y{};
        int z{};
        bool isFound{false};
        while(x < n && y < m && z < k)
        {
            if(a[x] == b[y] && b[y] == c[z])
            {
                isFound = true;
                cout << a[x] << ' ';

                ++x;
                ++y;
                ++z;
            }
            else
            {
                if(a[x] < b[y])
                    ++x;
                if(b[y] < c[z])
                    ++y;
                if(c[z] < a[x])
                    ++z;
            }
        }

        if(!isFound)
            cout << "NO\n";
        else
            cout << '\n';
    }

    return 0;
}