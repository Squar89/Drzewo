/* TODO check if debug mode works */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"tree.h"

#define MAX_STRING_SIZE 20
#define ADD_NODE_LENGTH 9 //8 + 1
#define RIGHTMOST_CHILD_LENGTH 16 // 15 + 1
#define DELETE_NODE_LENGTH 12 // 11 + 1
#define DELETE_SUBTREE_LENGTH 15 // 14 + 1
#define SPLIT_NODE_LENGTH 11 // 10 + 1
typedef enum { false, true } bool;


int main(int argc, char **argv) {
    bool debugMode = false;
    char inputString[MAX_STRING_SIZE];
    int firstArgument, secondArgument;
    
    if (argc >= 2) {
        char *paramString =
            (char*) malloc((strlen(argv[1]) + 1) * sizeof(char));
        strcpy(paramString, argv[1]);
        if ((strncmp(paramString, "-v", 3) == 0) && argc == 2 ) {
            debugMode = true;
        }
        else {
            printf("ERROR");
            return 1;
        }
        free(paramString);
    }
    
    setupZeroNode();
    
    while((scanf("%s", inputString)) != EOF) {
        if ((strncmp(inputString, "ADD_NODE", ADD_NODE_LENGTH)) == 0) {
            scanf("%d", &firstArgument);
            
            printf("%s\n", addNode(firstArgument));
        }
        else if ((strncmp(
            inputString, "RIGHTMOST_CHILD", RIGHTMOST_CHILD_LENGTH)) == 0) {
            
            scanf("%d", &firstArgument);
            
            printf("%d\n", rightmostChild(firstArgument));
        }
        else if ((strncmp(
            inputString, "DELETE_NODE", DELETE_NODE_LENGTH)) == 0) {
            
            scanf("%d", &firstArgument);
            
            printf("%s\n", deleteNode(firstArgument));
        }
        else if ((strncmp(
            inputString, "DELETE_SUBTREE", DELETE_SUBTREE_LENGTH)) == 0) {

            scanf("%d", &firstArgument);
            
            printf("%s\n", deleteSubtree(firstArgument));
        }
        else if ((strncmp(
            inputString, "SPLIT_NODE", SPLIT_NODE_LENGTH)) == 0) {
            
            scanf("%d  %d", &firstArgument, &secondArgument);
            
            printf("%s\n", splitNode(firstArgument, secondArgument));
        }
        if(debugMode == true) {
            fprintf(stderr, "NODES: <%d>\n", numberOfNodes);
        }
    }
    
    clean();
    
    return 0;
}

/*
ADD_NODE 0
ADD_NODE 0
ADD_NODE 1
ADD_NODE 1
ADD_NODE 0
ADD_NODE 3
RIGHTMOST_CHILD 0
RIGHTMOST_CHILD 1
ADD_NODE 4
DELETE_NODE 4
RIGHTMOST_CHILD 1
ADD_NODE 1
SPLIT_NODE 1 3
RIGHTMOST_CHILD 1
RIGHTMOST_CHILD 9
DELETE_SUBTREE 9
RIGHTMOST_CHILD 1
*/