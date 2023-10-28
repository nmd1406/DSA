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
        unordered_map<int, int> m{};
        for(int i{}; i < n; ++i)
        {
            cin >> arr[i];
            m[arr[i]]++;
        }
        vector<pair<int, int>> v{};

        for(auto& itr : m)
            v.push_back(itr);

        sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b)
                                {
                                    return a.second > b.second; 
                                });

        if(v[0].second > n / 2)
            cout << v[0].first << '\n';
        else
            cout << "NO\n";
    }

    return 0;
}