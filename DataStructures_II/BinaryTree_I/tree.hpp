#ifndef _HPP_TREE
#define _HPP_TREE

typedef struct Node {
    int data;
    Node *left;
    Node *right;
} leaf_node;

int ifEmpty(leaf_node *t) {

    if(t == NULL)
        return 1;

    if(t->data == NULL)
        return 1;

    return 0;
}

void insertTree(leaf_node **t, int num) {

    if(*t == NULL) {
        *t = new leaf_node;
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

void printTree(leaf_node *t) {

    cout << "<";

    if(!ifEmpty(t)) {
        cout << t->data;
        printTree(t->left);
        printTree(t->right);
    }

    cout << ">";
}

void printTreePre(leaf_node *t) {

    cout << "<";

    if(!ifEmpty(t)) {
        cout << t->data;
        printTreePre(t->left);
        printTreePre(t->right);
    }

    cout << ">";
}

void printTreeSym(leaf_node *t) {

    cout << "<";

    if(!ifEmpty(t)) {
        printTreeSym(t->left);
        cout << t->data;
        printTreeSym(t->right);
    }

    cout << ">";
}

void printTreePost(leaf_node *t) {

    cout << "<";

    if(!ifEmpty(t)) {
        printTreePost(t->left);
        printTreePost(t->right);
        cout << t->data;
    }

    cout << ">";
}

#endif
