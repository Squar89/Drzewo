#include<stdlib.h>
#include<assert.h>
#include"list.h"

#define MAX_ARRAY_SIZE 250000


/* right and left guardian is self-explanatory and nodeInParentsList
 * is a pointer to this node's unique list element which is an element
 * of his parent's list (basically this node represented as list element) */
typedef struct Tree {
    struct List *leftGuardian;
    struct List *rightGuardian;
    struct List *nodeInParentsList;
} Tree;

/* Array that stores pointers to nodes(Tree) with their labels as key */
Tree *pointerToNode[MAX_ARRAY_SIZE];
int numberOfNodes = 0;
int nextNodeLabel = 0;

Tree* getPointerToNode(int label) {
    /* NULL pointer possible only when we are trying to interact with
     * a node that has already been deleted */
    assert(pointerToNode[label] != NULL && "interacting with deleted node");
    
    return pointerToNode[label];
}

void updateArray(int label, Tree *node) {
    pointerToNode[label] = node;
    
    return;
}

void createNode(List *nodeInParentsList) {
    Tree *node;
    node = (Tree*) malloc(sizeof(Tree));
    
    node->leftGuardian = createListElement(-1);
    node->rightGuardian = createListElement(-1);
    setConnection(node->leftGuardian, node->rightGuardian);
    node->nodeInParentsList = nodeInParentsList;
    
    updateArray(nextNodeLabel, node);
    
    numberOfNodes++;
    nextNodeLabel++;
    
    return;
}

char* addNode(int parentsLabel) {
    List *nodeInParentsList = createListElement(nextNodeLabel);
    Tree *parentsNode = getPointerToNode(parentsLabel);
    List *lastParentsChild = getPrevious(parentsNode->rightGuardian);
    List *parentsGuardian = parentsNode->rightGuardian;
    /* lastParentsChild might also be his left guardian,
     * but that doesn't really matter in this case */
    
    setConnection(lastParentsChild, nodeInParentsList);
    setConnection(nodeInParentsList, parentsGuardian);
    createNode(nodeInParentsList);
    
    return "OK";
}

int rightmostChild(int label) {
    Tree *node = getPointerToNode(label);
    List *rightChild = getPrevious(node->rightGuardian);
    
    /* returns label of list element that is a predecessor
     * to node's right guardian, so either his rightmost child
     * or his left guardian with label "-1" */
    return rightChild->label;
}

bool hasNoChildren(int label) {
    /* rightmostChild returns -1 only if node has no Children */
    if (rightmostChild(label) == -1) {
        return true;
    }
    else {
        return false;
    }
}

char* deleteNode(int label) {
    Tree *node = getPointerToNode(label);
    List *previousOnParentsList = getPrevious(node->nodeInParentsList);
    List *nextOnParentsList = getNext(node->nodeInParentsList);
    List *leftChild = getNext(node->leftGuardian);
    List *rightChild = getPrevious(node->rightGuardian);
    
    if (hasNoChildren(label)) {
        setConnection(previousOnParentsList, nextOnParentsList);
    }
    else {
        setConnection(previousOnParentsList, leftChild);
        setConnection(rightChild, nextOnParentsList);
    }
    
    deleteListElement(node->leftGuardian);
    deleteListElement(node->rightGuardian);
    deleteListElement(node->nodeInParentsList);
    updateArray(label, NULL);
    free(node);
    numberOfNodes--;
    
    return "OK";
}

char* deleteSubtree(int label) {
    Tree *node = getPointerToNode(label);
    List *previousOnParentsList = getPrevious(node->nodeInParentsList);
    List *nextOnParentsList = getNext(node->nodeInParentsList);
    
    /* deleteNode replaces input Node in his parent's list with his
     * children so this while deletes nodes from parent's list until
     * the input node predecessor's successor is input node original
     * successor, or simply until whole subtree is deleted from parent's list
     */
    while (getNext(previousOnParentsList) != nextOnParentsList) {
        deleteNode(getLabel(getNext(previousOnParentsList)));
    }

    return "OK";
}

char* splitNode(int labelParent, int labelNodeNextTo) {
    addNode(labelParent);
    
    /* newNode is the node that we just created and
     * nodeNextTo is the node that we are asked to split tree right after */
    Tree *newNode = getPointerToNode(nextNodeLabel - 1);
    Tree *nodeNextTo = getPointerToNode(labelNodeNextTo);
    List *leftChildToMove = getNext(nodeNextTo->nodeInParentsList);
    List *rightChildToMove = getPrevious(newNode->nodeInParentsList);
    
    if (leftChildToMove != newNode->nodeInParentsList) {
        setConnection(newNode->leftGuardian, leftChildToMove);
        setConnection(rightChildToMove, newNode->rightGuardian);
        setConnection(nodeNextTo->nodeInParentsList,
                      newNode->nodeInParentsList);
    }

    return "OK";
}

/* this function prepares node 0 which is a little bit different
 * as it doesn't have parent */
void setupZeroNode() {
    createNode(createListElement(0));
}

void clean() {
    Tree *zeroNode = getPointerToNode(0);
    /* these are created so we can use deleteSubtree function on zero node
     * and therefore simplify cleaning process */
    List *highestLeftGuardian = createListElement(-1);
    List *highestRightGuardian = createListElement(-1);
    
    setConnection(highestLeftGuardian, zeroNode->nodeInParentsList);
    setConnection(zeroNode->nodeInParentsList, highestRightGuardian);
    
    deleteSubtree(0);
    deleteListElement(highestLeftGuardian);
    deleteListElement(highestRightGuardian);
    
    return;
}