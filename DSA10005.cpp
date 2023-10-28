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

        int degVao[1005]{};
        int degRa[1005]{};

        while(m--)
        {
            int fv, sv;
            cin >> fv >> sv;
            ++degVao[sv];
            ++degRa[fv];
        }

        int count{};
        bool flag{true};
        for(int i{1}; i <= n; ++i)
        {
            count += (abs(degVao[i] - degRa[i]) == 1);
            if(count > 2 || abs(degVao[i] - degRa[i]) > 1 || !degVao[i] || !degRa[i])
            {
                flag = false;
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