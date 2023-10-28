#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> a{};
vector<bool> b{};
vector<vector<int>> ans{};

void backTracking(int i, int n, int k)
{
    for(int j{}; j <= 1; ++j)
    {
        b[i] = j;
        if(i == n - 1)
        {
            int sum{};
            for(int m{}; m < n; ++m)
            {
                if(b[m])
                    sum += a[m];
            }
            if(sum == k)
            {
                vector<int> temp{};
                for(int l{}; l < n; ++l)
                {
                    if(b[l])
                        temp.push_back(a[l]);
                }

                ans.push_back(temp);
            }
        }
        else
            backTracking(i + 1, n, k);
    }
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int n{};
        int k{};
        cin >> n >> k;
        a.resize(n);
        b.resize(n);

        for(int i{}; i < n; ++i)
            cin >> a[i];
            
        sort(a.begin(), a.end());

        backTracking(0, n, k);
        if(ans.empty())
            cout << -1 << '\n';
        else
        {
            sort(ans.begin(), ans.end());
            for(auto& itr : ans)
            {
                cout << '[' << itr[0] << ' ';
                for(int i{1}; i < itr.size() - 1; ++i)
                    cout << itr[i] << ' ';
                cout << itr[itr.size() - 1] << "] ";
            }
            cout << '\n';
        }

        ans.clear();
    }

    return 0;
}