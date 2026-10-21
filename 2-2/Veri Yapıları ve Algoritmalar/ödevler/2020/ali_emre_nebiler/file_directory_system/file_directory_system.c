#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20
#define display(n) printf(#n)

typedef struct node {
  char name[SIZE];
  struct node *parent;
  struct node *sibling;
  struct node *firstChild;
} NODE;

void mkdir(NODE *, char *);
NODE *chdir(NODE *, char *);
void *rmdir(NODE *, char *);
void dir(NODE *);
void count(NODE *);

// Other Functions
int searchForDir(NODE *, char *);
NODE *create_node();

int main() {
  char tmp[SIZE], *command, *name;
  int goon = 1;

  NODE *root = create_node();

  strcpy(root->name, "root");
  root->parent = NULL;
  root->firstChild = NULL;
  root->sibling = NULL;

  NODE *selected_dir = root;

  printf("\n --- OS DIRECTORY STRUCTURE ---\n");

  while (goon) {
    printf("\n  Directory:  %s\n", selected_dir->name);
    printf("\n mkdir name:  Create a new directory.");
    printf("\n chdir name:  Go to a subdirectory.");
    printf("\n rmdir name:  Delete a subdirectory.");
    printf("\n        dir:  Print the directory tree.");
    printf("\n      count:  Count subdirectories.");
    printf("\n       exit:  Exit.\n");
    printf("\n > ");
    scanf(" %[^\n]s", tmp);

    command = strtok(tmp, " ");
    name = strtok(NULL, "\n");

    if (strcmp(command, "mkdir") == 0) {
      mkdir(selected_dir, name);
    } else if (strcmp(command, "chdir") == 0) {
      selected_dir = chdir(selected_dir, name);
    } else if (strcmp(command, "rmdir") == 0) {
      rmdir(selected_dir, name);
    } else if (strcmp(command, "dir") == 0) {
      dir(selected_dir);
    } else if (strcmp(command, "count") == 0) {
      count(selected_dir);
    } else if (strcmp(command, "exit") == 0) {
      goon = 0;
    } else {
      printf("\n (!) Wrong command!");
      printf("\n (!) Please try another command.\n");
    }
  }

  return 0;
}

void mkdir(NODE *selected_dir, char *name) {
  NODE *newNode = create_node();
  NODE *tmp = create_node();
  // if the directory already exists, warn and do nothing
  if (searchForDir(selected_dir, name)) {
    printf("\n (!) A directory with this name already exists.\n");
  }
  // if the directory does not exist, start adding it
  else {
    strcpy(newNode->name, name);
    newNode->firstChild = NULL;
    newNode->sibling = NULL;
    // if there is no child, add it as a child
    if (selected_dir->firstChild == NULL) {
      selected_dir->firstChild = newNode;
      newNode->parent = selected_dir;
    }
    // if there is already a child, add it as a sibling
    else {
      tmp = selected_dir->firstChild;
      // move forward until there is no sibling
      while (tmp->sibling != NULL) {
        tmp = tmp->sibling;
      }
      // add as the new sibling
      tmp->sibling = newNode;
      newNode->parent = selected_dir;
    }
    printf("\n --> Directory added.\n");
  }
}

NODE *chdir(NODE *selected_dir, char *name) {
  NODE *tmp = create_node();
  // go to the parent directory
  if (strcmp(name, "..") == 0) {
    if (selected_dir->parent == NULL) {
      printf("\n (!) There is no parent directory.");
      printf("\n (!) Please try again.\n");
      return selected_dir;
    } else {
      printf("\n --> Directory changed.\n");
      return selected_dir->parent;
    }
  }
  // go to the subdirectory
  else {
    // if the directory exists, start selecting it
    if (searchForDir(selected_dir, name)) {
      tmp = selected_dir->firstChild;
      // move forward until the name matches
      while (strcmp(tmp->name, name) != 0) {
        tmp = tmp->sibling;
      }
      // change the directory after the search is complete
      printf("\n --> Directory changed.\n");
      return tmp;
    }
    // if the directory does not exist, warn and do nothing
    else {
      printf("\n (!) There is no directory with this name.");
      printf("\n (!) Please try again.\n");
      return selected_dir;
    }
  }
}

void *rmdir(NODE *selected_dir, char *name) {
  NODE *tmp = create_node();
  NODE *preSibling = create_node();
  // continue if the directory exists
  if (searchForDir(selected_dir, name)) {
    tmp = selected_dir->firstChild;
    // move forward until the name matches
    while (strcmp(tmp->name, name) != 0) {
      preSibling = tmp;
      tmp = tmp->sibling;
    }
    // if it has no child, perform the deletion
    if (tmp->firstChild == NULL) {
      // if it is the first child, update the first child
      if (tmp->parent != NULL) {
        tmp->sibling->parent = tmp->parent;
        tmp->parent->firstChild = tmp->sibling;
      }
      // otherwise connect the adjacent siblings
      else {
        preSibling->sibling = tmp->sibling;
      }
    }
    // if it has a child, warn and do nothing
    else {
      printf("\n (!) This directory has subdirectories.\n");
    }
  }
  // if the directory does not exist, warn and do nothing
  else {
    printf("\n (!) There is no directory with this name.\n");
  }
}

void dir(NODE *selected_dir) {
  NODE *tmp = create_node();
  if (selected_dir->firstChild != NULL) {
    tmp = selected_dir->firstChild;
    printf("\n --- Subdirectories ---");
    do {
      printf("\n --> %s", tmp->name);
      tmp = tmp->sibling;
    } while (tmp != NULL);
    printf("\n");
  } else {
    printf("\n (!) There are no subdirectories.\n");
  }
}

void count(NODE *selected_dir) {
  NODE *tmp = create_node();
  int counter = 0;
  if (selected_dir->firstChild != NULL) {
    tmp = selected_dir->firstChild;
    do {
      counter++;
      tmp = tmp->sibling;
    } while (tmp != NULL);
  }
  printf("\n --> Number of Subdirectories: %d\n", counter);
}

// Other Functions
int searchForDir(NODE *selected_dir, char *name) {
  int found = 0;
  NODE *tmp = create_node();
  tmp = selected_dir->firstChild; // first child of the directory
  // if there is a child, start the search
  if (tmp != NULL) {
    // continue searching while siblings remain and the name is not found
    do {
      if (strcmp(tmp->name, name) == 0) {
        found = 1;
      }
      tmp = tmp->sibling;
    } while (tmp != NULL && found == 0);
  }
  return found;
}

NODE *create_node() { return (NODE *)malloc(sizeof(NODE)); }
