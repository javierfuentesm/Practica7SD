#include<iostream>
#include<string>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
#include <bits/stdc++.h>

using namespace std;

int countFreq(string &ipn, string &txt) {
    int M = ipn.length();
    int N = txt.length();
    int res = 0;

    /* A loop to slide ipn[] one by one */
    for (int i = 0; i <= N - M; i++) {
        /* For current index i, check for
           pattern match */
        int j;
        for (j = 0; j < M; j++)
            if (txt[i + j] != ipn[j])
                break;

        // if ipn[0...M-1] = txt[i, i+1, ...i+M-1]
        if (j == M) {
            res++;
            j = 0;
        }
    }
    return res;
}

// Otra forma de hacerlo con substring
int countSubstring(const std::string &str, const std::string &sub) {
    if (sub.length() == 0) return 0;
    int count = 0;
    for (size_t offset = str.find(sub); offset != std::string::npos; offset = str.find(sub, offset + sub.length())) {
        ++count;
    }
    return count;
}

int main() {
    string n = "";
    srand(time(NULL));
    int nPalabras = 26 * 26 * 26;
    for (int i = 0; i < nPalabras; i++) {
        n.push_back(rand() % 26 + 65);
        n.push_back(rand() % 26 + 65);
        n.push_back(rand() % 26 + 65);
        n.push_back(32);
    }
    cout << n << endl;
    string ipn = "IPN ";
    cout << countSubstring(n, ipn);
}
