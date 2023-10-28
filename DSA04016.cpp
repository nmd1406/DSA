#include<iostream>

using namespace std;

void mergeSort(int a[], int b[], int m, int n, int arr[])
{
    int i{};
    int j{};
    int k{};

    while(i < m && j < n)
    {
        if(a[i] < b[j])
        {
            arr[k] = a[i];
            ++i;
            ++k;
        }
        else
        {
            arr[k] = b[j];
            ++j;
            ++k;
        }
    }

    while(i < m)
    {
        arr[k] = a[i];
        ++i;
        ++k;
    }
    while(j < n)
    {
        arr[k] = b[j];
        ++j;
        ++k;
    }
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int m{};
        int n{};
        int k{};
        cin >> m >> n >> k;

        int a[m]{};
        int b[n]{};
        for(int i{}; i < m; ++i)
            cin >> a[i];
        for(int i{}; i < n; ++i)
            cin >> b[i];

        int arr[m + n]{};
        mergeSort(a, b, m, n, arr);

        cout << arr[k - 1] << '\n';
    }

    return 0;
}