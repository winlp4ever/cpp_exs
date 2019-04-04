#include <iostream>
#include <list> // internally implemented by a double-linked list
#include <algorithm>


struct Graph {
    int V;
    std::list<int> *Adj;
public:
    Graph(int n);
    ~Graph();
    void addEdge(int u, int v);
    bool isCyclic();
};

void Graph::addEdge(int u, int v) {
        Adj[u].push_back(v);
}
Graph::Graph(int n): V(n) {
        Adj = new std::list<int>[V];
    }
Graph::~Graph() {
        delete[] Adj;
    }

bool Graph::isCyclic() {
    std::list<int> visited(0);
    bool check_visit[V];

    while (!visited.empty()) {
        int u = visited.front();
        if (check_visit[u]) return true; 
        else check_visit[u] = true;
        visited.pop_front();
        std::for_each(Adj[u].begin(), Adj[u].end(), [&visited](int a) {
            visited.push_front(a);
        });
    }
    return false;
}

int main(int argc, char** argv) {
    int n, e;
    std::cin >> n >> e;

    Graph g(n);
    for (int i = 0; i < e; i++) {
        int u, v;
        std::cin >> u >> v;
        g.addEdge(u, v);
    }

    std::cout << "This graph is " << (g.isCyclic()? "": " not ") << "cyclic!" << std::endl;
}