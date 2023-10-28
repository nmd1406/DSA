#include<bits/stdc++.h>

using namespace std;

bool nguyenAm(char c)
{
    return (c == 'A' || c == 'E');
}

bool check(string str)
{
    for(int i{1}; i < str.length() - 1; ++i)
    {
        if(nguyenAm(str[i]))
        {
            if(!nguyenAm(str[i - 1]) && !nguyenAm(str[i + 1]))
                return false;
        }
    }

    return true;
}

int main()
{
    char c{};
    cin >> c;

    string str{"ABC"};
    for(char i{'D'}; i <= c; ++i)
        str += i;

    if(check(str))
        cout << str << '\n';

    while(next_permutation(str.begin(), str.end()))
    {
        if(check(str))
            cout << str << '\n';
    }

    return 0;
}