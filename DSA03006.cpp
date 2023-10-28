#include<bits/stdc++.h>

using namespace std;

bool check(int a[], int b[], int n)
{
    for(int i{}; i < n; ++i)
    {
        if(a[i] != b[i] && a[i] != b[n - i - 1])
            return false;
    }

    return true;
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int n{};
        cin >> n;

        int a[n]{};
        int b[n]{};

        for(int i{}; i < n; ++i)
        {
            cin >> a[i];
            b[i] = a[i];
        }

        sort(b, b + n);
        
        if(check(a, b, n))
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}