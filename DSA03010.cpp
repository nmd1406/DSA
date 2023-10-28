#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int n{};
        cin >> n;

        priority_queue<int, vector<int>, greater<int>> pq{};
        for(int i{}; i < n; ++i)
        {
            int x{};
            cin >> x;
            pq.push(x);
        }

        long long ans{};
        while(pq.size() >= 2)
        {
            int min1{pq.top()};
            pq.pop();
            int min2{pq.top()};
            pq.pop();

            int sum{min1 + min2};
            ans += sum;
            pq.push(sum);
        }

        cout << ans << '\n';
    }

    return 0;
}