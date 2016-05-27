#include <bits/stdc++.h>

using namespace std;

void printCase(int i, string result) {
    cout << "Case #" << i << ": " << result << endl;
}

void subtract(map<int, int> &numCount, map<char, int> &count, int num, char letter, string word) {
    numCount[num] = count[letter];
    for (int i = 0; i < word.length(); i++) {
        count[word[i]] = count[word[i]] - numCount[num];
    }
}

string solve(string input) {
    map<char, int> count;
    map<int, int> numCount;
    for (int i = 0; i < input.length(); i++) {
        count[input[i]]++;
    }

    subtract(numCount, count, 0, 'Z', "ZERO");
    subtract(numCount, count, 2, 'W', "TWO");
    subtract(numCount, count, 4, 'U', "FOUR");
    subtract(numCount, count, 3, 'R', "THREE");
    subtract(numCount, count, 1, 'O', "ONE");
    subtract(numCount, count, 8, 'H', "EIGHT");
    subtract(numCount, count, 5, 'F', "FIVE");
    subtract(numCount, count, 7, 'V', "SEVEN");
    subtract(numCount, count, 6, 'S', "SIX");
    subtract(numCount, count, 9, 'I', "NINE");

    string result = "";
    for (int i = 0; i <= 9; i++) {
        int x = numCount[i];
        while (x > 0) {
            x--;
            result += to_string(i);
        }
    }
    return result;
}

int main(void) {
    int T;
    cin >> T;
    string line;
    for (int i = 0; i < T; i++) {
        cin >> line;
        string res = solve(line);
        printCase(i+1, res);
    }
}
