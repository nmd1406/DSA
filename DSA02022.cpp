#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<string> day{};
    day.push_back("02");
    day.push_back("20");
    day.push_back("22");

    vector<string> year{};
    year.push_back("2000");
    year.push_back("2002");
    year.push_back("2020");
    year.push_back("2022");
    year.push_back("2200");
    year.push_back("2202");
    year.push_back("2220");
    year.push_back("2222");


    for(auto i : day)
    {
        for(auto j : year)
            cout << i << "/02/" << j << '\n';
    }
    return 0;
}