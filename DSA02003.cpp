#include<bits/stdc++.h>

using namespace std;

int n{};
int arr[12][12]{};
bool check{false};
string s{};

void backTracking(int i, int j, string s)
{
    if(i == n - 1 && j == n - 1)
    {
        cout << s << ' ';
        check = true;
        return;
    }
    if(arr[i + 1][j])
        backTracking(i + 1, j, s + 'D');
    if(arr[i][j + 1])
        backTracking(i, j + 1, s + 'R');
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        cin >> n;
        check = false;
        

        for(int i{}; i < n; ++i)
        {
            for(int j{}; j < n; ++j)
                cin >> arr[i][j];
        }

        if(!arr[0][0])
            cout << -1 << '\n';
        else
        {
            backTracking(0, 0, "");
            if(!check)
                cout << -1;
        }

        cout << '\n';
    }

    return 0;
}