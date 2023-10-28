#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        string str{};
        cin >> str;

        int arr[200]{};
        int maxCount{};
        for(int i{}; i < str.length(); ++i)
        {
            arr[str[i]]++;
            maxCount = max(maxCount, arr[str[i]]);
        }

        if(str.length() - maxCount >= maxCount - 1)
            cout << 1 << '\n';
        else
            cout << -1 << '\n';
    }

    return 0;
}