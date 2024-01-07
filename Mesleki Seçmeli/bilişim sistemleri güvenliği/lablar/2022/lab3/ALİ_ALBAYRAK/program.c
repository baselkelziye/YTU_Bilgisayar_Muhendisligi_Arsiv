#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

/*
  programda 4 komut bulunmaktadir
  - list (cmd_list_files) : kullanicinin dosyalarini listeler
  - read (cmd_read_file) : kullaniciya ait bir dosyayi okur, satirlardaki sayilarin toplamini yazar
  - help (cmd_help) : komut listesini gosterir
  - reset (cmd_reset) : sistemi resetler (ekrana sadece yazi yaziyor)

  programdad 2 kullanici tipi bulunmaktadir
  - user : dosya listeleme, dosya okuma yapabilmektedir
  - admin : dosya listeleme, dosya okuma, sistemi resetleme yapabilmektedir


  programdaki aciklar:
  - admin sifresini kullanmadan admin login
  - dosyadaki satirlarda buffer overflow yapilarak shell acmak


  Programa yeni dosya olusturma veya dosya yukleme secenegi eklenmemistir.
  Dosyalarin baska bir program ile yuklendigini varsayilarak ornekler uygulanmaktadir.

 */

void cmd_list_files(const char * userName);
void cmd_read_file(const char * userName, const char * fileName);
void cmd_help(int admin);
void cmd_reset();

int sum_integers(char * line);  // cmd_read_file icerisinde kullanilan fonksiyon
void read_command();  // kullanicidan komut ister
void admin_menu();  // admin'in menusu
void user_menu();  // normal kullacinin menusu


/* girilen userName ismindeki klasordeki dosyalari listeler */
void cmd_list_files(const char * userName) {
  DIR *d;
  struct dirent *dir;

  printf("files:\n");
  d = opendir(userName);
  if (d) {
    while ((dir = readdir(d)) != NULL) {
      // . ile baslamayan dosaylari gosterir
      if (dir->d_name[0] != '.') {  
	printf("%s\n", dir->d_name);
      }
    }
    closedir(d);
  } else {
    printf("user dir found\n");
  }
  printf("\n\n");
}

/* satirda ; ile ayrilmis olan sayilari okur ve toplar */
int sum_integers(char * line) {
  char buf[40];
  int sum = 0;

  char * s;
  char * d;

  strcpy(buf, line);
  // buf[39] = '\0';

  // ; karakterini arar ve aradaki stringleri integera cevirip toplar
  s = buf;
  while (s != 0) {
    d = strchr(s, ';');

    if (d == NULL)
      break;
    *d = '\0';
    sum += atoi(s);
    s = d+1;
  }
  
  return sum;
}

/*
  userName isimli klasor altindan fileName isimli dosyayi acar
  ve her satir icin sum_integers_in_line fonksiyonunu calistirir */
void cmd_read_file(const char * userName, const char * fileName) {
  char path[256];
  char line[1000];
  FILE * f;
  
  sprintf(path, "%s/%s", userName, fileName);
  printf("read file %s\n", path);
  f = fopen(path, "r");
  if (f == NULL) {
    printf("file not found\n");
    return;
  }

  while (fgets(line, 1000, f) != NULL) {
    // printf("%d\n", strlen(line));
    int s = sum_integers(line);
    printf("%d\n", s);
  }

  fclose(f);
}

void cmd_help(int admin) {
  printf("commands:\n");
  printf("  list\n");
  printf("  read FILENAME\n");
  if (admin)
    printf("  reset\n");
  printf("  exit\n");
}

char command[50];
char current_user[50];

void read_command() {
  printf(">");
  gets(command);
}

void user_menu() {

  cmd_help(0);

  while (1) {
    printf("USER MENU\n");
    read_command();

    if (strcmp(command, "help") == 0) {
      cmd_help(0);
    } else if (strcmp(command, "list") == 0) {
      cmd_list_files(current_user);
    } else if (strncmp(command, "read ", 5) == 0) {
      char fileName[100];
      strcpy(fileName, command+5);
      cmd_read_file(current_user, fileName);
    } else if (strcmp(command, "exit") == 0) {

      return;
    }
  }
}


void admin_menu() {
  cmd_help(1);

  while (1) {
    printf("ADMIN MENU\n");

    read_command();

    if (strcmp(command, "help") == 0) {
      cmd_help(1);
    } else if (strcmp(command, "list") == 0) {
      cmd_list_files(current_user);
    } else if (strcmp(command, "reset") == 0) {
      printf("delete all files & reset system!!!\n");
    } else if (strncmp(command, "read ", 5) == 0) {
      char fileName[100];
      strcpy(fileName, command+5);
      cmd_read_file(current_user, fileName);

    } else if (strcmp(command, "exit") == 0) {
      return;
    }
  }
  
}

int main() {
  int isAdmin;
  char password[20];
  char user[20];

  printf("%p %p %p\n", &isAdmin, password, user);

  // cmd_read_file("user-1", "b.txt");
  // exit(1);
  
  while (1) {
    printf("\n");
    isAdmin = 0;
    
    printf("username:");
    scanf("%s", user);

    printf("password:");
    scanf("%s", password);

    if (strcmp(user, "admin") == 0 && strcmp(password, "admin1234") == 0) {
      isAdmin = 1;
    } 

    strcpy(current_user, user);

    if (isAdmin) {
      // printf("%d\n", isAdmin);
      admin_menu();
    } else {
      if (strcmp(user, "user-1") == 0 && strcmp(password, "1234") == 0) {
	strcpy(current_user, "user-1");
      } else if (strcmp(user, "user-2") == 0 && strcmp(password, "1234") == 0) {
	strcpy(current_user, "user-2");
      } else {
	printf("incorrect username or password\n");
	continue;
      }
      
      user_menu();
    }
    
  }
  
  return 0;

}
