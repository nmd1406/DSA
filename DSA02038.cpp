#include<bits/stdc++.h>

using namespace std;

int n, k;
int arr[16];
int res[16];

void print()
{
    for(int i{1}; i <= k; ++i)
        cout << arr[res[i]] << ' ';

    cout << '\n';
}

void backTrack(int i)
{
    for(int j{res[i - 1] + 1}; j <= n - k + i; ++j)
    {
        res[i] = j;
        if(i == k)
            print();
        else
            backTrack(i + 1);
    }

}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        cin >> n >> k;
        for(int i{1}; i <= n; ++i)
            cin >> arr[i];

        sort(arr + 1, arr + 1 + n);

        backTrack(1);
    }   

    return 0;
}