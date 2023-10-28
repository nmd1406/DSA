#include<bits/stdc++.h>

using namespace std;

struct Line
{
    int start{};
    int finish{};
};

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int n{};
        cin >> n;

        Line l[n]{};
        for(int i{}; i < n; ++i)
            cin >> l[i].start >> l[i].finish;

        sort(l, l + n, [](Line& a, Line& b)
                        {
                            return a.finish < b.finish;
                        });

        int count{1};
        int i{};
        for(int j{1}; j < n; ++j)
        {
            if(l[j].start >= l[i].finish)
            {
                ++count;
                i = j;
            }
        }

        cout << count << '\n';
    }

    return 0;
}