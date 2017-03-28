#ifndef TREE_H
#define TREE_H

typedef struct Tree {
    struct List *leftGuardian;
    struct List *rightGuardian;
    struct List *nodeInParentsList;
} Tree;

extern char* addNode(int parentsLabel);

extern int rightmostChild(int label);

extern char* deleteNode(int label);

extern char* deleteSubtree(int label);

extern char* splitNode(int labelParent, int labelNodeNextTo);

#endif /* TREE_H */