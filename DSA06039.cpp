#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int n{};
        cin >> n;

        int arr[n]{};
        unordered_map<int, int> m{};
        bool check{false};
        for(int i{}; i < n; ++i)
        {
            cin >> arr[i];
            m[arr[i]]++;
        }

        for(int i{}; i < n; ++i)
        {
            if(m[arr[i]] > 1)
            {
                check = true;
                cout << arr[i];
                break;
            }
        }

        if(check)
            cout << '\n';
        else
            cout << "NO\n";
    }

    return 0;
}