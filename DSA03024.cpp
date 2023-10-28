#include<bits/stdc++.h>

using namespace std;

struct Task
{
    int start{};
    int finish{};
};

bool cmp(Task& a, Task& b)
{
    return a.finish < b.finish;
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int n{};
        cin >> n;

        Task t[n]{};
        for(int i{}; i < n; ++i)
        {
            cin >> t[i].start;
            cin >> t[i].finish;
        }

        sort(t, t + n, cmp);
        int count{1};
        int i{};

        for(int j{1}; j < n; ++j)
        {
            if(t[j].start >= t[i].finish)
            {
                i = j;
                ++count;
            }
        }

        cout << count << '\n';
    }

    return 0;
}