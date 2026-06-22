// Kodda istenenler çok fazla olduğu için burada açıklayamıyorum. Tanımını metin belgesi olarak koyacağım. Önce onu okuyun plz
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int no;
    char name[30];
    float gpa;
    int interview;
    int english;
    int disciplinary;
} Candidate;

void add_Candidate(Candidate**, int*, int*, Candidate);
int eligible_for_internship(Candidate);
int best_Candidate(Candidate*, int);
int borderline_candidate_count(Candidate*, int);

int main (){
    Candidate newCandidate;
    int capacity = 2, guncel=0;
    Candidate *cands = (Candidate*)malloc(capacity*sizeof(Candidate));
    printf("Enter the Candidate Number (-1 for stop)");
    scanf("%d", &newCandidate.no);
    while(newCandidate.no != -1){ // Tanımda break yasak denmemiş ama biz gene de hocaları sinirlendirmeyelim :D
        printf("Candidate name:\n"); scanf("%s", newCandidate.name);
        printf("Candidate gpa:\n"); scanf("%f", &newCandidate.gpa);
        printf("Candidate interview:\n"); scanf("%d", &newCandidate.interview);
        printf("Candidate english\n"); scanf("%d", &newCandidate.english);
        printf("Candidate disciplinary\n"); scanf("%d", &newCandidate.disciplinary);
        add_Candidate(&cands, &guncel, &capacity, newCandidate);
        printf("Enter the Candidate Number (-1 for stop)"); // Yukarda while'ı başlatmak için sorduk. Burada -1 gelene kadar soruyoruz
        scanf("%d", &newCandidate.no);
    }
    int best_idx = best_Candidate(cands, guncel);
    if(best_idx != -1){
        printf("The best candidate name: %s no:%d \n", cands[best_idx].name, cands[best_idx].no);
    }else{
        printf("No eligible candidate for internship\n");
    }
    int borderline = borderline_candidate_count(cands, guncel);
    printf("Borderline candidate count: %d", borderline);
    free(cands);
    return 0;
}

void add_Candidate(Candidate** cands, int* guncel, int* capacity, Candidate newCandidate){
    if(*guncel >= *capacity){ // Pointer olarak gönderdiğimiz değerleri * ile açmalıyız (dereference)
        *capacity *= 2;
        *cands = (Candidate*)realloc(*cands, (*capacity) * sizeof(Candidate));
    }
    (*cands)[*guncel] = newCandidate;
    (*guncel)++;
}

int eligible_for_internship(Candidate cand){
    if(cand.interview >= 70 && cand.disciplinary == 0 && (cand.gpa >= 2.50 || cand.english >= 80)) return 1;
    else return 0;
}

int best_Candidate(Candidate* arr, int n){
    int i,idx=-1;
    for(i=0;i<n;i++){
        if(eligible_for_internship(arr[i])){
            if(idx == -1){ // Değerlendirmeye uygun aday bulduk mu ilkini best'imiz olarak seçelim
                idx = i;
            }else{
                if(arr[i].interview > arr[idx].interview){
                    idx = i;
                }else if(arr[i].interview == arr[idx].interview){
                    if(arr[i].gpa > arr[idx].gpa){
                        idx = i;
                    }else if(arr[i].gpa == arr[idx].gpa){
                        if(arr[i].english > arr[idx].english){
                            idx = i;
                        }
                    }
                }
            }
        }
    }
    return idx;
}

int borderline_candidate_count(Candidate* arr, int n){
    int counter = 0;
    for(int i=0;i<n;i++){
        if(eligible_for_internship(arr[i])){ // Bize arafta olan adayları soruyor, o yüzden sadece 1 şartı sağlayanları alıyoruz
            if(arr[i].gpa >= 2.50 && arr[i].english < 80) counter++;
            else if(arr[i].gpa < 2.50 && arr[i].english >= 80) counter++;
        }
    }
    return counter;
}