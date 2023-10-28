#include<iostream>
#include<set>

void tachChuSo(long long num, std::set<long long>& s)
{
    while(num)
    {
        s.insert(num % 10);
        num /= 10;
    }
}

int main()
{
    int test{};
    std::cin >> test;

    while(test--)
    {
        int n{};
        std::cin >> n;

        long long arr[n]{};
        for(int i{}; i < n; ++i)
            std::cin >> arr[i];

        std::set<long long> s{};
        for(int i{}; i < n; ++i)
            tachChuSo(arr[i], s);
        
        for(long long i : s)
            std::cout << i << ' ';

        std::cout << '\n';
    }

    return 0;
}