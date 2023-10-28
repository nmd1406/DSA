#include<bits/stdc++.h>

using namespace std;

int minSum(string str1, string str2)
{
    for(int i{}; i < str1.size(); ++i)
    {
        if(str1[i] == '6')
            str1[i] = '5';
    }
    for(int i{}; i < str2.size(); ++i)
    {
        if(str2[i] == '6')
            str2[i] = '5';
    }

    return stoi(str1) + stoi(str2);
}

int maxSum(string str1, string str2)
{
    for(int i{}; i < str1.size(); ++i)
    {
        if(str1[i] == '5')
            str1[i] = '6';
    }
    for(int i{}; i < str2.size(); ++i)
    {
        if(str2[i] == '5')
            str2[i] = '6';
    }

    return stoi(str1) + stoi(str2);
}

int main()
{
    string str1{};
    string str2{};
    cin >> str1 >> str2;

    cout << minSum(str1, str2) << ' ' << maxSum(str1, str2);

    return 0;
}