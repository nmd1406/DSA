#include<iostream>
#include<string>

void gen(std::string& str)
{
    int i = str.size() - 1;
    while(i >= 0 && str[i] == '0')
    {
        str[i] = '1';
        --i;
    }
    if(i >= 0)
        str[i] = '0';
    // else
    // {
    //     for(int j{}; j < str.size(); ++j)
    //         str[j] = '1';
    // }
}

int main()
{
    int test{};
    std::cin >> test;

    while(test--)
    {
        std::string str{};
        std::cin >> str;

        gen(str);
        std::cout << str << '\n';
    }

    return 0;
}