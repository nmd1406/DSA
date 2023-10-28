#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n{};
    cin >> n;
    int arr[n + 1][n + 1]{};

    for(int i{1}; i <= n; ++i)
    {
        string str{};
        getline(cin >> ws, str);
        stringstream ss{str};

        while(ss >> str)
        {
            int sv{stoi(str)};
            arr[i][sv] = 1;
        }
    }

    for(int i{1}; i <= n; ++i)
    {
        for(int j{1}; j <= n; ++j)
            cout << arr[i][j] << ' ';

        cout << '\n';
    }

    return 0;
}