#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// 定义无穷大
#define INF numeric_limits<int>::max()

// 结点结构体
struct Node
{
    int index;                           // 结点编号
    int dist;                            // 起点到该结点的最短路径长度
    bool visited;                        // 结点是否已经访问过
    vector<pair<Node *, int>> neighbors; // 该结点的邻居结点和对应的边权值
};

// 迪杰斯特拉算法的实现
void dijkstra(vector<Node *> &graph, int start)
{
    // 初始化结点列表
    for (auto node : graph)
    {
        node->dist = INF;      // 距离初始为无穷大
        node->visited = false; // 未访问过
    }
    graph[start]->dist = 0; // 起点到自己的距离为0

    // 扩展最短路径
    for (int i = 0; i < graph.size(); i++)
    {
        // 选择未访问过且距离最小的结点
        int minDist = INF;
        Node *minNode = nullptr;
        for (auto node : graph)
        {
            if (!node->visited && node->dist < minDist)
            {
                minDist = node->dist;
                minNode = node;
            }
        }
        if (!minNode)
            break; // 所有结点都已访问过，退出循环

        // 标记该结点已访问
        minNode->visited = true;

        // 更新距离列表
        for (auto neighbor : minNode->neighbors)
        {
            int newDist = minNode->dist + neighbor.second;
            if (newDist < neighbor.first->dist)
            {
                neighbor.first->dist = newDist;
            }
        }
    }
}

int main()
{
    // 构建一个简单图
    vector<Node *> graph;
    for (int i = 0; i < 5; i++)
    {
        graph.push_back(new Node{i, INF, false, {}});
    }
    graph[0]->neighbors = {{graph[1], 4}, {graph[2], 2}};
    graph[1]->neighbors = {{graph[2], 3}, {graph[3], 2}, {graph[4], 3}};
    graph[2]->neighbors = {{graph[1], 1}, {graph[3], 4}, {graph[4], 5}};
    graph[3]->neighbors = {{graph[4], 1}};
    graph[4]->neighbors = {};

    // 运行迪杰斯特拉算法
    dijkstra(graph, 0);

    // 打印最短路径结果
    for (auto node : graph)
    {
        cout << "从0到" << node->index << "的最短路径长度为：" << node->dist << endl;
    }

    return 0;
}