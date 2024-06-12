#include <iostream>
#include <vector>
using namespace std;

int lower_bound(const vector<long long> &array, long long search_value) {
    int left = 0;
    int right = array.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (search_value <= array[mid]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<long long> Nn(N);
    vector<long long> Mm(M);
    for (int i = 0; i < N; i++) {
        cin >> Nn[i];
    }
    for (int i = 1; i < N; i++) {
        Nn[i] += Nn[i - 1];
    }
    for (int i = 0; i < M; i++) {
        cin >> Mm[i];
    }
    for (int i = 0; i < M; i++) {
        cout << lower_bound(Nn, Mm[i]) + 1 << " ";
    }
}