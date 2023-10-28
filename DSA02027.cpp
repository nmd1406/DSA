#include<bits/stdc++.h>

using namespace std;

int n{};
int c[16][16]{};
int path[16]{};
bool isVisited[16]{};
int cost{};
int minCost{INT_MAX};

void backTrack(int i = 2)
{
    for(int j{2}; j <= n; ++j)
    {
        if(!isVisited[j])
        {
            path[i] = j;
            isVisited[j] = true;
            cost += c[path[i - 1]][path[i]];

            if(i == n)
            {
                int totalCost{cost + c[path[n]][path[1]]};
                minCost = min(minCost, totalCost);
            }
            else if(cost + (n - i + 1) * INT_MAX < minCost)
                backTrack(i + 1);

            cost -= c[path[i - 1]][path[i]];
            isVisited[j] = false;
        }
    }
}

int main()
{
    cin >> n;
    path[1] = 1;

    for(int i{1}; i <= n; ++i)
    {
        for(int j{1}; j <= n; ++j)
            cin >> c[i][j];
    }

    backTrack();
    cout << minCost << '\n';

    return 0;
}