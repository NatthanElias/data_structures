#ifndef _HPP_TREE
#define _HPP_TREE

typedef struct Node {
    int data;
    Node *left;
    Node *right;
} tree_node;

int ifEmpty(tree_node *t) {

    if(t == NULL)
        return 1;

    if(t->data == NULL)
        return 1;

    return 0;
}

void insertTree(tree_node **t, int num) {

    if(*t == NULL) {
        *t = new tree_node;
        (*t)->left = NULL;
        (*t)->right = NULL;
        (*t)->data = num;
    }

    else {

    if(num < (*t)->data)
        insertTree(&(*t)->left, num);

    else
        insertTree(&(*t)->right, num);
    }
}
void printTree(tree_node *t) {

    cout << "<";

    if(!ifEmpty(t)) {
        cout << t->data;
        printTree(t->left);
        printTree(t->right);
    }

    cout << ">";
}

#endif
