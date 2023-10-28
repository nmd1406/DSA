#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int v{};
        int e{};
        cin >> v >> e;

        vector<set<int>> matrix(v + 1);
        for(int i{}; i < e; ++i)
        {
            int fv{};
            int sv{};
            cin >> fv >> sv;

            matrix[fv].insert(sv);
            matrix[sv].insert(fv);
        }

        for(int i{1}; i <= v; ++i)
        {
            cout << i << ": ";
            if(matrix[i].empty())
                continue;
            
            for(int num : matrix[i])
                cout << num << ' ';

            cout << '\n';
        }
    }

    return 0;
}