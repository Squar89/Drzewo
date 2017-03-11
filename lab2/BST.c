#include<stdio.h>
#include<stdlib.h>
struct Node;

typedef struct Node* Tree;

struct Node {
  int value;
  Tree left, right;
};

void insert(Tree *treePtr, int x) {
  Tree T = *treePtr;
  if(T == NULL) {
    T = (Tree) malloc(sizeof(struct Node));
    T->value = x;
    T->left = NULL;
    T->right = NULL;
    (*treePtr) = T;
  }
  else if(x < T->value) insert(&(T->left), x);
  else if(x > T->value) insert(&(T->right), x);
  return;
}

void printAll(Tree t) {
  if(t != NULL) {
    if(t->left != NULL) printAll((t->left));
    printf("%d\n", t -> value);
    if(t->right != NULL) printAll((t->right));
  }
  return;
}

void removeAll(Tree t) {
  if(t != NULL) {
    if(t->left != NULL) removeAll((t->left));
    if(t->right != NULL) removeAll((t->right));
    free(t);
  }
  return;
}


int main() {
  int x;
  Tree t = NULL;
  
  while(scanf("%d", &x) != EOF) {
    insert(&t, x);
  }
  
  printAll (t);
  removeAll (t);
  
  
  return 0;
}