#include<iostream>
#include<algorithm>
#include<map>

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
        map<int, int> m{};
        for(int i{}; i < n; ++i)
        {
            cin >> arr[i];
            ++m[arr[i]];
        }

        sort(arr, arr + n);
        int min{arr[0]};
        int max{arr[n - 1]};

        int count{};
        for(int i{min}; i <= max; ++i)
        {
            if(m[i] == 0)
                ++count;
        }

        cout << count << '\n';
    }

    return 0;
}