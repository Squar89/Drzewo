#include<stdio.h>
#include<stdlib.h>
struct Node;

typedef struct Node* Tree;

struct Node {
  int value;
  Tree left, right;
};


void insert(Tree *treePtr, int x) {
  Tree t = *treePtr;
  
  if (t == NULL) {
    t = (Tree) malloc(sizeof(struct Node));
    t->value = x;
    t->left = NULL;
    t->right = NULL;
    (*treePtr) = t;
  }
  else if (x < t->value) insert(&(t->left), x);
  else if (x > t->value) insert(&(t->right), x);
  
  return;
}


void printAll(Tree t) {
  if (t != NULL) {
    if (t->left != NULL) printAll((t->left));
    printf("%d\n", t -> value);
    if (t->right != NULL) printAll((t->right));
  }
  
  return;
}


void removeAll(Tree t) {
  if (t != NULL) {
    if (t->left != NULL) removeAll((t->left));
    if (t->right != NULL) removeAll((t->right));
    free(t);
  }
  
  return;
}


int removeMin(Tree *treePtr) {
  Tree t = *treePtr;
  int val = t->value;
  
  if (t->left != NULL) val = removeMin(&(t->left));
  else if (t->right != NULL) {
    *treePtr = t->right;
    free(t->left);
    free(t);
  }
  else {
    free(t->left);
    free(t->right);
    free(t);
    *treePtr = NULL;
  }
  
  return val;
}


void removeValue(Tree *treePtr, int x) {
  Tree t = *treePtr;
  
  if (t != NULL) {
    if (x < t->value) removeValue(&(t->left), x);
    else if (x > t->value) removeValue(&(t->right), x);
    else {
      if (t->right == NULL) {
        *treePtr = t->left;
        free(t->right);
        free(t);
      }
      else {
        t->value = removeMin(&(t->right));
        *treePtr = t;
      }
    }
  }
  
  return;
}


int main() {
  int x;
  Tree t = NULL;
  
  while (scanf("%d", &x) != EOF) {
    if (x > 0) insert(&t, x);
    else if (x < 0) removeValue(&t, abs(x));
  }
  
  printAll (t);
  removeAll (t);
  
  return 0;
}