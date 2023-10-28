#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test{};
    cin >> test;
    const int mod = 1e9 + 7;

    while(test--)
    {
        int n{};
        cin >> n;
        priority_queue<long long, vector<long long>, greater<long long>> pq{};
        for(int i{}; i < n; ++i)
        {
            long long num{};
            cin >> num;
            pq.push(num);
        }

        long long ans{};
        while(pq.size() >= 2)
        {
            long long min1{pq.top()};
            pq.pop();
            long long min2{pq.top()};
            pq.pop();

            long long sum{(min1 + min2) % mod};
            ans += sum;
            ans %= mod;
            pq.push(sum);
        }

        cout << ans << '\n';
    }

    return 0;
}