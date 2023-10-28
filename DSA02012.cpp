#include<bits/stdc++.h>

using namespace std;

int arr[101][101]{};
int n{};
int m{};

long long factorial(int n)
{
    if(n == 0 || n == 1)
        return 1;

    return n * factorial(n - 1);
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        cin >> n >> m;

        for(int i{}; i < n; ++i)
        {
            for(int j{}; j < m; ++j)
                cin >> arr[i][j];
        }

        cout << factorial(n + m - 2) / factorial(n - 1) / factorial(m - 1) << '\n';
    }

    return 0;
}