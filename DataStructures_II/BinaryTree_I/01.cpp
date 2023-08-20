#include <iostream>
#include "tree.hpp"

using namespace std;

int main(void) {

    tree_node* root = NULL;

    insertTree(&root, 26);
    insertTree(&root, 30);
    insertTree(&root, 17);
    insertTree(&root, 11);
    insertTree(&root, 23);
    insertTree(&root, 8);
    insertTree(&root, 5);
    insertTree(&root, 14);
    insertTree(&root, 25);
    insertTree(&root, 52);
    insertTree(&root, 40);
    insertTree(&root, 6);
    insertTree(&root, 28);
    insertTree(&root, 59);
    insertTree(&root, 27);

    printTree(root);

    return 0;
}
