#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n{};
    cin >> n;
    cin.ignore();

    vector<vector<int>> arr(n + 1);

    for(int i{1}; i <= n; ++i)
    {
        string input{};
        getline(cin >> ws, input);
        stringstream ss{input};
        while(ss >> input)
            arr[i].push_back(stoi(input));
    }

    for(int i{1}; i <= n; ++i)
    {
        sort(arr[i].begin(), arr[i].end());
        for(auto j : arr[i])
        {
            if(i < j)
                cout << i << ' ' << j << '\n';
        }
    }

    return 0;
}