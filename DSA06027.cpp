#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int n{};
        cin >> n;
        
        vector<int> v(n);
        vector<vector<int>> steps{};
        for(int i{}; i < n; ++i)
            cin >> v[i];

        for(int i{}; i < n - 1; ++i)
        {
            for(int j{i + 1}; j < n; ++j)
            {
                if(v[i] > v[j])
                    swap(v[i], v[j]);
            }
            steps.push_back(v);
        }

        for(int i = steps.size() - 1; i >= 0; --i)
        {
            cout << "Buoc " << i + 1 << ": ";
            for(int j{}; j < n; ++j)
                cout << steps[i][j] << ' ';

            cout << '\n';
        }
    }

    return 0;
}