#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

typedef std::pair<int, double> p;

class Solution {
public:

    int largest_possible(const int &N, const int &L, const std::vector<int> &vec) const{
        std::vector<p> residuals;
        double coef = 100.0 / N;
        double rd = coef - (int) coef;
        int U = 0;
        
        for (int i = 0; i < L; i++) {
            double res = vec[i] * coef;
            residuals.push_back(p(i, res - (int) res));
            U += (rd >= 0.5)? (int) std::ceil(res): (int) res;
        }
        sort(residuals.begin(), residuals.end(), [] (const p &a, const p &b) {
            return a.second >= b.second;
        });

        int s = N; // sum of vec
        std::for_each(vec.begin(), vec.end(), [&] (int n) {
            s -= n;  
        });

        if (100 % N == 0) { // check if coef - (int) coef == 0.
            return 100;
        }

        if (coef - (int) coef >= 0.5) {
            U += s * std::ceil(coef);
            return U;
        }

        for (auto& x: residuals) {
            if (x.second < 0.5) {
                double r = (0.5 - x.second) / rd;
                int need_p = (int) std::ceil(r);
                if (s >= need_p) {
                    s -= need_p;
                    U += 1 + need_p * (int) coef;
                }
                else 
                    break;
            }
        }

        if (s > 0) {
            double rd = coef - (int) coef;
            int times = (int) std::ceil(0.5 / rd);
            int t = s / times;
            U += t * times + s * (int) coef;
        }
        return U;
    }
};

int main(int argc, char** argv) {
    int T;
    Solution sol;
    std::cin >> T;
    std::cin.ignore();
    for (int i = 1; i <= T; ++i) {
        int N, L;
        std::cin >> N >> L;
        std::cin.ignore();
        std::vector<int> v;
        for (int j = 0; j < L; j++) {
            int c;
            std::cin >> c;
            v.push_back(c);
        }
        int result = sol.largest_possible(N, L, v);
        std::cout << "Case #" << i << ": " << result << std::endl;
    }
    return 0;
}