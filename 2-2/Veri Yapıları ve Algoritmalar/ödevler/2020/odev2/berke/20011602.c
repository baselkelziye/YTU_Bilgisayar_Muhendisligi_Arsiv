#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 255

typedef struct Directory {
	char *name;
	struct Directory *parent;
	struct Directory *firstChild;
	struct Directory *nextSibling;
	struct Directory *prevSibling;
} Directory;

typedef struct Tree {
	Directory *root;
	Directory *current;
} Tree;

Directory *createDirectory(Directory *parent, char *name);
Tree *createTree();

int directoryExists(Directory *dir, char *name);
int directoryEmpty(Directory *dir);
Directory *findDirectory(Directory *parent, char *name);
void freeDirectory(Directory *dir);
void freeTree(Tree *t);

void mkdir(Tree *t, char *name);
void chdir(Tree *t, char *name);
void rmdir(Tree *t, char *name);
void dir(Tree *t);
void count(Tree *t);

int stringEquals(char *s1, char *s2);
int stringLength(char *s);
void stringCopy(char *dst, char *tar);
char *getCommand(char *s);
char *getArgument(char *s);
void checkAllocation(void *p);

int main() {
	int run;
	char *buffer, *cmd, *arg;
	Tree *t;

	run = 1;
	buffer = (char *) malloc(BUFFER_SIZE * sizeof(char));
	checkAllocation(buffer);
	t = createTree();
	printf("mkdir <name> - chdir <name> - rmdir <name> - dir - count - exit\n");
	while (run) {
		printf("> ");
		fgets(buffer, BUFFER_SIZE, stdin);
		cmd = getCommand(buffer);
		arg = getArgument(buffer);
		if (stringEquals(cmd, "exit")) run = 0;
		else if (stringEquals(cmd, "dir")) dir(t);
		else if (stringEquals(cmd, "count")) count(t);
		else if (stringEquals(cmd, "mkdir") && *arg) mkdir(t, arg);
		else if (stringEquals(cmd, "chdir") && *arg) chdir(t, arg);
		else if (stringEquals(cmd, "rmdir") && *arg) rmdir(t, arg);
		else printf("Unrecognized command.\n");
		free(cmd);
		free(arg);
	}
	free(buffer);
	freeTree(t);

	return 0;
}

Directory *createDirectory(Directory *parent, char *name) {
	int nameLength;
	Directory *dir;

	nameLength = stringLength(name);
	dir = (Directory *) malloc(sizeof(Directory));
	checkAllocation(dir);
	dir->name = (char *) malloc((nameLength + 1) * sizeof(char));
	checkAllocation(dir->name);
	stringCopy(dir->name, name);
	dir->parent = parent;
	dir->firstChild = NULL;
	dir->nextSibling = NULL;
	dir->prevSibling = NULL;

	return dir;
}

Tree *createTree() {
	Tree *t;
	Directory *root;

	t = (Tree *) malloc(sizeof(Tree));
	checkAllocation(t);
	root = createDirectory(NULL, "root");
	t->root = root;
	t->current = root;

	return t;
}

int directoryExists(Directory *dir, char *name) {
	return findDirectory(dir, name) != NULL;
}

int directoryEmpty(Directory *dir) {
	return dir->firstChild == NULL;
}

Directory *findDirectory(Directory *parent, char *name) {
	Directory *iter;

	iter = parent->firstChild;
	while (iter != NULL && !stringEquals(iter->name, name)) {
		iter = iter->nextSibling;
	}

	return iter;
}

void freeDirectory(Directory *dir) {
	Directory *iter, *temp;

	iter = dir->firstChild;
	while (iter != NULL) {
		temp = iter->nextSibling;
		freeDirectory(iter);
		iter = temp;
	}

	free(dir->name);
	free(dir);
}

void freeTree(Tree *t) {
	freeDirectory(t->root);
	free(t);
}

void mkdir(Tree *t, char *name) {
	Directory *dir, *current, *iter;

	current = t->current;
	iter = current->firstChild;
	if (iter == NULL) {
		dir = createDirectory(current, name);
		current->firstChild = dir;
	} else if (!directoryExists(current, name)) {
		while (iter->nextSibling != NULL) {
			iter = iter->nextSibling;
		}
		dir = createDirectory(current, name);
		dir->prevSibling = iter;
		iter->nextSibling = dir;
	} else {
		printf("Directory \"%s\" already exists.\n", name);
	}
}

void chdir(Tree *t, char *name) {
	Directory *current, *dir;

	current = t->current;
	if (stringEquals(name, "..")) {
		if (current->parent != NULL) {
			t->current = current->parent;
		} else {
			printf("Can not go back from the root directory.\n");
		}
	} else {
		dir = findDirectory(current, name);
		if (dir != NULL) {
			t->current = dir;
		} else {
			printf("Directory \"%s\" does not exist.\n", name);
		}
	}
}

void rmdir(Tree *t, char *name) {
	Directory *dir, *parent, *prev, *next;

	dir = findDirectory(t->current, name);
	if (dir == NULL) {
		printf("Directory \"%s\" does not exist.\n", name);
	} else if (!directoryEmpty(dir)) {
		printf("Directory \"%s\" is not empty.\n", name);
	} else {
		parent = dir->parent;
		prev = dir->prevSibling;
		next = dir->nextSibling;
		if (parent->firstChild == dir) {
			parent->firstChild = next;
		}
		if (prev != NULL) {
			prev->nextSibling = next;
		}
		if (next != NULL) {
			next->prevSibling = prev;
		}
		freeDirectory(dir);
	}
}

void dir(Tree *t) {
	Directory *current, *iter;

	current = t->current;
	iter = current->firstChild;
	while (iter != NULL) {
		printf("%s\n", iter->name);
		iter = iter->nextSibling;
	}
}

void count(Tree *t) {
	Directory *current, *iter;
	int count;

	current = t->current;
	iter = current->firstChild;
	count = 0;
	while (iter != NULL) {
		count++;
		iter = iter->nextSibling;
	}

	printf("%d\n", count);
}

int stringEquals(char *s1, char *s2) {
	int i;

	i = 0;
	while (s1[i] && s2[i] && s2[i] == s1[i]) {
		i++;
	}

	return s2[i] == s1[i];
}

int stringLength(char *s) {
	int i;

	i = 0;
	while (s[i]) {
		i++;
	}

	return i;
}

void stringCopy(char *dst, char *tar) {
	int i;
	
	i = 0;
	while (tar[i]) {
		dst[i] = tar[i];
		i++;
	}
	dst[i] = '\0';
}

char *getCommand(char *s) {
	char *cmd;
	int i;

	i = 0;
	while (s[i] && s[i] != ' ' && s[i] != '\n') {
		i++;
	}
	cmd = (char *) malloc((i + 1) * sizeof(char));
	checkAllocation(cmd);
	cmd[i--] = '\0';
	while (i >= 0) {
		cmd[i] = s[i];
		i--;
	}

	return cmd;
}

char *getArgument(char *s) {
	char *arg;

	arg = s;
	while (*arg && *arg != ' ' && *arg != '\n') {
		arg++;
	}

	return getCommand(arg + 1);
}

void checkAllocation(void *p) {
	if (p == NULL) {
		printf("Allocation error.\n");
		exit(1);
	}
}