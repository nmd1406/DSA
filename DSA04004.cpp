#include<iostream>
#include<cmath>

using namespace std;

int gapDoi(int n, long long k)
{
    long long x = pow(2, n - 1);
    if(k == x)
        return n;
    if(k < x)
        return gapDoi(n - 1, k);

    return gapDoi(n - 1, k - x);
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int n{};
        long long k{};
        cin >> n >> k;
        cout << gapDoi(n, k) << '\n';
    }

    return 0;
}