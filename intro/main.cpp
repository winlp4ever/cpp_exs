#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <time.h>
#include <random>
using namespace std;

vector<unsigned int> primesbetw(const int & N) {
    vector<unsigned int> v;

    return v;
}

double estimePI(const int & N) {
    //srand(time(NULL));
    uniform_real_distribution<double> unif(0, 1);
    default_random_engine re;
    unsigned int nb(0);
    for (int i = 0; i < N; i++) {
        double x = unif(re);
        double y = unif(re);
        if (x * x + y * y < 1) nb++;
    }
    return 4 * ((double) nb / N);
}

bool isPalindrome(const string & s) {
    if (s.length() == 1 || s.length() == 0)
        return true;
    else if (s[s.length() - 1] == s[0])
        return isPalindrome(s.substr(1, s.length() - 2));
    return false;
}

void checkPalindrome() {
    while(true) {
        string word("");
        cin >> word;
        cin.ignore();
        string answer =  isPalindrome(word) ? "" : " not ";
        cout << "your enter word is " << answer << "a palindrome" << endl;  
    }
}

int main(int argc, char * argv[]) {
    //checkPalindrome();
    cout << estimePI(10000000) << endl;
    return 0;
}