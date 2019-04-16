#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

typedef std::pair<int, int> Node;
// popular way to represent a graph is by a list of adjacent vertices
// this time undirected weighted graph

void add_edge(std::vector<Node> G[], int u, int v, int w) {
    G[u].push_back(Node(v, w));
    G[v].push_back(Node(u, w));
}

std::unordered_map<int, int> mst(int n, std::vector<Node> graph[]) {

    struct comp { // replace less than
        bool operator()(const Node &a, const Node &b) {
            return a.second > b.second;
        }
    };

    std::priority_queue<Node, std::vector<Node>, comp> Q;
    std::unordered_map<int, int> visited;
    Q.push(Node(n, 0));
    visited[n] = 0;
    while (!Q.empty()) {
        Node v = Q.top();
        std::cout << v.first << std::endl;
        Q.pop();
        for (auto adj: graph[v.first]) {
            int d = visited[v.first] + adj.second;
            if (visited.find(adj.first) == visited.end() || visited[adj.first] > d) {
                visited[adj.first] = d;
                Q.push(Node(adj.first, d));
            }
        }
    }
    return visited;
}


int main(int argc, char** argv) {
    int V = 5;
    std::vector<Node> G[V];
    add_edge(G, 0, 1, 1);
    add_edge(G, 0, 2, 2);
    add_edge(G, 1, 2, 0);
    add_edge(G, 0, 4, 1);
    add_edge(G, 2, 3, 1);
    std::unordered_map<int, int> visited = mst(0, G);
    for (auto it = visited.begin(); it != visited.end(); it++) {
        std::cout << it->first << ": " << it->second << std::endl;
    }
}