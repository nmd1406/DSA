#include<iostream>
#include<queue>

int main()
{
    int test{};
    std::cin >> test;

    while(test--)
    {
        int n{};
        int k{};
        std::cin >> n >> k;

        std::priority_queue<int> pq{};
        for(int i{}; i < n; ++i)
        {
            int temp{};
            std::cin >> temp;
            pq.push(temp);
        }

        for(int i{}; i < k; ++i)
        {
            std::cout << pq.top() << ' ';
            pq.pop();
        }

        std::cout << '\n';
    }

    return 0;
}