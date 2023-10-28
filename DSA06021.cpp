#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int n{};
        int x{};
        cin >> n >> x;

        vector<int> v(n);
        for(int i{}; i < n; ++i)
            cin >> v[i];

        auto itr{find(v.begin(), v.end(), x)};
        cout << itr - v.begin() + 1 << '\n';
    }

    return 0;
}