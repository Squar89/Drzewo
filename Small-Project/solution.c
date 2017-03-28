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
            (char*) malloc((strlen(argv[1]) + 1) * sizeof(char));
        strcpy(paramString, argv[1]);
        if ((strncmp(paramString, "-v", 3) == 0) && argc == 2 ) {
            debugMode = true;
        }
        else {
            printf("ERROR");
            return 1;
        }
    }
    
    return 0;
}


//strncmp(paramString, "-v", strlen("-v") + 1)
//paramString[0] == '-' && paramString[1] == 'v' 