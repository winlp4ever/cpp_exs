#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <time.h>

#include "Cell.h"
#include "Zone.h"

using namespace std;

string toString(vector<Zone*> zs) {
    string s = "";
    for (vector<Zone*>::const_iterator it = zs.begin(); it != zs.end(); it ++) {
        s += (*it)->toString();
        if (it != zs.end() - 1) s += "  ";
    }
    return s;
};

string toString_(vector<vector<Zone*>> zzs) {
    string s = "";
    for (vector<vector<Zone*>>::const_iterator it = zzs.begin(); it != zzs.end(); it ++) {
        s += "[" + toString(*it) + "]";
        if (it != zzs.end()) s += " ";
    }
    return s;
};

class BplusTree {
private:
    Zone* root;
public:
    BplusTree() {
        root = new Zone(true);
    };
    ~BplusTree() {
        delete root;
    };
    void insert(int a) {
        // search for position
        Cell* c = root->insert_plus(a);
        if (c) {            
            Zone* z = new Zone();            
            z->insert(c);
            root = z;
        }
    }
    string toString() {
        Zone* z = root;
        vector<Zone*> v = {root};
        vector<vector<Zone*>> vv = {v};
        int l = 1;
        int depth = 0;
        string s = "";
        while(l > 0) {
            s += to_string(depth) + ": " + toString_(vv) + "\n";
            l = 0;
            vector<vector<Zone*>> vv_tmp;
            for (vector<vector<Zone*>>::const_iterator iit = vv.begin(); iit != vv.end(); iit ++) {
                for (vector<Zone*>::const_iterator it = iit->begin(); it != iit->end(); it ++) {
                    vector<Zone*> v_tmp = (*it)->descs_of_zone();
                    vv_tmp.push_back(v_tmp);
                    l += v_tmp.size();
                }
            }
            vv = vv_tmp;
            depth ++;            
        }
        return s;
    }

};

int main(int argc, char* argv[]) {
    Cell cell(5);
    BplusTree tree;
    default_random_engine gen;
    gen.seed(time(NULL));
    uniform_int_distribution<> U(0, 1000000);
    for (int i = 0; i < 100; i ++) {
        tree.insert(U(gen));
    }
    cout << tree.toString() << endl;
}