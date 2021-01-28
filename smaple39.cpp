// dijstra搜索

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 定义一个有向图的邻接矩阵
const int MAX = (1<<31)-1;
const int N = 5;
const int NA = -1;
const int GRAPH[N][N] = {
    {0, 4, MAX, 2, MAX}, 
    {4, 0, 4, 1, MAX}, 
    {MAX, 4, 0, 1, 3},
    {2, 1, 1, 0, 7},
    {MAX, MAX, 3, 7, 0}
};

// 判断数据中是否还有未处理的节点
bool isNotEmpty(int n, int arr[])
{
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] != NA)
        {
            return true;
        }
    }

    return false;
}

// 狄克斯特拉搜索算法
int dijkstra() {
    int S[N];
    int U[N];

    // 初始化S和U
    for (int i = 0; i < N; ++i)
    {
        S[i] = ((i == 0) ? 0 : NA);
        U[i] = ((i == 0) ? NA : GRAPH[0][i]);
    }

    // 核心算法
    while (isNotEmpty(N, U))
    {
        // 找到最临近的节点shortest
        int shortest = MAX;
        int shortestIndex = -1;
        for (int i = 0; i < N; ++i)
        {
            if (U[i] != NA)
            {
                if (U[i] < shortest)
                {
                    shortest = U[i];
                    shortestIndex = i;
                }
            }
        }

        // 将该shortest节点放置到S集合中
        if (shortestIndex >= 0 && shortestIndex < N)
        {
            S[shortestIndex] = U[shortestIndex];
            U[shortestIndex] = NA;
        }
        
        // 根据shortest节点，重新刷新集合U
        for (int i = 0; i < N; ++i)
        {
            if (U[i] != NA) // 找到U集合里残余的节点
            {
                if (GRAPH[shortestIndex][i] != MAX) // 如果shortest节点与该节点有通路
                {
                    if (GRAPH[shortestIndex][i] + S[shortestIndex] < U[i])
                    {
                        U[i] = GRAPH[shortestIndex][i] + S[shortestIndex];
                    }
                }
            }
        }
    }

    return S[N-1];
}

int main(int argc, char** argv)
{
    cout << dijkstra() << endl;

    return 0;
}