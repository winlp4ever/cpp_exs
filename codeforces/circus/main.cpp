#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

/**
 * @brief complexity O(n)
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */

int main(int argc, char** argv) {
    int n;
    std::cin >> n;
    std::cin.ignore();
    std::string line_a, line_c;
    std::getline(std::cin, line_c);
    std::getline(std::cin, line_a);

    std::vector<int> jj, jo, oj, oo;
    for (int i = 0; i < n; i++) {
        if (line_c[i]&1) {
            if (line_a[i]&1) jj.push_back(i + 1);
            else jo.push_back(i + 1);
        }
        else {
            if (line_a[i]&1) oj.push_back(i + 1);
            else oo.push_back(i + 1);
        }
    }
    int ljj, ljo, loj, loo;
    ljj = jj.size();
    ljo = jo.size();
    loj = oj.size();
    loo = oo.size();

    int a = -1, b, c, d;
    for (int i = 0; i < jj.size() + 1; i++) {
        if ((i + ljo <= n / 2) && (i + ljo >= ljj - i) && (i + ljo <= ljj - i + loj) && (n / 2 >= loj + ljj - i)) {
            a = i;
            b = ljo;
            c = loj - (2 * i - ljj) - ljo;
            d = n / 2 + i - loj - ljj;
            break;
        }
        else if ((i + loj <= n / 2) && (i + loj >= ljj - i) && (i + loj <= ljj - i + ljo) && (n / 2 >= ljo + ljj - i)) {
            a = ljj - i;
            b = 2 * i - ljj + loj;
            c = 0;
            d = n / 2 - i - loj;
            break;
        }
    }
    if (a == -1) {
        std::cout << a << std::endl;
        return 0;
    }
    for (int i = 0; i < a; i++) std::cout << jj[i] << " ";
    for (int i = 0; i < b; i++) std::cout << jo[i] << " ";
    for (int i = 0; i < c; i++) std::cout << oj[i] << " ";
    for (int i = 0; i < d; i++) std::cout << oo[i] << " ";
    std::cout << std::endl;
    return 0;
}