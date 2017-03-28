#ifndef TREE_H
#define TREE_H

extern int numberOfNodes;

extern char* addNode(int parentsLabel);

extern int rightmostChild(int label);

extern char* deleteNode(int label);

extern char* deleteSubtree(int label);

extern char* splitNode(int labelParent, int labelNodeNextTo);

extern void setupZeroNode();

extern void clean();

#endif /* TREE_H */