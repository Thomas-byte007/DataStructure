#include "./graph_adjacency_list.cpp"
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

/* 广度优先遍历 */
// 使用邻接表来表示图，以便获取指定顶点的所有邻接顶点
vector<Vertex *> graphBfs(GraphAdjList &graph,Vertex *startVet){
    vector<Vertex *> res;
    unordered_set<Vertex*> visited = {startVet};
    queue<Vertex*> que;
    que.push(startVet);
    while(!que.empty()){
        Vertex *vet = que.front();
        que.pop();
        res.push_back(vet);
        for(auto adjVet : graph.heads[vet]){
            if(visited.count((adjVet)))
                continue;
            que.push(adjVet);
            visited.emplace(adjVet);
        }
    }
}