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

        int arr[n]{};
        for(int i{}; i < n; ++i)
            cin >> arr[i];

        stack<int> s{};
        int res[n]{};
        for(int i{n - 1}; i >= 0; --i)
        {
            while(!s.empty() && s.top() <= arr[i])
                s.pop();
            if(s.empty())
                res[i] = -1;
            else
                res[i] = s.top();

            s.push(arr[i]);
        }

        for(int i{}; i < n; ++i)
            cout << res[i] << ' ';

        cout << '\n';
    }

    return 0;
}