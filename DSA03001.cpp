#include<iostream>

using namespace std;

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int n{};
        cin >> n;
        int coin[]{1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
        int count{};

        int i{9};
        while (n)
        {
            if(coin[i] <= n)
            {
                n -= coin[i];
                ++count;
            }
            else
                --i;
        }

        cout << count << '\n';
    }

    return 0;
}