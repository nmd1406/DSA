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
        for(int i{}; i < n; ++i)
            cin >> arr[i];

        int sum{};
        int maxSum{INT_MIN};

        for(int i{}; i < n; ++i)
        {
            sum += arr[i];
            maxSum = max(maxSum, sum);

            if(sum < 0)
                sum = 0;
        }

        cout << maxSum << '\n';
    }

    return 0;
}