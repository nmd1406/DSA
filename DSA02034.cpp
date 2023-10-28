#include<bits/stdc++.h>

using namespace std;

bool check(int arr[], int n)
{
    for(int i{}; i < n - 1; ++i)
    {
        if(abs(arr[i + 1] - arr[i]) == 1)
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
        int arr[n]{};

        for(int i{}; i < n; ++i)
            arr[i] = i + 1;

        do
        {
            if(check(arr, n))
            {
                for(int i{}; i < n; ++i)
                    cout << arr[i];

                cout << '\n';
            }
        }
        while(next_permutation(arr, arr + n));
    }

    return 0;
}