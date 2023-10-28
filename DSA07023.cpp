#include<bits/stdc++.h>

using namespace std;

int main()
{
    int test{};
    cin >> test;

    while(test--)
    {
        string str{};
        getline(cin >> ws, str);

        stringstream ss{str};
        string token{};
        stack<string> s{};

        while(ss >> token)
            s.push(token);
        
        while(!s.empty())
        {
            cout << s.top() << ' ';
            s.pop();
        }

        cout << '\n';
    }

    return 0;
}