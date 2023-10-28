#include<bits/stdc++.h>

using namespace std;

long long merge(long long arr[], int l, int mid, int r)
{
    int i{};
    int j{};
    int k{l};
    int size1{mid - l + 1};
    int size2{r - mid};

    long long left[size1];
    long long right[size2];

    for(int i{}; i < size1; ++i)
        left[i] = arr[l + i];
    for(int i{}; i < size2; ++i)
        right[i] = arr[mid + i + 1];

    long long count{};
    i = j = 0;
    while(i < size1 && j < size2)
    {
        if(left[i] <= right[j])
            arr[k++] = left[i++];
        else
        {
            count = count + size1 - i;
            arr[k++] = right[j++];
        }
    }

    while(i < size1)
        arr[k++] = left[i++];
    while(j < size2)
        arr[k++] = right[j++];

    return count;
}   

long long mergeSort(long long arr[], int l, int r)
{
    long long count{};
    if(l < r)
    {
        int mid{l + (r - l) / 2};
        count += mergeSort(arr, l, mid);
        count += mergeSort(arr, mid + 1, r);
        count += merge(arr, l, mid, r);
    }

    return count;
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int n{};
        cin >> n;
        long long arr[n]{};
        for(int i{}; i < n; ++i)
            cin >> arr[i];

        cout << mergeSort(arr, 0, n - 1) << '\n';
    }

    return 0;
}