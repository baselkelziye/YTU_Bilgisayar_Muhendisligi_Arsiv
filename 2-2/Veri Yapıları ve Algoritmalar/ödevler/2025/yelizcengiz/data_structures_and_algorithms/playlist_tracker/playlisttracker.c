#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct Song{
	char* name;
	int time;
	int playCount;
	struct Song* prev;
	struct Song* next;
}Song;

typedef struct User{
	int songCount;
	struct Song* list;
	struct Song* listened;
	struct User* next;
}User;

int isSongOnList(char* songName,User* user);
void addUserToUsers(User* user,User** allUsers);
void addSongToAllSongs(Song* newSong,Song** allSongs);
void addSongToUserList(User* user,Song* song);
void addSongToTop10(Song* song,Song** allTop10);
void playSong(User* user,Song* song,Song** allTop10);
Song* createSong(char* name,int time);
Song* copySong(Song* song);
User* createUser();
void freeAllUsers(User** allUsers);
void freeUserSongList(Song* head);
void freeAllSongs(Song** allSongs);
void freeAllTop10(Song** allTop10);
void printAllSongs(Song** allSongs);
void printAllTop10(Song** allTop10);
void printUserSongList(User* user);
void printAllUsers(User** allUsers);
void printUserTop10List(User* user);


int main(){
	Song* allSongs=NULL;
	User* allUsers=NULL;
	Song* allTop10=NULL;
	
	User* tmpUser=allUsers;
	Song* tmpSong=allSongs;
	int i,j,k;
	int random,random1;
	int allSongCount,allUserCount;
	char tmpName[50];

	srand(time(NULL));
	printf("Sarki sayisini girin : ");
	scanf("%d",&allSongCount);
	printf("Kullanici sayisini girin : ");
	scanf("%d",&allUserCount);
	
	for(i=0;i<allSongCount;i++){
		sprintf(tmpName,"song%02d",i+1);
		random=rand()%101+100;//[100-200]
		addSongToAllSongs(createSong(tmpName,random),&allSongs);
	}
	printAllSongs(&allSongs);
	
	for(i=0;i<allUserCount;i++){
		addUserToUsers(createUser(),&allUsers);
	}
	
	tmpUser=allUsers;
	for(k=0;k<allUserCount;k++){
		tmpSong=allSongs;
		random=rand()%3+30;//[2-32]

		for(i=0;i<random;i++){
			random1=rand()%2+5;

			for(j=0;j<random1;j++){
				tmpSong=tmpSong->next;
			}
			addSongToUserList(tmpUser,tmpSong);
		}
		tmpUser=tmpUser->next;
	}
	
	printAllUsers(&allUsers);
	printf("\n-User1 Song List-\n");
	printUserSongList(allUsers);

	tmpUser=allUsers;
	for(j=0;j<allUserCount;j++){
		random1=rand()%11+tmpUser->songCount-10;//min=10 max=user playlist
		for(k=0;k<random1;k++){
			tmpSong=tmpUser->list;
			random=(rand()%tmpUser->songCount+1)-(tmpUser->songCount/2);//[-Mx/2,Mx/2]
			if(random<0){
				for(i=0;i>random;i--){
					tmpSong=tmpSong->prev;
				}
			}
			else if(random>0){
				for(i=0;i<random;i++){
					tmpSong=tmpSong->next;
				}
			}
			playSong(tmpUser,tmpSong,&allTop10);
		}
		tmpUser=tmpUser->next;
	}
	printf("\n-User1's Top10 List-\n");
	printUserTop10List(allUsers);
	
	printAllTop10(&allTop10);
	
	freeAllTop10(&allTop10);
	freeAllUsers(&allUsers);
	freeAllSongs(&allSongs);
	return 0;
}

int isSongOnList(char* songName,User* user){
	Song* tmp=user->list;
	int i=0;
	if(user->list==NULL ||user==NULL){
		return -1;
	}
	while(strcmp(tmp->name,songName)!=0 && i<user->songCount){
		tmp=tmp->next;
		i++;
	}
	if(strcmp(tmp->name,songName)==0 ){
		return 1;
	}else{
		return -1;
	}
}

