#include<iostream>

void thapHaNoi(int n, char dau = 'A', char giua = 'B', char cuoi = 'C')
{
    if(n == 1)
    {
        std::cout << dau << " -> " << cuoi << '\n';
        return;
    }

    thapHaNoi(n - 1, dau, cuoi, giua);
    std::cout << dau << " -> " << cuoi << '\n';
    thapHaNoi(n - 1, giua, dau, cuoi);
}

int main()
{
    int n{};
    std::cin >> n;

    thapHaNoi(n);
    return 0;
}