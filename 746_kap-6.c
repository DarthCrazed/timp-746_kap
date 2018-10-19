nclude <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    int key;
    struct node *right;
    struct node *left;
} node;

typedef node* tree;

int init(tree *root){
    *root = NULL;
    return 1;
}

int addnote(int key, int value, tree *root){
    tree con = (*root);
    tree con2 = (tree)malloc(sizeof(node));
    con2->key = key;
    con2->value = value;
    con2->right = NULL;
    con2->left = NULL;

    if((*root) == NULL){
        (*root) = con2;
        return 1;
    }

    while (1)
    {
        if(key > con->key)
        {
            if(con->right == NULL)
            {
                con->right = con2;
                return 1;
            }
            con = con->right;
        }
        else if(key < con->key)
        {
            if(con->left == NULL)
            {
                con->left = con2;
                return 1;
            }
            con = con->left;
        }
        else return 1;
    }
}

void treeprint(tree root){
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->value);
    treeprint(root->left);
    treeprint(root->right);
}

int main()
{
    tree root;
    init(&root);

    int i, x, key, n;

    scanf("%d", &n);

    for(i=0; i<n; i++){
        scanf("%d", &key);
        scanf("%d", &x);
        addnote(key, x, &root);
    }

    treeprint(root);
    printf("\n");
    return 0;
}

