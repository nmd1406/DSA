#include<iostream>

using namespace std;

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int n{};
        int s{};
        int m{};
        cin >> n >> s >> m;

        if(m > n || n * 6 < m * 7)
            cout << -1 << '\n';
        else
        {
            int count{};
            int total{m * s};
            if(total % n == 0)
                cout << total / n << '\n';
            else
                cout << total / n + 1 << '\n';
        }
    }

    return 0;
}