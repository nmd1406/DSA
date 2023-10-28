#include<iostream>
#include<algorithm>

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
        for(int j{i + 1}; j < n; ++j)
        {
            if(arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }

        cout << "Buoc " << i + 1 << ": ";
        for(int k{}; k < n; ++k)
            cout << arr[k] << ' ';
        cout << '\n';
    }

    return 0;
}