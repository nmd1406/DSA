#include<bits/stdc++.h>

using namespace std;

int n;
int arr[16];
vector<vector<int>> res;
vector<int> v;

void backTracking(int i, int sum = 0)
{
    if(sum % 2 == 1)
        res.push_back(v);
    if(i > n)
        return;

    for(int j{i}; j <= n; ++j)
    {
        v.push_back(arr[j]);
        backTracking(j + 1, sum + arr[j]);
        v.pop_back();
    }
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        cin >> n;
        for(int i{1}; i <= n; ++i)
            cin >> arr[i];

        sort(arr + 1, arr + n + 1, greater<int>());

        backTracking(1);
        sort(res.begin(), res.end());
        for(auto itr : res)
        {
            for(auto num : itr)
                cout << num << ' ';

            cout << '\n';
        }

        v.clear();
        res.clear();
    }

    return 0;
}