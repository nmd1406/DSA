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

    for(int i{}; i < n - 1; ++i)
    {
        int minPos{i};
        for(int j{i + 1}; j < n; ++j)
        {
            if(v[j] < v[minPos])
                minPos = j;
        }

        swap(v[i], v[minPos]);
        steps.push_back(v);
    }

    for(int i = steps.size() - 1; i >= 0; --i)
    {
        cout << "Buoc " << i + 1 << ": ";
        for(int j{}; j < n; ++j)
            cout << steps[i][j] << ' ';
        
        cout << '\n';
    }

    return 0;
}