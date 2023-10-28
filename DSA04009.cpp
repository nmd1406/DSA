#include<bits/stdc++.h>

using namespace std;

int n{};
const long long mod = 1e9 + 7;

struct Matrix
{
    long long arr[11][11]{};
};

Matrix operator*(Matrix a, Matrix b)
{
    Matrix res;

    for(int i{}; i < n; ++i)
    {
        for(int j{}; j < n; ++j)
        {
            res.arr[i][j] = 0;
            for(int k{}; k < n; ++k)
            {
                res.arr[i][j] += (a.arr[i][k] * b.arr[k][j]) % mod;
                res.arr[i][j] %= mod;
            }
        }
    }

    return res;
}

Matrix matrixPow(Matrix a, int k)
{
    if(k == 1)
        return a;

    Matrix temp = matrixPow(a, k / 2);
    if(k % 2 == 0)
        return temp * temp;

    return a * temp * temp;
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int k{};
        cin >> n >> k;

        Matrix a{};
        for(int i{}; i < n; ++i)
        {
            for(int j{}; j < n; ++j)
                cin >> a.arr[i][j];
        }

        Matrix res{matrixPow(a, k)};

        for(int i{}; i < n; ++i)
        {
            for(int j{}; j < n; ++j)
                cout << res.arr[i][j] << ' ';

            cout << '\n';
        }
    }

    return 0;
}