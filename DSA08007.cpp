#include<bits/stdc++.h>

using namespace std;

int bdn1(long long n)
{
    vector<long long> v{};
    long long num{1};
    v.push_back(num);

    while(num * 10 <= n)
    {
        int x = v.size();
        num *= 10;
        v.push_back(num);

        for(int i{}; i < x; ++i)
            v.push_back(num + v[i]);
    }
    
    int res = upper_bound(v.begin(), v.end(), n) - v.begin();

    return res;
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        long long n{};
        cin >> n;

        cout << bdn1(n) << '\n';
    }

    return 0;
}