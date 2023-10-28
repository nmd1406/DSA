#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n{};
    cin >> n;

    vector<int> v(n);
    for(int i{}; i < n; ++i)
        cin >> v[i];

    vector<vector<int>> steps{};

    for(int i{}; i < n; ++i)
    {
        int temp{v[i]};
        int j{i - 1};
        while(j >= 0 && temp < v[j])
        {
            v[j + 1] = v[j];
            --j;
        }
        v[j + 1] = temp;

        steps.push_back(v);
    }

    for(int i = steps.size() - 1; i >= 0; --i)
    {
        cout << "Buoc " << i << ": ";
        for(int j{}; j <= i; ++j)
            cout << steps[i][j] << ' ';

        cout << '\n';
    }

    return 0;
}