#include<bits/stdc++.h>

using namespace std;

void solve(int n)
{
    queue<string> q{};
    q.push("6");
    q.push("8");

    vector<string> nums{};
    while(true)
    {
        string temp{q.front()};
        q.pop();
        nums.push_back(temp);

        if(temp.length() <= n - 1)
        {
            q.push(temp + "6");
            q.push(temp + "8");
        }
        else
            break;
    }

    while(!q.empty())
    {
        nums.push_back(q.front());
        q.pop();
    }

    cout << nums.size() << '\n';
    for(int i = nums.size() - 1; i >= 0; --i)
        cout << nums[i] << ' ';

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

        solve(n);
    }

    return 0;
}