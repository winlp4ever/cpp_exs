#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Vertex {
private:
    int index, rank;
    Vertex* parent;
public:
    Vertex(int i): index(i), rank(0) {
        parent = NULL;
    };
    Vertex(const Vertex& v): index(v.index), rank(v.rank) {
        parent = NULL;
    };
    ~Vertex() {};

    Vertex* getClass() {
        if (parent == NULL) 
            return this;
        return parent->getClass();
    }

    int getConPart() const{
        if (parent == NULL)
            return index;
        return parent->getConPart();
    }

    int getRank() const {
        return rank;
    }

    int getIndex() const {
        return index;
    }

    bool operator==(const Vertex& v) {
        return v.index == index;
    }

    void Union(Vertex& v) {
        Vertex* a = getClass();
        Vertex* b = v.getClass();
        if (*a == *b) 
            return;
        
        if (a->rank > b->rank) {
            b->parent = a;                
        }
        else if (a->rank < b->rank) {
            a->parent = b;
        }
        else {
            a->parent = b;
                    

            b->rank ++;
        }
    }

    friend ostream& operator<<(ostream& in, const Vertex& v) {
        in << "index: " << v.index << " -rank: " << v.rank << " -class: " << v.getConPart();
        return in;
    }
};

class Edge {
    int u, v;
    double w;
public:
    Edge(int u_, int v_, double w_): u(u_), v(v_), w(w_) {};
    Edge(const Edge& e): u(e.u), v(e.v), w(e.w) {};
    ~Edge() {};

    bool operator==(const Edge& e) const {
        return e.w == w;
    }

    bool operator<(const Edge& e) const {
        return e.w < w;
    }

    friend ostream& operator<<(ostream& in, const Edge& e) {
        in << "u: " << e.u << " -v: " << e.v << " -w: " << e.w;
        return in;
    }

    int operator[](const int& i) const {
        if (i > 1)
            throw runtime_error("invalid index! Only 0 or 1 accepted");
        if (i == 0)
            return u;
        return v;
    }

    double getW() const {
        return w;
    }
};

class Graph {
    vector<Vertex> vertices;
    vector<Edge> edges;
public:
    Graph(int n) {
        for (int i = 0; i < n; i++)
            vertices.push_back(Vertex(i));
    }
    Graph(const Graph& g) {
        vertices = g.vertices;
        edges = g.edges;
    }

    void mst(vector<Edge> es) {
        sort(es.begin(), es.end());
        for (vector<Edge>::iterator it = es.begin(); it != es.end(); it++) {
            Vertex& u = vertices[(*it)[0]];
            Vertex& v = vertices[(*it)[1]];

            if (u.getClass() != v.getClass()) {
                edges.push_back(Edge(*it));   
                u.Union(v);
            }
        }
    }

    friend ostream& operator<<(ostream& in, const Graph& g) {
        for (vector<Vertex>::const_iterator it = g.vertices.begin(); it != g.vertices.end(); it++) {
            in << *it << endl;
        }

        if (g.edges.size() == 0) 
            return in;
        for (vector<Edge>::const_iterator it = g.edges.begin(); it != g.edges.end(); it++) {
            in << *it << endl;
        }
        return in;
    }
};

int main(int argc, char* argv[]) {
    Graph g(5);
    vector<Edge> es = {Edge(0, 1, 1.), Edge(0, 4, 2.), Edge(1, 2, 3.), Edge(1, 3, 4.), Edge(2, 3, 5.), Edge(2, 4, 6.)};
    g.mst(es);
    cout << g << endl;
}