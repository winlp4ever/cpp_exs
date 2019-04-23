#include <iostream>
#include <unordered_map>
#include <string>

struct Node {
    char c;
    bool term;
    int h;
    std::unordered_map<char, Node*> childs;

    Node(char c_, int h_): c(c_), term(false), h(h_), childs() {};
    ~Node() {
        for (auto it = childs.begin(); it != childs.end(); it++) 
            delete it->second;
    }
    bool insert(const std::string &s) {
        if (s[0] != c) return false;
        if (s.length() == 1) {
            term = true;
            return true;
        }
        auto find = childs.find(s[1]);
        if (find != childs.end()) {
            return find->second->insert(s.substr(1, s.length() - 1));
        }
        else {
            childs[s[1]] = new Node(s[1], h+1);
            return childs[s[1]]->insert(s.substr(1, s.length() - 1));
        }
    }

    bool find(const std::string &s) {
        if (s[0] != c) return false;
        if (s.length() == 1) {
            if (term) return true;
            else return false;
        }
        auto find = childs.find(s[1]);
        if (find == childs.end()) return false;
        else {
            return find->second->find(s.substr(1, s.length() - 1));
        }
    }

    friend std::ostream& operator<<(std::ostream& in, const Node &node) {
        in << node.c << " - " << node.term << " h: " << node.h << std::endl;
        for (auto it = node.childs.begin(); it != node.childs.end(); it++) in << *(it->second);
        return in;
    }
};


int main(int argc, char** argv) {
    Node node('c', 0);
    bool u = node.insert("cook");
    bool v = node.insert("coat");
    node.insert("cookie");
    node.insert("crook");
    std::cout << node.childs.size() << std::endl;
    std::cout << node << std::endl;
    std::cout << node.find("cookie") << std::endl;
}