void addUserToUsers(User* user,User** allUsers){
	User* tmp=*allUsers;
	if(tmp==NULL){
		user->next=NULL;
		*allUsers=user;
		return;
	}
	while(tmp->next!=NULL){
		tmp=tmp->next;
	}
	tmp->next=user;
	user->next=NULL;	
}

void addSongToAllSongs(Song* newSong,Song** allSongs){
	Song* tmp=*allSongs;
	if(tmp==NULL){
		newSong->prev=newSong;
		newSong->next=newSong;
		*allSongs=newSong;
		return;
	}
	tmp->prev->next=newSong;
	newSong->prev=tmp->prev;
	newSong->next=*allSongs;
	tmp->prev=newSong;
}

void addSongToUserList(User* user,Song* song){
	Song* newSong;Song* last;
	
	if(isSongOnList(song->name,user)<0){
		newSong=copySong(song);
		newSong->prev=NULL;
		newSong->next=NULL;
		
		if(user->list==NULL){
			newSong->prev=newSong;
			newSong->next=newSong;
			user->list=newSong;
			user->songCount++;
			return;
		}
		last=user->list->prev;
		last->next=newSong;
		newSong->prev=last;
		newSong->next=user->list;
		user->list->prev=newSong;
		
		user->songCount++;
	}
}

void addSongToTop10(Song* song,Song** allTop10){
	Song* tmp=*allTop10;
	Song* start;
	Song* newSong;
	Song *a ,*b;
	if(tmp==NULL){
		newSong=copySong(song);
		newSong->playCount=1;
		newSong->next=newSong;
		newSong->prev=newSong;
		*allTop10=newSong;
		return;
	}
	if(strcmp(tmp->name,song->name)==0){
		tmp->playCount++;
		return;
	}
	tmp=tmp->next;
	start=*allTop10;
	while(strcmp(tmp->name,song->name)!=0&&tmp!=start){
		tmp=tmp->next;
	}
	if(strcmp(tmp->name,song->name)==0){/
		tmp->playCount++;
		start=*allTop10;
		
		while(tmp->prev->playCount < tmp->playCount && tmp->prev!=(*allTop10)->prev){
			a=tmp->prev;
    		b=tmp;

    		if (a->prev) a->prev->next = b;
    		if (b->next) b->next->prev = a;

    		b->prev=a->prev;
    		a->next=b->next;
    		a->prev=b;
    		b->next=a;
    		
            if (*allTop10==a) {
                *allTop10=b;
            }
		}
	}else{
		newSong=copySong(song);
		newSong->playCount=1;
		tmp=*allTop10;
		tmp->prev->next=newSong;
		newSong->prev=tmp->prev;
		newSong->next=*allTop10;
		(*allTop10)->prev=newSong;
	}
}

void playSong(User* user,Song* song,Song** allTop10){
	Song* tmp=user->listened;
	Song *a ,*b,*newSong;
	addSongToTop10(song,allTop10);
	
	if(tmp==NULL){
		user->listened=copySong(song);
		user->listened->playCount=1;
		user->listened->next = user->listened;
    	user->listened->prev = user->listened;
    	return;
	}
	if(strcmp(tmp->name,song->name)==0){
		tmp->playCount++;
		return;
	}
	tmp=tmp->next;
	while(strcmp(tmp->name,song->name)!=0 &&tmp!=user->listened){
		tmp=tmp->next;
	}
	if(strcmp(tmp->name,song->name)==0){
		tmp->playCount++;
		
		while(tmp->prev->playCount < tmp->playCount&&tmp->prev != user->listened->prev){
			a=tmp->prev;
    		b=tmp;

    		if(a->prev) {a->prev->next=b;}
    		if(b->next) {b->next->prev=a;}

    		b->prev=a->prev;
    		a->next=b->next;
    		a->prev=b;
    		b->next=a;
    	
            if (user->listened == a) {
                user->listened = b;
            }
		}
	}else{
		newSong=copySong(song);
		user->listened->prev->next=newSong;
		newSong->playCount=1;
		newSong->prev=user->listened->prev;
		newSong->next=user->listened;
		user->listened->prev=newSong;
	}
}

