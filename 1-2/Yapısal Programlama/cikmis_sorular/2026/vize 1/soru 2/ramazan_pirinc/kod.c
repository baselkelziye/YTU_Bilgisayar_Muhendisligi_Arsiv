// Soruda STUDENT struct'ı verilmişti. Main içinde n adet öğrencinin bilgilerini alan, sortbymane ile isme göre sıralayan ve printStudent ile ekrana yazdıran kod istenmişti
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
    float gpa;
} STUDENT;

void sort_by_name(STUDENT*,int);
void print_Students(STUDENT*,int);

int main() {
    int n;
    printf("Kaç öğrenci girilecek? ");
    scanf("%d", &n);
    STUDENT *students = (STUDENT*)malloc(n * sizeof(STUDENT));
    for (int i = 0; i < n; i++) {
        printf("\n%d. Öğrenci Bilgileri:\n", i + 1);
        printf("ID: "); scanf("%d", &students[i].id);
        printf("İsim: "); scanf(" %s", students[i].name);
        printf("Yaş: "); scanf("%d", &students[i].age);
        printf("GPA: "); scanf("%f", &students[i].gpa);
    }
    sort_by_name(students, n);
    print_Students(students, n);

    free(students);
    return 0;
}
void sort_by_name(STUDENT *s, int n) {
    STUDENT temp;
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            // strcmp > 0 ise soldaki isim alfabetik olarak daha büyüktür (Z'ye daha yakındır)
            if (strcmp(s[i].name, s[j].name) > 0) {
                temp = s[i]; // Tüm struct'ı takas ediyoruz, sadece ismi değil!
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}
void print_Students(STUDENT *s, int n) {
    for (int i=0; i<n; i++) {
        printf("%d %s %d %f\n", s[i].id, s[i].name, s[i].age, s[i].gpa);
    }
}