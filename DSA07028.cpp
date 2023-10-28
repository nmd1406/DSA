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

        stack<int> s{};
        s.push(0);
        int arr[n + 1]{};
        for(int i{1}; i <= n; ++i)
        {
            cin >> arr[i];

            while(s.size() > 1 && arr[s.top()] <= arr[i])
                s.pop();

            cout << i - s.top() << ' ';
            s.push(i);
        }

        cout << '\n';
    }

    return 0;
}