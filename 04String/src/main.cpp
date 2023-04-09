#include <iostream>
#include "Solution.h"
Solution sln;

void testReverseString()
{
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    for (auto c : s)
    {
        std::cout << c;
    }
    std::cout << "\nAfter reverse:\n";
    sln.reverseString(s);
    for (char c : s)
    {
        std::cout << c;
    }
}

void testReverseLeftWords()
{
    string s = "abcdefg";
    int k = 2;
    sln.reverseLeftWords(s, k);
    std::cout << s << std::endl;
}

int main()
{
    testReverseLeftWords();

    return 0;
}