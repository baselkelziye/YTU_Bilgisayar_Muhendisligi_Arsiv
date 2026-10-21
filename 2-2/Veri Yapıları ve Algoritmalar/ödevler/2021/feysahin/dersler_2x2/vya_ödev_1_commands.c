#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tree{
	char name[10];
	struct tree *next;
	struct tree *child;
}TREE;

typedef struct path{
	char name[10];
	struct path *up;
	struct path *down;
}PATH;

TREE *createTreeNode(char *s){
	TREE *node = (TREE*)malloc(sizeof(TREE));
	if(node!=NULL){
		strcpy(node->name,s);
		node->next = NULL;
		node->child = NULL;
	}
	return node;
}

PATH *createPathNode(char *s){
	PATH *node = (PATH*)malloc(sizeof(PATH));
	if(node!=NULL){
		strcpy(node->name,s);
		node->up = NULL;
		node->down = NULL;
	}
	return node;
}

void showTree(TREE *r){
	
	if(r!=NULL){
		printf("\n%s", r->name);
		showTree(r->child);
		showTree(r->next);
	}
}

TREE *findNode(TREE *r, char *n){
	
	if(r==NULL) return NULL;
	if(strcmp(r->name,n)==0) return r;
	TREE *node;
	if((node=findNode(r->next,n)) != NULL) return node;
	return findNode(r->child,n);	
}

void showFolders(TREE *current){
	TREE *tmp = current->child;
	while(tmp!=NULL){
		printf("\nFOLDER: %s", tmp->name);
		tmp = tmp->next;
	}
}

int countFolders(TREE *current){
	TREE *tmp = current->child;
	int count=0;
	while(tmp!=NULL){
		count++;
		tmp = tmp->next;
	}
	return count;
}

int main(){
	
	TREE *root = createTreeNode("root"), *temp, *prev, *current;
	PATH *proot = createPathNode("root"), *pnode, *prtemp = proot; //prtemp: path double linked list'inin en alttaki elemanýný point eder
	
	int flag; //flag: mkdir için ilk turda kontrol amaçlý kullanýldý
	char commandLine[15], command[5], folder[10];
	
	current=root; //current: güncel konumu tutar
	
	printf("\nPress 'q' to exit\n\n\n>>");
	scanf(" %[^\n]s", commandLine);
	
	while(strcmp(commandLine, "q") != 0){
		
		sscanf(commandLine, "%s %s", command, folder);
		
		//////////////////////////////////////////////////////////////////////////////// MKDIR
		if(strcmp(command,"mkdir") == 0){
			
			//HENÜZ BÝR KLASÖRÜ YOKSA
			if(current->child==NULL){
				current->child = createTreeNode(folder);
				printf("\nNew folder '%s' is created into the folder '%s'.", folder, current->name);
				flag=0;
			}
			temp=current->child;
			
			//KLASÖR ZATEN MEVCUTSA
			while(temp != NULL && strcmp(temp->name, folder)!=0){
				prev=temp;
				temp=temp->next;
			}
			
			//KLASÖR OLUÞTURMA
			if(temp==NULL){
				prev->next = createTreeNode(folder);
				printf("\nNew folder '%s' is created into the folder '%s'.", folder, current->name);
			}
			else if(flag) printf("\nFolder already exists!\n");
			flag=1;
		}
		//////////////////////////////////////////////////////////////////////////////// CHDIR
		else if(strcmp(command,"chdir") == 0){
			
			//CHDIR ..
			if(strcmp(folder, "..")==0){
				
				if(current!=root){
					pnode = prtemp;
					prtemp = prtemp->up;
					free(pnode);
					
					current = findNode(root, prtemp->name);	
				}
				else printf("\nIt is not possible to go out of the ROOT!\n");
			}
			
			//CHDIR FOLDER
			else{
				//MEVCUDÝYET KONTROLÜ
				if(current->child != NULL){
					temp=current->child;
					while(temp != NULL && strcmp(temp->name, folder) != 0){
						temp=temp->next;
					}
					if(temp==NULL) printf("\nFolder does not exist!\n");
					else{
						current = temp;
						
						pnode = createPathNode(current->name);
						pnode->up = prtemp;
						prtemp->down=pnode;						
						prtemp = pnode;
						
						printf("\nNew current folder is: %s", current->name);
					}
				}
				else printf("\nThe folder is empty!");
			}
		}
		//////////////////////////////////////////////////////////////////////////////// RMDIR
		else if(strcmp(command,"rmdir") == 0){
			if(current->child != NULL){
				temp = current->child;
				if(strcmp(temp->name, folder) == 0){
					if(temp->child == NULL){
						current->child = current->child->next;
						free(temp);
						printf("\n%s folder is deleted.\n", folder);
					}
					else printf("\nCannot delete folder %s. The directory is not empty.\n", folder);
				}
				else{
					prev = current->child;
					temp = current->child->next;
					while(temp != NULL && strcmp(temp->name, folder) != 0){
						prev = temp;
						temp=temp->next;
					}
					if(temp==NULL) printf("\nFolder %s does not exist!\n", folder);
					else{
						if(temp->child == NULL){
							prev->next = temp->next;
							free(temp);
							printf("\n%s folder is deleted.\n", folder);
						}
						else printf("\nCannot delete folder. The directory is not empty.\n");						
					}
				}
			}
			else printf("\nCurrent folder is empty!\n");
		}
		//////////////////////////////////////////////////////////////////////////////// DIR
		else if(strcmp(command,"dir") == 0){
			showFolders(current);
		}
		/////////////////////////////////////////////////////////////////////////////// COUNT
		else if(strcmp(command,"count") == 0){
			printf("\n# of directory: %d", countFolders(current));
		}
		
		printf("\n\n>>");
		scanf(" %[^\n]s", commandLine);
	}
	printf("\n\nDIRECTREE:");
	showTree(root);
	
	return 0;
}
