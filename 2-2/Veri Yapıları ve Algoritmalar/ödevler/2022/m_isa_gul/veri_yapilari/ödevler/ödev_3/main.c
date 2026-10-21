#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct node{
	char word[20];
	char files[100][20];
	int fileCount;
	struct node *left, *right;
} NODE;

NODE *getMin(NODE *root)
{
	if(root == NULL){
		return NULL;
	}
    if(root->left != NULL){
        return getMin(root->left);
    }
    return root;
}

NODE *newNode(char *word, char *fileName){
	NODE *tmp = (NODE*)malloc(sizeof(NODE));
	tmp->left=NULL;
	tmp->right=NULL;
	strcpy(tmp->word,word);
	tmp->fileCount=0;
	strcpy(tmp->files[tmp->fileCount],fileName);	
	tmp->fileCount++;
	
	return tmp;
}

NODE *addNode(NODE *root, char *word, char *fileName){
	int i,n;
	
	if(root == NULL){
		return newNode(word, fileName);
	}
	
	else if(root != NULL && strcmp(word,root->word)==0){
		n = root->fileCount;
		for(i=0;i<n;i++){
			if(strcmp(fileName, root->files[i]) == 0){
				return root;
			}
		}
		strcpy(root->files[root->fileCount],fileName);
		root->fileCount++;
		return root;
	}
	
	if(strcmp(word,root->word) > 0){
		root->right = addNode(root->right, word, fileName);
	}
	else if(strcmp(word,root->word) < 0){
		root->left = addNode(root->left, word, fileName);
	}
	return root;
}

NODE *searchWord(NODE *root, char *word){
	int i,n;
	NODE *tmp = root;

	while(tmp != NULL && strcmp(word,tmp->word) != 0){

		if(strcmp(word,tmp->word) > 0){
			tmp = tmp->right;	
		}
		else if(strcmp(word,tmp->word) < 0){
			tmp=tmp->left;
		}
	}
	return tmp;
}
void addFile(NODE *root){
	char newFile[20];
	char text[256];
	printf("\nEnter the file name and content:\n(<x.txt>: <w1 w2 w3>)\n");
	gets(newFile);
	gets(newFile);
	char *word = strtok(newFile, ": ");
	char *fileName = word;
	word = strtok(NULL, " ");
	
	while(word != NULL){
		addNode(root, word, fileName);
		word = strtok(NULL, " ");
		
	}
}

NODE *deleteNode(NODE *node){
	int i;
	if(node == NULL){
		return NULL;
	}
	if(node->left == NULL && node->right ==NULL){
		free(node);
		return NULL;
	}
	else if(node->left == NULL || node->right == NULL){
		NODE *tmp = node->right;
		
		if(node->left == NULL){
			tmp = node->right;
		}
		else{
			tmp=node->left;
		}
		free(node);
		return tmp;
	}
 else{
		NODE *tmp = getMin(node->right);
		strcpy(node->word,tmp->word);
		node->fileCount = tmp->fileCount;
		for(i=0;i<tmp->fileCount;i++){
			strcpy(node->files[i], tmp->files[i]);
		}
		deleteNode(tmp);
	}
	return node;
}

void deleteFile(NODE *root){
	int n;
	char fileN[20];
	char line[256];
	NODE *tmpNode;
	int i,j;
	
	printf("Enter file name to delete: ");
	gets(fileN);
	gets(fileN);
	FILE* file = fopen("test.txt", "r");
	while(fgets(line,sizeof(line),file)){
		char *word = strtok(line, ": ");
		if(strcmp(fileN,word)==0){
			char *fileName = word;
			word = strtok(NULL, " ");
			while(word != NULL){
				tmpNode = searchWord(root, word);
				i=0;
				while(strcmp(fileN,tmpNode->files[i]) != 0){
					i++;
				}
				tmpNode->fileCount--;
				n= tmpNode->fileCount;
				for(j=i;j<n;j++){
					strcpy(tmpNode->files[j], tmpNode->files[j+1]);
				}
				if(n == 0){
//					deleteNode(tmpNode);

				}
				word = strtok(NULL, " ");
				
			}
		}	
	}
	fclose(file);
}


int main(){
	int menu=-1,n,i;
	FILE* file = fopen("test.txt", "r");
	char line[256];
	char wordToSearch[20];
	NODE *node;
	
	fgets(line,sizeof(line),file);
	char *word = strtok(line, ": ");
	char *fileName = word;
	word = strtok(NULL, " ");
	NODE *root=newNode(word,fileName);
	fclose(file);
	file = fopen("test.txt", "r");
	while(fgets(line,sizeof(line),file)){
		char *word = strtok(line, ": ");
		char *fileName = word;
		word = strtok(NULL, " ");
		while(word != NULL){
			addNode(root, word, fileName);
			word = strtok(NULL, " ");
			
		}
	}
	while(menu != 0){
//		printf("\nPress any key to see menu...");
//		getch();
		printf("\n1-Add file");
		printf("\n2-Delete file");
		printf("\n3-Search word");
		printf("\n0-Exit");
		
		printf("\n\nChoice: ");
		scanf("%d", &menu);
		switch(menu){
			case 1:
				addFile(root);
				break;
			case 2:
				deleteFile(root);
				break;
			case 3:
				
				printf("Write the word to search: ");
				scanf("%s",wordToSearch);
				node = searchWord(root,wordToSearch);
				if(node == NULL){
					printf("\nNot found!\n");
				}
				else{
					n=node->fileCount;
					if(n==0){
						printf("Not found.\n");
					}
					else{
					
						printf("Files:\n");
						for(i=0;i<n;i++){
							printf("%d-%s\n",i+1,node->files[i]);
						}
					}
				}
				break;
		}
		
	}
	fclose(file);
}
