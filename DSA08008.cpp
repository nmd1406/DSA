#include<bits/stdc++.h>

using namespace std;

long long bdn2(int n)
{
    queue<long long> q{};
    q.push(1ll);

    while(true)
    {
        long long temp{q.front()};
        q.pop();

        if(temp % n == 0)
            return temp;

        q.push(temp * 10);
        q.push(temp * 10 + 1);
    }
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int n{};
        cin >> n;

        cout << bdn2(n) << '\n';
    }

    return 0;
}