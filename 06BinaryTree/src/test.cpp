#include <iostream>
#include "Solution.h"
#include <algorithm>

Solution sln;

void testMorris(TreeNode *root)
{
    TreeNode node1(2), node2(3), node3(4), node4(5), node5(6), node6(7);
    root->left = &node1;
    root->right = &node2;
    root->left->left = &node3;
    root->left->right = &node4;
    root->right->left = &node5;
    root->right->right = &node6;

    auto print = [](const int i)
    { std::cout << i << " "; };

    auto ans1 = sln.preorderTraversal(root);
    std::for_each(ans1.begin(), ans1.end(), print);
    std::cout << "\n============================\n";
    auto ans2 = sln.morrisPre(root);
    std::for_each(ans2.begin(), ans2.end(), print);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    std::cout << "test begin.\n";
    testMorris(root);
    std::cout << "\ntest over.\n";
    delete root;

    std::cin.get();
    return 0;
}