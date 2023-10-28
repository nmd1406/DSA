#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n{};
    cin >> n;

    int arr[n]{};
    for(int i{}; i < n; ++i)
        cin >> arr[i];

    vector<int> dec{};
    vector<int> inc{};
    for(int i{}; i < n; ++i)
    {
        if(i % 2 == 0)
            inc.push_back(arr[i]);
        else
            dec.push_back(arr[i]);
    }

    sort(dec.rbegin(), dec.rend());
    sort(inc.begin(), inc.end());

    int j{};
    int k{};
    for(int i{}; i < n; ++i)
    {
        if(i % 2 == 0)
            cout << inc[j++] << ' ';
        else
            cout << dec[k++] << ' ';
    }

    return 0;
}