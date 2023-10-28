#include<bits/stdc++.h>

using namespace std;

bool check(string& str)
{
    int i = str.length() - 2;
    while(i >= 0 && str[i + 1] <= str[i])
        --i;

    if(i < 0)
        return true;
    else
        return false;
}

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        int n{};
        string str{};
        cin >> n >> str;

        cout << n << ' ';

        string temp{str};
        next_permutation(temp.begin(), temp.end());
        
        if(check(str))
            cout << "BIGGEST\n";
        else
            cout << temp << '\n';

    }

    return 0;
}