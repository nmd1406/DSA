#include<iostream>
#include<stack>
#include<vector>

std::stack<std::vector<int>> s{};

void backTracking(std::vector<int> v, int n)
{
    if(n)
    {
        s.push(v);
        for(int i{}; i < n - 1; ++i)
            v[i] += v[i + 1];

        backTracking(v, n - 1);
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
        std::vector<int> v{};
        for(int i{}; i < n; ++i)
        {
            int num{};
            std::cin >> num;
            v.push_back(num);
        }

        backTracking(v, n);
    
        int size{1};
        while(!s.empty())
        {
            std::vector<int> temp{s.top()};
            s.pop();

            if(size == 1)
            {
                std::cout << '[' << temp[0] << "] ";
                ++size;
            }
            else
            {
                std::cout << '[';
                for(int i{}; i < size - 1; ++i)
                    std::cout << temp[i] << ' ';

                std::cout << temp[size - 1];
                ++size;
                std::cout << "] ";    
            }
        }
        std::cout << '\n';
    }

    return 0;
}