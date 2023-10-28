#include<bits/stdc++.h>

using namespace std;

long long solve(long long arr[], int n)
{
    int left[n]{};
    int right[n]{};
    stack<int> s{};

    s.push(-1);

    for(int i{}; i < n; ++i)
    {
        while(s.size() > 1 && arr[s.top()] >= arr[i])
            s.pop();

        left[i] = s.top() + 1;
        s.push(i);
    }

    while(!s.empty())
        s.pop();

    s.push(n);

    for(int i{n - 1}; i >= 0; --i)
    {
        while(s.size() > 1 && arr[s.top()] >= arr[i])
            s.pop();
        
        right[i] = s.top() - 1;
        s.push(i);
    }

    long long res{};
    for(int i{}; i < n; ++i)
        res = max(res, 1ll * arr[i] * (right[i] - left[i] + 1));

    return res;
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int n{};
        cin >> n;

        long long arr[n]{};
        for(int i{}; i < n; ++i)
            cin >> arr[i];

        cout << solve(arr, n) << '\n';
    }

    return 0;
}