// dijstra搜索

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

// 从vector容器中删除指定的元素


// 狄克斯特拉搜索算法
int dijkstra() {
    return 0;
}

int main(int argc, char** argv)
{
    cout << dijkstra() << endl;

    return 0;
}