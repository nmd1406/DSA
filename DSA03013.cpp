#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int d{};
        string str{};
        cin >> d >> str;

        int arr[200]{};
        int maxCount{};
        for(int i{}; i < str.length(); ++i)
        {
            arr[str[i]]++;
            maxCount = max(maxCount, arr[str[i]]);
        }

        if((maxCount - 1) * d < str.length())
            cout << 1 << '\n';
        else
            cout << -1 << '\n';
    }

    return 0;
}