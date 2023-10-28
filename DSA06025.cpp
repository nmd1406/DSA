#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n{};
    cin >> n;
    int arr[n]{};
    for(int i{}; i < n; ++i)
        cin >> arr[i];

    for(int i{}; i < n; ++i)
    {
        int temp{arr[i]};
        int j{i - 1};
        while(j >= 0 && temp < arr[j])
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = temp;

        cout << "Buoc " << i << ": ";
        for(int k{}; k <= i; ++k)
            cout << arr[k] << ' ';
        cout << '\n';
    }

    return 0;
}