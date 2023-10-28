#include<iostream>

using namespace std;

char c{};
int k{};
char arr[100]{};

void backTracking(int i = 1, char ch = 'A')
{
    for(char j{ch}; j <= c; ++j)
    {
        arr[i] = j;
        if(i == k)
        {
            for(int h{1}; h <= k; ++h)
                cout << arr[h];
            cout << '\n';
        }
        else
            backTracking(i + 1, j);
    }
}

int main()
{
    cin >> c >> k;
    backTracking();

    return 0;
}