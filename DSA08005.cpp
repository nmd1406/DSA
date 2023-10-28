#include<bits/stdc++.h>

using namespace std;

void nhiPhan(int n)
{
    queue<string> q{};
    q.push("1");

    while(n--)
    {
        string s{q.front()};
        q.pop();
        cout << s << ' ';
        q.push(s + "0");
        q.push(s + "1");
    }

    cout << '\n';
}   

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int n{};
        cin >> n;

        nhiPhan(n);
    }

    return 0;
}