#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int n{};
        long long k{};
        cin >> n >> k;

        long long arr[n]{};
        for(int i{}; i < n; ++i)
            cin >> arr[i];

        long long count{};
        unordered_map<long long, long long> m{};
        for(int i{}; i < n; ++i)
        {
            auto itr{m.find(k - arr[i])};
            if(itr != m.end())
                count += m[k - arr[i]];

            ++m[arr[i]];
        }
        cout << count << '\n';
    }

    return 0;
}