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
        bool isSwap{false};
        for(int j{}; j < n - i - 1; ++j)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSwap = true;
            }
        }

        if(!isSwap)
            break;
        cout << "Buoc " << i + 1 << ": ";
        for(int k{}; k < n; ++k)
            cout << arr[k] << ' ';
        cout << '\n';
    }

    return 0;
}