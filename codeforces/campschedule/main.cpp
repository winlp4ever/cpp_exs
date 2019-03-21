#include <iostream>
#include <algorithm>
#include <string>


int main(int argc, char** argv) {
    std::string s, t;
    std::getline(std::cin, s);
    std::getline(std::cin, t);
    int s1(0), s0(0), t1(0), t0(0), p1(0), p0(0);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') s1++;
        else s0++;
    }
    int m = 0;
    for (int i = t.length(); i > 0; i--) {
        if (t.substr(i, t.length() - i) == t.substr(0, t.length() - i)) {
            m = i;
            p1 = 0;
            p0 = 0;
        }
        if (t[i - 1] == '1') {
            t1++;
            p1++;
        }
        else {
            t0++;
            p0++;
        }
    }

    int idx = 0;
    while (s1 >= t1 && s0 >= t0 && idx <= s.length() - t.length()) {
        s.replace(idx, t.length(), t);
        s1 -= p1;
        s0 -= p0;
        idx += m;
        if (idx > s.length() - t.length()) {
            s1 -= t1 - p1;
            s0 -= t0 - p0;
            idx = idx - m + t.length();
        }
    }
    for (int i = idx; i < s.length(); i++) {
        if (s1 > 0) {
            s[i] = '1';
            s1--;
        }
        else if (s0 > 0) {
            s[i] = '0';
            s0--;
        }
        
    }
    
    std::cout << s << std::endl;
}