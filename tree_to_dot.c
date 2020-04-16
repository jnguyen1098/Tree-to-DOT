#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUCCESS 1
#define FAIL    0

/* inline functions */
#define MAX(x,y) (x > y ? x : y)
#define BALANCE(x) ((x) ? HEIGHT((x)->left) - HEIGHT((x)->right) : 0)
#define HEIGHT(x) ((x) ? (x)->height : 0)

/* write mode indicator */
typedef enum writemode_enum { NORMAL, AVL } WriteMode;

/* node definition */
typedef struct tree_node {
    int data;
    struct tree_node *left;
    struct tree_node *right;
    int height;
} Node;

/* write file to output.dot */
int write_file(Node *, FILE *);

/* recursive line writer */
void write_line(Node *);

/* function to insert node into tree */
void add(Node **, int, WriteMode);

/* node creation func. */
Node *create(int);

/* frees a binary tree */
void free_tree(Node *);

/* AVL rotation paradigms */
void rightRotate(Node **);
void leftRotate(Node **);

/* yeah */
static FILE *fp;
static int i;

int main(void)
{
    /* initializing */
    Node *root = NULL;
    srand((unsigned int)time(NULL));

    /* add random numbers to tree */
    for (int iter = 1; iter <= 20; iter++)
        add(&root, rand() % 100 + 1, AVL);

    /* write to stdout (or file) */
    if (!write_file(root, stdout))
        fprintf(stderr, "Write failed\n");

    /* housekeeping */
    free_tree(root);
    return 0;
}

int write_file(Node *tree, FILE *infp)
{
    if (!tree) return FAIL;

    // so I don't pass fp into write_line every time
    fp = infp;

    /* header info */
    fprintf(fp, "digraph G {\n");
    fprintf(fp, "\tgraph [ordering=\"out\"];\n");

    /* recursively write tree to file */
    write_line(tree);

    /* housekeeping */
    fprintf(fp, "}");
    return SUCCESS;
}

void write_line(Node *tree)
{
    if (!tree) return;

    /* write node if exists */
    if (tree->left)
        fprintf(fp, "\t\"%d\" -> \"%d\"\n", tree->data, tree->left->data);
    /* else just write a dot to represent NULL */
    else {
        fprintf(fp, "\tnull%d [shape=\"point\"]\n", i);
        fprintf(fp, "\t\"%d\" -> null%d\n", tree->data, i++);
    }

    if (tree->right)
        fprintf(fp, "\t\"%d\" -> \"%d\"\n", tree->data, tree->right->data);
    else {
        fprintf(fp, "\tnull%d [shape=\"point\"]\n", i);
        fprintf(fp, "\t\"%d\" -> null%d\n", tree->data, i++);
    }

    /* recurse */
    write_line(tree->left);
    write_line(tree->right);
    return;
}

void add(Node **tree, int data, WriteMode mode)
{
    /* normal insertion paradigm */
    if (!*tree) {
        *tree = create(data);
    } else {
        if ((*tree)->data > data)
            add(&((*tree)->left), data, mode);
        else if ((*tree)->data < data)
            add(&((*tree)->right), data, mode);
        else // equal case...undefined
            return;
    }

    /* AVL code to follow */
    if (mode != AVL) return;

    /* update height */
    (*tree)->height = 1 + MAX(HEIGHT((*tree)->left), HEIGHT((*tree)->right));

    /* assess balance */
    int balance = BALANCE(*tree);

    /* single rotations */
    if (balance > 1 && data < (*tree)->left->data)
        rightRotate(tree);

    else if (balance < -1 && data > (*tree)->right->data)
        leftRotate(tree);

    /* double rotations */
    else if (balance > 1 && data > (*tree)->left->data) {
        leftRotate(&((*tree)->left));
        rightRotate(tree);
    }

    else if (balance < -1 && data < (*tree)->right->data) {
        rightRotate(&((*tree)->right));
        leftRotate(tree);
    }

    return;
}


Node *create(int data)
{
    Node *ret = calloc(1, sizeof(Node));
    ret->data = data;
    ret->height = 1; // height starts at 1
    return ret;
}

void free_tree(Node *tree)
{
    if (!tree) return;
    free_tree(tree->left);
    free_tree(tree->right);
    free(tree);
    return;
}


void rightRotate(Node **y)
{
    Node *x = (*y)->left;
    Node *T2 = x->right;

    x->right = (*y);
    (*y)->left = T2;

    (*y)->height = MAX(HEIGHT((*y)->left), HEIGHT((*y)->right)) + 1;
    x->height = MAX(HEIGHT(x->left), HEIGHT(x->right)) + 1;

    *y = x;

    return;
}

void leftRotate(Node **x)
{
    Node *y = (*x)->right;
    Node *T2 = y->left;

    y->left = (*x);
    (*x)->right = T2;

    (*x)->height = MAX(HEIGHT((*x)->left), HEIGHT((*x)->right)) + 1;
    y->height = MAX(HEIGHT(y->left), HEIGHT(y->right)) + 1;

    *x = y;
    return;
}

