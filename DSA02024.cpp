#include<bits/stdc++.h>

using namespace std;

vector<string> ans{};
vector<int> v{};
int arr[30]{};

void save()
{
    string str{};
    for(int num : v)
        str += to_string(num) + ' ';

    ans.push_back(str);
}

void backTrack(int n, int i = 0)
{
    for(int j{i + 1}; j <= n; ++j)
    {
        if(arr[i] < arr[j])
        {
            v.push_back(arr[j]);
            if(v.size() > 1)
                save();
            backTrack(n, j);
            v.pop_back();
        }
    }
}

int main()
{
    int n{};
    cin >> n;
    for(int i{1}; i <= n; ++i)
        cin >> arr[i];

    arr[0] = INT_MIN;

    backTrack(n);

    sort(ans.begin(), ans.end());
    for(const auto& ele : ans)
        cout << ele << '\n';

    return 0;
}