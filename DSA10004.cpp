#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int n, m;
        cin >> n >> m;

        int deg[n + 5]{};
        while(m--)
        {
            int fv, sv;
            cin >> fv >> sv;
            ++deg[fv];
            ++deg[sv];
        }

        int count{};
        for(int i{1}; i <= n; ++i)
            count += (deg[i] % 2 == 1);

        if(!count)
            cout << "2\n";
        else if(count == 2)
            cout << "1\n";
        else
            cout << "0\n";
    }

    return 0;
}