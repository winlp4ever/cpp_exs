#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <set>
#include <bitset>
#include <time.h>

using namespace std;

int last_bin_digits(const int& a, const int& n) {
    /**
     * Return deximal value of last n digits of a in binary form.
     * For example, last_bin_digits(23, 2) returns 3, which is value of 11, 
     * last 2 digits in binary form of 23
     */
    return a - ((a >> n) << n);
}

string to_bin(const int& a) {
    /**
     * Return binary form of integer (must be positive) 
     */
    if (a < 0) throw std::invalid_argument( "received negative value, must be positive!" );
    int n = 0;
    string s = "";
    while ((a >> n) != 0) {
        s = to_string(((a >> n) % 2)) + s;
        n++;
    }
    return s;
}

class HashBuckets {
private:
    int global_depth;
    int bucket_size;
    vector<pair<int, vector<int>*>> keybucs; // (local depth, addr to bucket)
public:
    HashBuckets() {
        bucket_size = 4;
        global_depth = 1;
        vector<int>* u0 = new vector<int>;
        vector<int>* u1 = new vector<int>;
        vector<pair<int, vector<int>*>> kb;
        kb.push_back(pair<int, vector<int>*>(1, u0));
        kb.push_back(pair<int, vector<int>*>(1, u1));
        keybucs = kb;
    }
    ~HashBuckets() {
        set<int> existedKeys;
        int id = 0;
        for (vector<pair<int, vector<int>*>>::iterator it = keybucs.begin(); it != keybucs.end(); it++) {
            int key = last_bin_digits(id, it->first);
            if (existedKeys.find(key) == existedKeys.end()) delete it->second;
            existedKeys.insert(key);
        }
    } 
    inline int getKey(const int& a) const{
        return last_bin_digits(a, global_depth);
    }

    void extends() {
        global_depth++;
        keybucs.insert(keybucs.end(), keybucs.begin(), keybucs.end());
    }

    void divide_bucket(const int& key) {
        int local_depth = keybucs[key].first;
        vector<int>* v = keybucs[key].second;
        if (local_depth == global_depth) extends();

        vector<int>* v0 = new vector<int>;
        vector<int>* v1 = new vector<int>;
        for (vector<int>::iterator it = v->begin(); it != v->end(); it++) {
            if ((*it >> local_depth) % 2) v1->push_back(*it);
            else v0->push_back(*it);
        }


        int k = last_bin_digits(key, local_depth);
        int length = keybucs.size();
        delete v; // delete v and replace v0, v1 into corresponding plots
        int h = 0;
        for (int i = k; i < length; i += (1 << local_depth)) {
            if((i >> local_depth) % 2)
                keybucs[i] = pair<int, vector<int>*>(local_depth + 1, v1);
            else
                keybucs[i] = pair<int, vector<int>*>(local_depth + 1, v0);
            h++;
        }
    }

    bool isfull(const int& key) {
        return keybucs[key].second->size() == bucket_size;
    }

    bool exist(const int& a) {
        int key = getKey(a);
        vector<int>* v = keybucs[key].second;
        for(vector<int>::const_iterator it = v->begin(); it != v->end(); it++) {
            if(a == *it)
                return true;
        }
        return false;
    }
    bool add(int a) {
        if (exist(a)) return false;

        int key = getKey(a);
        while(isfull(key)) {
            divide_bucket(key);
            key = getKey(a);
        }
        keybucs[key].second->push_back(a);
        return true;
    }

    string toString() {
        string s = "||-----------------||\nglobal depth: " + to_string(global_depth) + "\n";
        int id = 0;
        for(vector<pair<int, vector<int>*>>::const_iterator it = keybucs.begin(); it != keybucs.end(); it++) {
            s += "id: " + to_string(id) + " - local depth: " + to_string(it->first) + "\n[ ";
            vector<int>* v = it->second;
            for(vector<int>::const_iterator i = v->begin(); i != v->end(); i++) {
                s += to_string(*i) + " ";
                s += "(" + to_bin(*i) + ") ";
            }
            s += "]\n";
            id ++;
        }
        return s + "||-----------------||";
    }
};

int main(int argc, char* argv []) {
    cout << (13-((13>>2)<<2)) << endl;
    cout << to_bin(157) << endl;
    cout << bitset<8>(157).to_string() << endl;
    HashBuckets hshbks;
    default_random_engine gen;
    gen.seed(time(NULL));
    uniform_int_distribution<> U(0, 1000);
    for (int i = 0; i < 1000; i++) {
        int a = U(gen);
        hshbks.add(a);
    }
    cout << hshbks.toString() << endl;
    return 0;
}