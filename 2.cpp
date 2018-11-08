#include <iostream>

using namespace std;
int p = 31;
int p_pow[1000];
int h[1000];
int hash_t = 0;

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    p_pow[0] = 1;
    for (int i = 1; i < s.size(); i++)
        p_pow[i] = p_pow[i - 1] * p;
    h[0] = s[0];
    for (int i = 1; i < n; i++)
        h[i] = h[i - 1] + s[i] * p_pow[i];
    for (int i = 0; i < m; i++)
        hash_t += t[i] * p_pow[i];

    for (int i = 0; i + m < n; i++) {
        int j = i + m - 1;
        int hash = h[j];
        if (i > 0) hash -= h[i - 1];
        if (hash == hash_t * p_pow[i])
            cout << i << " ";
    }
    return 0;
}