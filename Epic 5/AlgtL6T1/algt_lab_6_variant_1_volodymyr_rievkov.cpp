#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, K;
    const int alphabetSize = 26;
    std::vector<int> letterCount(alphabetSize, 0);

    std::cin >> N >> K;

    for (int i = 0; i < N; ++i) {
        std::string word;
        std::cin >> word;

        std::vector<bool> uniqueLetters(alphabetSize, false);

        for (char letter : word) {
            letter = std::tolower(letter);
            uniqueLetters[letter - 'a'] = true;
        }

        if (std::count_if(uniqueLetters.begin(), uniqueLetters.end(), [](bool b) { return b; }) >= K) {
            for (char letter : word) {
                letter = std::tolower(letter);
                ++letterCount[letter - 'a'];
            }
        }
    }

    std::vector<char> resultLetters;

    for (int i = 0; i < alphabetSize; ++i) {
        if (letterCount[i] >= K) {
            resultLetters.push_back('a' + i);
        }
    }

    std::sort(resultLetters.rbegin(), resultLetters.rend());

    if (resultLetters.empty()) {
        std::cout << "Empty!" << std::endl;
    } else {
        std::cout << resultLetters.size() << std::endl;
        for (char letter : resultLetters) {
            std::cout << letter << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}