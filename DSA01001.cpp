#include<iostream>
#include<string>

int main()
{
    int testCase{};
    std::cin >> testCase;

    while(testCase--)
    {
        std::string str{};
        std::cin >> str;

        int i = str.length() - 1;

        while(i >= 0 && str[i] == '1')
        {
            str[i] = '0';
            --i;
        }

        if(i >= 0)
            str[i] = '1';
        std::cout << str << '\n';
    }
}