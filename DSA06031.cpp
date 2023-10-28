#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int n{};
        int k{};
        cin >> n >> k;

        int arr[n]{};
        for(int i{}; i < n; ++i)
            cin >> arr[i];

        multiset<int> s{};
        for(int i{}; i < k; ++i)
            s.insert(arr[i]);

        for(int i{k}; i < n; ++i)
        {
            cout << *s.rbegin() << ' ';
            s.erase(s.find(arr[i - k]));
            s.insert(arr[i]);
        }

        cout << *s.rbegin() << '\n';
    }

    return 0;
}