#include<stdlib.h>
#include"list.h"
#include"tree.h"

#define MAX_ARRAY_SIZE 250000

Tree *PointerToNode[MAX_ARRAY_SIZE];
int numberOfNodes = 0;
int nextNodeLabel = 0;

Tree* getPointerToNode(int label) {
    return PointerToNode[label];
}

void updateArray(int label, Tree *node) {
    PointerToNode[label] = node;
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
     * but that doesn't really matter in this case
     */
    
    setConnection(lastParentsChild, nodeInParentsList);
    setConnection(nodeInParentsList, parentsGuardian);
    createNode(nodeInParentsList);
    
    return "OK\n";
}

int rightmostChild(int label) {
    Tree *node = getPointerToNode(label);
    List *rightChild = getPrevious(node->rightGuardian);
    
    return rightChild->label;
}

bool hasNoChildren(int label) {
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
    
    return "OK\n";
}

char* deleteSubtree(int label) {
    Tree *node = getPointerToNode(label);
    List *previousOnParentsList = getPrevious(node->nodeInParentsList);
    List *nextOnParentsList = getNext(node->nodeInParentsList);
    
    /* delete nodes from parent's list until the input node predecessor's
     * successor is input node original successor
     */
    while (getNext(previousOnParentsList) != nextOnParentsList) {
        deleteNode(getLabel(getNext(previousOnParentsList)));
    }
    
    return "OK\n";
}

char* splitNode(int labelParent, int labelNodeNextTo) {
    addNode(labelParent);
    
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
    
    return "OK\n";
}

void clean() {
    Tree *zeroNode = getPointerToNode(0);
    List *highestLeftGuardian = createListElement(-1);
    List *highestRightGuardian = createListElement(-1);
    
    setConnection(highestLeftGuardian, zeroNode->nodeInParentsList);
    setConnection(zeroNode->nodeInParentsList, highestRightGuardian);
    
    deleteSubtree(0);
    deleteListElement(highestLeftGuardian);
    deleteListElement(highestRightGuardian);
    
    return;
}

int main() {
    /*
    createNode(createListElement(0));
    printf("%d\n", rightmostChild(0));
    addNode(0);
    printf("%d\n", rightmostChild(0));
    addNode(0);
    printf("%d\n", rightmostChild(0));
    addNode(1);
    printf("%d\n", rightmostChild(1));
    addNode(3);
    printf("%d\n", rightmostChild(3));
    addNode(1);
    addNode(1);
    addNode(1);
    addNode(1);//8
    splitNode(1, 5);
    printf("%d\n", rightmostChild(1));
    printf("%d\n", rightmostChild(9));
    */
    /*
    printf("%d\n", rightmostChild(1));
    deleteNode(2);
    deleteNode(1);
    printf("%d\n", rightmostChild(0));
    deleteNode(5);
    printf("%d\n", rightmostChild(0));
    */
    /*
    deleteNode(5);
    printf("%d\n", rightmostChild(1));
    addNode(1);
    printf("%d\n", rightmostChild(1));
    deleteNode(3);
    printf("%d\n", rightmostChild(1));
    deleteNode(6);
    printf("%d\n", rightmostChild(1));
    deleteNode(1);
    deleteNode(2);
    deleteNode(4);
    */
    
    clean();
    
    
    return 0;
}