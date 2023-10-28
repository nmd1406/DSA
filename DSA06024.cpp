#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n{};
    cin >> n;
    int arr[n]{};
    for(int i{}; i < n; ++i)
        cin >> arr[i];

    for(int i{}; i < n - 1; ++i)
    {
        int minPos{i};
        for(int j{i + 1}; j < n; ++j)
        {
            if(arr[j] < arr[minPos])
                minPos = j;
        }

        swap(arr[i], arr[minPos]);
        cout << "Buoc " << i + 1 << ": ";
        for(int k{}; k < n; ++k)
            cout << arr[k] << ' ';
        cout << '\n';
    }

    return 0;
}