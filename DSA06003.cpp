#include<iostream>
#include<algorithm>

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

        int count{};
        for(int i{}; i < n - 1; ++i)
        {
            int minIdx{i};
            for(int j{i + 1}; j < n; ++j)
            {
                if(arr[j] < arr[minIdx])
                    minIdx = j;
            }

            if(minIdx != i)
            {
                swap(arr[i], arr[minIdx]);
                ++count;            
            }
        }

        cout << count << '\n';
    }

    return 0;
}
