#include<bits/stdc++.h>

using namespace std;

int atm[35];
int n, s;
bool stop{false};

void backTrack(int idx, int cur = 0, int count = 0)
{   
    if(stop)
        return;
    if(cur > s)
        return;
    if(cur == s)
    {
        cout << count << '\n';
        stop = true;
        return;
    }

    for(int j{idx}; j <= n; ++j)
        backTrack(j + 1, cur + atm[j], count + 1);
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        stop = false;
        cin >> n >> s;

        for(int i{1}; i <= n; ++i)
            cin >> atm[i];

        sort(atm + 1, atm + n + 1, greater<int>());
        backTrack(1);

        if(!stop)
            cout << "-1\n";
    }

    return 0;
}