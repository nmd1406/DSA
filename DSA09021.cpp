#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n{};
    cin >> n;
    int arr[n + 1][n + 1]{};

    for(int i{1}; i <= n; ++i)
    {
        for(int j{1}; j <= n; ++j)
            cin >> arr[i][j];
    }

    for(int i{1}; i <= n; ++i)
    {
        for(int j{1}; j <= n; ++j)
        {
            if(arr[i][j])
                cout << j << ' ';
        }

        cout << '\n';
    }

    return 0;
}