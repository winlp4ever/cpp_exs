#include <iostream>
#include <algorithm>
#include <vector>
#include <ostream>

using namespace std;

struct triple { // here you can use 'class' instead of 'struct', the only difference is that all attrbs of a struct is public by default
    int a, b, aplusb;
    triple(int a, int b);
    ~triple() {};
    bool operator< (const triple& u) const {
        return (aplusb < u.aplusb);
    }
    bool operator> (const triple& u) const {
        return (aplusb > u.aplusb);
    }

    int* toArray (const triple& u) {
        return (new int[4]{a, b, u.a, u.b});
    }

    friend ostream& operator<< (ostream& in, const triple& t);
};

triple::triple(int a_, int b_) {
    a = a_;
    b = b_;
    aplusb = a + b;
}; 

ostream& operator<< (ostream& in, const triple& t) {
    in << t.a << " + " << t.b << " = " << t.aplusb;
    return in;
}

bool compare(const triple& u, const triple& v) {
    return u.aplusb > v.aplusb; // descending order, change to '<' for ascending order,
}

int operator+ (const triple& u, const triple& v) {
    return u.aplusb + v.aplusb;
}

vector<int*> foursums(const vector<int>& v,const int& s) {
    /* get an int array and an int s, return all the 4-tuples summed up to s
    */
    vector<triple> Ts;
    cout << "begin adding..." << endl;
    for (vector<int>::const_iterator it = v.begin(); it != v.end() - 1; it++) {
        for (vector<int>::const_iterator it_ = it + 1; it_ != v.end(); it_++) {
            Ts.push_back(triple(*it, *it_));
        }
    }

    cout << "begin sorting..." << endl;
    sort(Ts.begin(), Ts.end());
    for (vector<triple>::const_iterator it = Ts.begin(); it != Ts.end(); it ++) {
        cout << *it << endl;
    }
    vector<int*> results;
    vector<triple>::iterator it = Ts.begin();
    vector<triple>::iterator _it = Ts.end() - 1; // remember to set this -1
    while (it < _it) {
        if (*it + *_it == s) {
            results.push_back(it->toArray(*_it));
            
        }
        if (*it + *_it <= s) 
            it ++;
        if (*it + *_it >= s)
            _it --;
        cout << *it + *_it << endl;
    }
    return results;
}

int main(int argc, char* argv[]) {
    vector<triple> v = {triple(2, 3), triple(3, 5), triple(1, 2), triple(0, 6)};
    //sort(v.begin(), v.end()); // if you want ascending order
    sort(v.begin(), v.end(), compare);
    //sort(v.rbegin(), v.rend());
    for (vector<triple>::iterator it = v.begin(); it != v.end(); it++) {
        cout << it->a << " - " << it->b << " - " << it->aplusb << endl;
    }
    // 4 sums algorithm
    vector<int> u = {-1, 11, 7, 8, 6, 9, 0, 5, 3, 12, -3};
    int s = 18;
    vector<int*> res = foursums(u, s);
    cout << "length result: " << res.size() << endl;
    for (vector<int*>::const_iterator it = res.begin(); it != res.end(); it ++) {
        for (int i = 0; i < 4; i++) {
            cout << *(*it + i);
            if (i < 3)
                cout << " + ";
        }
        cout << " = " << s << endl;
    }
}