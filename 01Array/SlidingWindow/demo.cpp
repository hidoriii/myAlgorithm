#include <iostream>
#include <string>

#include "Solution.h"

void test1()
{
    Solution sln;
    string S("AHDSKKNBCNAUI"), T("ABC");
    auto ans = sln.minWindow(S, T);
    std::cout << ans << "\n";
}

int main()
{
    test1();

    std::cin.get();
    return 0;
}
