/* pamietaj zeby przygotowac pierwszy wierzcholek recznie */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"tree.h"

typedef enum { false, true } bool;

int main(int argc, char **argv) {
    bool debugMode = false;
    if (argc >= 2) {
        char *paramString =
            (char*) malloc((strlen(argv[0]) + 1) * sizeof(char));
        strcpy(paramString, argv[0]);
        if (strcmp(paramString, "-v") && argc == 2 ) {
            debugMode = true;
        }
        else {
            printf("ERROR %d %s", argc, argv[1]);
            return 1;
        }
    }
    if(debugMode == true)printf("true");
    else printf("false");
    return 0;
}