#include <bits/stdc++.h>

using namespace std;

long long solve(string &s1, string &s2, int i, int bigger) {
    // 0 not clear, 1 s1 bigger, 2 s2 bigger
    if (s1[i] != '?' && s2[i] != '?') {
        if (bigger == 0 && s1[i] > s2[i]) {
            bigger = 1;
        } else if (bigger == 0 && s1[i] < s2[i]) {
            bigger = 2;
        }
    }

    if (s1[i] == '?') {
        if (bigger == 1) {
            s1[i] = '0';
        } else if (bigger == 2) {
            s1[i] = '9';
        } else {
            if (s2[i] != '?') {
                s1[i] = s2[i];
            } else {
                if (i == s1.length()-1 || s1[i+1] == '?' || s2[i+1] == '?') {
                    s1[i] = '0';
                    s2[i] = '0';
                } else {
                    string s10(s1);
                    string s11(s1);
                    string s12(s1);

                    string s20(s2);
                    string s21(s2);
                    string s22(s2);

                    s10[i] = '0';
                    s20[i] = '0';

                    s11[i] = '0';
                    s21[i] = '1';

                    s12[i] = '1';
                    s22[i] = '0';

                    long d1 = solve(s10, s20, i+1, 0);
                    long d2 = solve(s11, s21, i+1, 2);
                    long d3 = solve(s12, s22, i+1, 1);

                    if (d1 <= d2 && d1 <= d3) {
                        s1[i] = '0';
                        s2[i] = '0';
                    } else if (d2 <= d3) {
                        s1[i] = '0';
                        s2[i] = '1';
                        bigger = 2;
                    } else {
                        s1[i] = '1';
                        s2[i] = '0';
                        bigger = 1;
                    }
                }
            }
        }
    }

    if (s2[i] == '?') {
        if (bigger == 1) {
            s2[i] = '9';
        } else if (bigger == 2) {
            s2[i] = '0';
        } else {
            s2[i] = s1[i];
        }
    }

    if (i < s1.length()) {
        return solve(s1, s2, i+1, bigger);
    } else {
        long long a1 = stoll(s1);
        long long a2 = stoll(s2);
        if (a1 > a2) {
            return a1-a2;
        } else {
            return a2-a1;
        }
    }
}

int main(void) {
    int T;
    cin >> T;
    string s1, s2;
    for (int i = 0; i < T; i++) {
        cin >> s1 >> s2;
        solve(s1, s2, 0, 0);
        cout << "Case #" << (i+1) << ": " << s1 << " " << s2 << endl;
    }
}