Song* createSong(char* name,int time){
	Song* newSong;
	newSong=(Song*)malloc(sizeof(Song));
	
	if(newSong==NULL){return NULL;}
	
	newSong->name = (char*)malloc(strlen(name)+1);
	strcpy(newSong->name, name);
	newSong->time=time;
	newSong->playCount=0;
	newSong->prev=NULL;
	newSong->next=NULL;
	
	return newSong;
}

Song* copySong(Song* song){
	return createSong(song->name,song->time);
}

User* createUser(){
	User* user;
	user=(User*)malloc(sizeof(User));
	
	if(user==NULL){return NULL;}
	
	user->songCount=0;
	user->next=NULL;
	user->list=NULL;
	user->listened=NULL;
	return user;
}

void freeAllUsers(User** allUsers){
    User* tmp=*allUsers;
    User* toFree;
    while (tmp!=NULL) {
        toFree=tmp;
        tmp=tmp->next;
        if (toFree->list!=NULL) {
            freeUserSongList(toFree->list);
        }
        free(toFree); 
    }
    *allUsers=NULL;
}

void freeUserSongList(Song* list){
    if (list==NULL) return;
    Song* current=list;
    Song* next;

    do {
        next=current->next;
        free(current->name);
        free(current);
        current=next;
    } while(current!=list);
}

void freeAllSongs(Song** allSongs){
    Song* current=*allSongs;
    Song* start=*allSongs;
    Song* toFree;
    
    if(allSongs==NULL) {return;}
    do{
        toFree=current;
        current=current->next;

        free(toFree->name);
        free(toFree);
    } while(current!=start);
    *allSongs= NULL;
}

void freeAllTop10(Song** allTop10){
	Song* current=*allTop10;
	Song* start=*allTop10;
	Song* toFree;
	
	if(*allTop10==NULL){return;	}
	do{
		toFree=current;
		current=current->next;
		
		free(toFree->name);
		free(toFree);
	}while(current!=start);
	*allTop10=NULL;
}

void printAllSongs(Song** allSongs){
	Song* tmp=*allSongs;
	if(*allSongs==NULL){ return;}
	printf("-All Songs-\n");
	do{
		printf("Name : %s\tTime : %d.%dmin\n",tmp->name,tmp->time/60,tmp->time%60);
		tmp=tmp->next;
	}while(tmp!=*allSongs);
}

void printAllTop10(Song** allTop10){
	Song* tmp=*allTop10;
	Song* start=*allTop10;
	int i=1;
	if(start==NULL){return;}
	printf("\n-All User's Top10 List-\n");
	do{
		if((tmp->time*tmp->playCount)/3600 >0){
			printf("%d) Name : %s\tPlay Time : %d.%d.%dhour\tcount : %d\n",i,tmp->name,(tmp->time*tmp->playCount)/3600,((tmp->time*tmp->playCount)%3600)/60,(tmp->time*tmp->playCount)%60,tmp->playCount);
		}else{
			printf("%d) Name : %s\tPlay Time : %d.%dmin\tcount : %d\n",i,tmp->name,(tmp->time*tmp->playCount)/60,(tmp->time*tmp->playCount)%60,tmp->playCount);
		}
		tmp=tmp->next;
		i++;
	}while(tmp!=start && i<11);
}

void printUserSongList(User* user){
	Song* tmp=user->list;
	if(user->list==NULL){ return;}
	do{
		printf("Name : %s\tTime : %d.%dmin\n",tmp->name,tmp->time/60,tmp->time%60);
		tmp=tmp->next;
	}while(tmp!=user->list);
}

void printAllUsers(User** allUsers){
    User* tmp=*allUsers;
    int userIndex=1;

    if(tmp==NULL) {
        return;
    }
    printf("\n-All Users-\n");
    while(tmp!=NULL) {
        printf("User %d:\n",userIndex++);
        printf("Song Count : %d\n",tmp->songCount);
        tmp=tmp->next;
    }
}

void printUserTop10List(User* user){
	int i=1;
	Song* tmp=user->listened;
	if(user->listened==NULL){ return;}
	do{
		printf("%d) Name : %s\t Play Time : %d.%dmin\tcount : %d\n",i,tmp->name,(tmp->time*tmp->playCount)/60,(tmp->time*tmp->playCount)%60,tmp->playCount);
		tmp=tmp->next;
		i++;
	}while(tmp!=user->listened&&i<11);
}
