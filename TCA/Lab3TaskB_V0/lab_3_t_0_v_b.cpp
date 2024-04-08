#include <iostream>
#include <string>

using namespace std;

int main() {
    int x;
    string sequence;
    cin >> x >> sequence;

    int replacements = 0;
    int zeroCount = 0;
    bool started = false;

    // Check for leading zeros
    int i = 0;
    while (i < sequence.size() && sequence[i] == '0') {
        i++;
    }
    replacements += max(0, i - x);

    for (; i < sequence.size(); i++) {
        if (sequence[i] == '0') {
            if (started)
                zeroCount++;
        } else {
            if (zeroCount > x)
                replacements += (zeroCount - x);
            zeroCount = 0;
            started = true;
        }
    }

    // Check if there are trailing zeros at the end
    if (zeroCount > x)
        replacements += (zeroCount - x);

    cout << replacements << endl;

    return 0;
}