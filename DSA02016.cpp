#include<iostream>

using namespace std;

int kq[100]{};
bool cot[100]{};
bool xuoi[100]{};
bool nguoc[100]{};

void nQueen(int i, int n, int& count)
{
    for(int j{1}; j <= n; ++j)
    {
        if(cot[j] == 0 && xuoi[i - j + n] == 0 && nguoc[i + j - 1] == 0)
        {
            kq[i] = j;
            cot[j] = xuoi[i - j + n] = nguoc[i + j - 1] = 1;
            if(i == n)
                ++count;
            else
                nQueen(i + 1, n, count);
            cot[j] = xuoi[i - j + n] = nguoc[i + j - 1] = 0;     
        }
    }
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int n{};
        cin >> n;

        int count{};
        nQueen(1, n, count);

        cout << count << '\n';
    }

    return 0;
}