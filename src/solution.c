#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"tree.h"

#define MAX_STRING_SIZE 20
// sizes of accepted input strings used later as an argument in strncmp
#define ARG_LENGTH 3 // "-v" //2 + 1
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
        if ((strncmp(paramString, "-v", ARG_LENGTH) == 0) && argc == 2 ) {
            debugMode = true;
        }
        else {
            printf("ERROR");
            free(paramString);
            return 1;
        }
        free(paramString);
    }
    
    /* preparing zero node in our Tree 
     * for more see tree.c */
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
            fprintf(stderr, "NODES: %d\n", numberOfNodes);
        }
    }
    
    /* destroys Tree structure cleaning used memory
     * for more see tree.c */
    clean();
    
    return 0;
}