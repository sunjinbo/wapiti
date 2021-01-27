
// 有向图的最短路径

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 定义一个有向图的邻接矩阵
const int MAX = (1<<31)-1;
const int N = 4;
const int GRAPH[N][N] = {{0, 6, 2, MAX}, 
                   {MAX, 0, MAX, 1}, 
                   {MAX, 3, 0, 5},
                   {MAX, MAX, MAX, 0,}
                  };

// 在vector容器中寻找元素是否存在
bool contains(vector<int>& vec, int element)
{
    for (vector<int>::const_iterator iter = vec.cbegin(); iter != vec.cend(); iter++) 
    {
        if (*iter == element)
        {
            return true;
        }
    }

    return false;
}

// 广度优先搜索算法
int bfs() {
    queue<int> q;
    vector<int> visited; // 保存访问过的节点ID

    q.push(0);
    visited.push_back(0);
    int step = 0;

    while (!q.empty())
    {
        int sz = q.size();

        for (int i = 0; i < sz; ++i)
        {
            int cur = q.front();
            q.pop();

            if (cur == N - 1) // 到达最后的节点
            {
                return step;
            }
            else
            {
                for (int j = 0; j < N; ++j)
                {
                    if (!contains(visited, j) && GRAPH[cur][j] != 0 && GRAPH[cur][j] != MAX)
                    {
                        q.push(j);
                        visited.push_back(j);
                    }
                }
            }
        }

        step++;
    }
    
    return -1;
}

// 狄克斯特拉搜索算法
int dijkstra() {
    return 0;
}

int main(int argc, char** argv)
{
    cout << bfs() << endl;
    cout << dijkstra() << endl;

    return 0;
}