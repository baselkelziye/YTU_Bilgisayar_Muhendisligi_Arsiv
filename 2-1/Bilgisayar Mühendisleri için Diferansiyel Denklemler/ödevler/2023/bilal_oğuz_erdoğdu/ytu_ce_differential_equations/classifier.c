#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>		//for random number generator
#include <ctype.h>		//used only to make text lowercase

#define MAX_LENGTH 511
#define MAX_QUOTE 200
#define DICT_SIZE 2500
#define TRAIN_PERC 0.8

//1 means Hayyam, -1 means Shakespeare.

int compute_number_of_words(char *text);
void text_to_vector(char **dictionary, char **quotes, int **vectors, int wordcount) ;
void remove_punctuation(char *text);
void remove_multiple_spaces(char *text, int tlen);
void organize_text(char *text);
void slide_text(char *text, int tlen, int start, int step, int direction);
int fill_dictionary(char **wordsdic, char **quotes);
int check_occurence(char **dictionary, char *word, int check_until);
void make_lowercase(char **quotes);
void organize_add(char **quotes);

double dot_product(int *vector, double *parameters, int wordcount);
double compute_func(int *vector, double *parameters, int wordcount);
void initiate_param(double *parameters, int wordcount, double param);
void initiate_labels(int *labels);

void gradiend_descent(int **vectors, double *parameters, int wordcount, int *labels, double stepsize, int maxiter, double error, char **quotes, FILE *file);
void stoc_grad_desc(int **vectors, double *parameters, int wordcount, int *labels, double stepsize, int maxiter, double error, char **quotes,  FILE *file);
void adam(int **vectors, double *parameters, int wordcount, int *labels, double stepsize, int maxiter, double error, double beta1, double beta2, double epsilon, char **quotes,  FILE *file);

double compute_loss(int *vector, double *parameters, int wordcount, int *labels);

double test_accuracy(char **texts, int **vectors, double *parameters, int *labels, int wordcount);
double train_accuracy(char **texts, int **vectors, double *parameters, int *labels, int wordcount);


int main(){
	int i=0, j;
	FILE *fptr;
	
	fptr = fopen("datas.txt", "r");
	if( fptr == NULL ){
		printf("File couldn't be opened. Exiting.");
		return 1;
	}

	char **quotes, **wordsdic;
	int **wordvectors, *labels;	
	double *parameters;
	

	quotes = (char**) malloc(MAX_QUOTE*sizeof(char*));				//Allocating memory for quotes, dictionary and vectors.
	if(quotes == NULL){
		printf("Memory allocation failed. Exiting.");
		return 1;
	}
	for( i=0; i<MAX_QUOTE; i++ ){
		quotes[i] = (char*) malloc(MAX_LENGTH*sizeof(char));
	}
	
	wordsdic = (char**)malloc(DICT_SIZE*sizeof(char*));
	if(wordsdic == NULL){
		printf("Memory allocation failed. Exiting.");
		return 1;
	}
	for( i=0; i<DICT_SIZE; i++ ){
		wordsdic[i] = (char*) malloc(MAX_LENGTH*sizeof(char));
	}
	
	wordvectors = (int**) malloc(MAX_QUOTE*sizeof(int*));
	if(wordvectors == NULL){
		printf("Memory allocation failed. Exiting.");
		return 1;
	}
	for( i=0; i<MAX_QUOTE; i++ ){
		wordvectors[i] = (int*) malloc(DICT_SIZE*sizeof(int));
	}
	
	for( i=0; i<MAX_QUOTE; i++ ){
		fgets(quotes[i], MAX_LENGTH, fptr);
	}
	fclose(fptr);
	
	labels = (int*) malloc(MAX_QUOTE*sizeof(int));
	if(labels == NULL){
		printf("Memory allocation failed. Exiting.");
		return 1;
	}
	

	for( i=0; i<MAX_QUOTE; i++ ){
		remove_punctuation(quotes[i]);
		remove_multiple_spaces(quotes[i], strlen(quotes[i]));
	}
	make_lowercase(quotes);
	organize_add(quotes);
	
	int wordcount = fill_dictionary(wordsdic, quotes); 
	text_to_vector(wordsdic, quotes, wordvectors, wordcount);
	
	parameters = (double*) malloc(wordcount*sizeof(double));
	if( parameters == NULL ){
		printf("Memory allocation failed. Exiting."); 
		return 1;
	}	
	initiate_labels(labels);
	
	int choice;
	printf("This program fits parameters using eithet gradient descenet (1), stochastic gradient descent (2) or adam (3).\nEnter corresponding number to do five trainings with different parameter initialization.\nChoice: ");
	scanf("%d", &choice);
	
	if( choice == 1 ){
		char filename_format[] = "gd_results_parameters_%d.txt";
		char filename[sizeof(filename_format) + 3];
		int k;
		for (k = 0; k < 5; k++) {
			initiate_param(parameters, wordcount, 0.0+k*0.05);
		    snprintf(filename, sizeof(filename), filename_format, k); 
		    FILE *fr = fopen(filename, "w");
			
		    if (!fr)
		        break;
		    gradiend_descent(wordvectors, parameters, wordcount, labels,  0.075, 200, 0.001, quotes, fr);	
			
		    fclose(fr);
		}
	} else if( choice == 2 ){
		char filename_format[] = "sgd_results_parameters_%d.txt";
		char filename[sizeof(filename_format) + 3];
		int k;
		for (k = 0; k < 5; k++) {
			initiate_param(parameters, wordcount, 0.0+k*0.05);
		    snprintf(filename, sizeof(filename), filename_format, k); 
		    FILE *fr = fopen(filename, "w");
			
		    if (!fr)
		        break;
			stoc_grad_desc(wordvectors, parameters, wordcount, labels, 0.1, 1000, 0.001, quotes, fr);
			
		    fclose(fr);
		}
	} else if( choice == 3 ){
		char filename_format[] = "adam_results_parameters_%d.txt";
		char filename[sizeof(filename_format) + 3];
		int k;
		for (k = 0; k < 5; k++) {
			initiate_param(parameters, wordcount, 0.0+k*0.05);
		    snprintf(filename, sizeof(filename), filename_format, k); 
		    FILE *fr = fopen(filename, "w");
			
		    if (!fr)
		        break;
			adam(wordvectors, parameters, wordcount, labels, 0.01, 100, 0.001, 0.9, 0.999, 0.01, quotes, fr);
			
		    fclose(fr);
		}
	}
	
	
	for( i=0; i<MAX_QUOTE; i++ ){
		free(quotes[i]);
	}
	free(quotes);
	for( i=0; i<DICT_SIZE; i++ ){				//FREEING MEMORY.
		free(wordsdic[i]);
	}
	free(wordsdic);
	for( i=0; i<MAX_QUOTE; i++ ){
		free(wordvectors[i]);
	}
	free(wordvectors);
	
	return 0;
}

void gradiend_descent(int **vectors, double *parameters, int wordcount, int *labels, double stepsize, int maxiter, double error, char **quotes, FILE *file) {
    int i = 0, t, z;
    double y_hat_std, y_std, gradient, total_loss = 0, last_loss, test_acc, train_acc;
    FILE *fptr;
	fptr = fopen("gd_times.txt", "w");
	time_t t0, t1;
	t0 = time(0);
	printf("Using Gradient Descent to update parameters.\n");
    do {
        last_loss = total_loss;
        total_loss = 0;

        for (t = 0; t < wordcount; t++) {
            gradient = 0;

            for (z = 0; z < MAX_QUOTE * TRAIN_PERC; z++) {
                y_std = (labels[z] + 1) / 2;
                y_hat_std = (compute_func(vectors[z], parameters, wordcount) + 1) / 2;

                gradient += (y_hat_std - y_std) * vectors[z][t];
            }
		
            gradient /= MAX_QUOTE*TRAIN_PERC;
            parameters[t] -= stepsize * gradient;
            fprintf(file, "%f ", parameters[t]);
        }
        fprintf(file, "\n");
		
        for (t = 0; t < MAX_QUOTE * TRAIN_PERC; t++) {
            total_loss += compute_loss(vectors[t], parameters, wordcount, labels);
        }
        total_loss /= MAX_QUOTE*TRAIN_PERC;
		fprintf(fptr, "%d ", t1-t0);
        printf("Iteration %d: Loss: %lf\n", i + 1, fabs(total_loss));
        t1 = time(0);
        if( (i+1) % 10 == 0 ){
        	train_acc = train_accuracy(quotes, vectors, parameters, labels, wordcount);
			test_acc = test_accuracy(quotes, vectors, parameters, labels, wordcount);
			printf("\nTraining set accuracy: %lf      Test set accuracy: %lf      Loss: %lf    Time: %d\n", train_acc, test_acc, total_loss, t1-t0);
			fprintf(fptr, "%d ", t1-t0);
		}

        i++;
    } while ((fabs(total_loss - last_loss) > error || i == 1) && i < maxiter);

    if (i < maxiter) {
        printf("\nModel successfully converged at %d. iteration.\n", i);
    } else {
        printf("\nModel training lasted for a full %d iterations.\n", maxiter);
    }
    test_accuracy(quotes, vectors, parameters, labels, wordcount);
}

void stoc_grad_desc(int **vectors, double *parameters, int wordcount, int *labels, double stepsize, int maxiter, double error, char **quotes, FILE *file){
	int i=0, t, z, chosen, j;
	double y_hat_std, y_std, gradient, total_loss=0, last_loss, test_acc, train_acc;
	srand(time(NULL));
	
	FILE *fptr;
	fptr = fopen("sgd_times.txt", "w");
	time_t t0, t1;
	t0 = time(0);
	printf("Using Stochastic Gradient Descent to update parameters.");
	do{
		last_loss = total_loss;
		total_loss = 0;
		
		chosen = rand()%MAX_QUOTE*TRAIN_PERC;
		y_std = (labels[chosen]+1) / 2;
		y_hat_std = ( compute_func(vectors[chosen], parameters, wordcount)+1 ) / 2;
		
		for( j=0; j<wordcount; j++ ){
			gradient = ( y_hat_std - y_std ) * vectors[chosen][j];
			parameters[j] -= stepsize*gradient;
			fprintf(file, "%f ", parameters[j]);
		}
		fprintf(file, "\n", parameters[j]);
		
		total_loss = 0;
		for( t=0; t<MAX_QUOTE*TRAIN_PERC; t++ ){
			total_loss += compute_loss(vectors[t], parameters, wordcount, labels);
		}
		total_loss /= MAX_QUOTE*TRAIN_PERC;
		printf("\nIteration %d: 	Loss: %lf", i+1, fabs(total_loss));
		t1 = time(0);
        if( (i+1) % 10 == 0 ){
        	train_acc = train_accuracy(quotes, vectors, parameters, labels, wordcount);
			test_acc = test_accuracy(quotes, vectors, parameters, labels, wordcount);
			printf("\nTraining set accuracy: %lf      Test set accuracy: %lf      Loss: %lf    Time: %d\n", train_acc, test_acc, total_loss, t1-t0);
			fprintf(fptr, "%d ", t1-t0);
		}
		
		stepsize *=	0.975;	i++;
	} while( ( fabs(total_loss - last_loss) > error || i==1 ) && i<maxiter );
	
	if( i < maxiter ){
		printf("\nModel succesfully converged at %d. iteration.", i);
	}
	else{
		printf("\nModel training lasted for a full %d iterations.", maxiter);
	}
	test_accuracy(quotes, vectors, parameters, labels, wordcount);
	
}

void adam(int **vectors, double *parameters, int wordcount, int *labels, double stepsize, int maxiter, double error, double beta1, double beta2, double epsilon, char **quotes,  FILE *file){
	int i, t, z;
	double gradient, total_loss=0, last_loss, *m, *v, m_hat, v_hat, y_std, y_hat_std, tmp, test_acc, train_acc;
	m = (double*) malloc(wordcount*sizeof(double));
	v = (double*) malloc(wordcount*sizeof(double));
	if( v == NULL || m == NULL ){
		printf("\nMemory allocation failed. Exiting.");
		exit(1);
	}
	int j;
	
	for( i=0; i<wordcount; i++ ){
		m[i] = 0;    v[i] = 0;
	}
	i=0;    epsilon = 0.000001;
	
	FILE *fptr;
	fptr = fopen("adam_times.txt", "w");
	time_t t0, t1;
	t0 = time(0);
	
	printf("Using Adam to update parameters.");
	do{
		last_loss = total_loss;
		total_loss = 0;
		
		for( t=0; t<wordcount; t++ ){
			gradient = 0;

            for (z = 0; z < MAX_QUOTE * TRAIN_PERC; z++) {
                y_std = (labels[z] + 1) / 2;
                y_hat_std = (compute_func(vectors[z], parameters, wordcount) + 1) / 2;

                gradient += (y_hat_std - y_std) * vectors[z][t];
            }
            gradient /= MAX_QUOTE*TRAIN_PERC;

			m[t] = beta1*m[t] + ( 1-beta1 )*gradient;
			v[t] = beta2*v[t] + ( 1-beta2 )* (gradient*gradient);
			tmp =  1-pow(beta1, (i+1));
			if( tmp == 0 )    tmp += 0.000001;
			m_hat = m[t] / tmp;
			tmp = 1-pow(beta2, (i+1));
			if( tmp == 0 )    tmp += 0.000001;
			v_hat = v[t] / tmp;
			
			parameters[t] -= stepsize * m_hat / (sqrt(v_hat) + epsilon);
			fprintf(file, "%f ", parameters[t]);
		}
		fprintf(file, "\n", parameters[t]);
		
		
		total_loss = 0;
		for( t=0; t<MAX_QUOTE*TRAIN_PERC; t++ ){
			total_loss += compute_loss(vectors[t], parameters, wordcount, labels);
		}
		total_loss /= MAX_QUOTE*TRAIN_PERC;
		printf("\nIteration %d: 	Loss: %lf", i+1, fabs(total_loss));
		
		t1 = time(0);
        if( (i+1) % 10 == 0 ){
        	train_acc = train_accuracy(quotes, vectors, parameters, labels, wordcount);
			test_acc = test_accuracy(quotes, vectors, parameters, labels, wordcount);
			printf("\nTraining set accuracy: %lf      Test set accuracy: %lf      Loss: %lf    Time: %d\n", train_acc, test_acc, total_loss, t1-t0);
			fprintf(fptr, "%d ", t1-t0);
		}
		stepsize *= 0.925;
		i++;
	} while( ( fabs(total_loss - last_loss) > error || i==1 ) && i<maxiter );
	
	if( i < maxiter ){
		printf("\nModel succesfully converged at %d. iteration.", i);
	}
	else{
		printf("\nModel training lasted for a full %d iterations.", maxiter);
	}
	

    free(m);
    free(v);
	
}

double test_accuracy(char **texts, int **vectors, double *parameters, int *labels, int wordcount){
	int i, j;
	double prediction, prediction_std, accuracy=0;
	for( i=MAX_QUOTE*TRAIN_PERC; i<MAX_QUOTE; i++ ){
		prediction = compute_func(vectors[i], parameters, wordcount);
		if( fabs( 1.0*labels[i] - prediction ) < 1 ){
			accuracy++;
		}
	}
	accuracy /= MAX_QUOTE*(1-TRAIN_PERC);
	return accuracy*100;
	
}

double train_accuracy(char **texts, int **vectors, double *parameters, int *labels, int wordcount){
	int i, j;
	double prediction, accuracy = 0;
	for( i=0; i<MAX_QUOTE*TRAIN_PERC; i++ ){
		prediction = compute_func(vectors[i], parameters, wordcount);
		if( fabs( 1.0*labels[i] - prediction ) < 1 ){
			accuracy++;
		}
	}
	accuracy /= MAX_QUOTE*TRAIN_PERC;
	return accuracy*100;
	
}


double compute_loss(int *vector, double *parameters, int wordcount, int *labels){
	int i;
	double loss, fx = compute_func(vector, parameters, wordcount);
	double fx_std = (fx+1.0) / 2.0;
	
	if( fx_std == 0 ) fx_std += 0.00001;
	if( fx_std == 1 ) fx_std -= 0.00001;
	for( i=0; i<MAX_QUOTE*TRAIN_PERC; i++ ){
		loss = - labels[i]*log (fx_std) - ( 1-labels[i] )*log( 1-fx_std );
	}
	return loss;
}

double dot_product(int *vector, double *parameters, int wordcount){
	int i;
	double result = 0;
	for( i=0; i<wordcount; i++ ){
		result += vector[i]*parameters[i];
	}
	return result;
}

double compute_func(int *vector, double *parameters, int wordcount){
	double dot = dot_product(vector, parameters, wordcount);
	return tanh(dot);
}

void initiate_param(double *parameters, int wordcount, double value){
	int i;
	double random_value;
	srand(time(NULL));
	for( i=0; i<wordcount; i++ ){
		parameters[i] = value;
	}
}

void initiate_labels(int *labels){
	int i;
	for( i=0; i<MAX_QUOTE/2*TRAIN_PERC; i++ ){
		labels[i] = 1;
	}
	for( i=MAX_QUOTE/2*TRAIN_PERC; i<MAX_QUOTE*TRAIN_PERC; i++ ){
		labels[i] = -1;
	}
	for( i=MAX_QUOTE*TRAIN_PERC; i< MAX_QUOTE-MAX_QUOTE*(1-TRAIN_PERC)/2; i++ ){
		labels[i] = 1;
	}
	for( i=MAX_QUOTE-MAX_QUOTE*(1-TRAIN_PERC)/2; i<MAX_QUOTE; i++ ){
		labels[i] = -1;
	}
}

int fill_dictionary(char **dictionary, char **quotes) {
    int i, j, count = 0, tmp = 0;
    char word[MAX_LENGTH];

    for (i = 0; i < MAX_QUOTE; i++) {
        j = 0;
        while (quotes[i][j] != '\0' && quotes[i][j] != '\n' ) {
            if (quotes[i][j] != ' ') {
                word[tmp] = quotes[i][j];
                tmp++;
                j++;
            } else {
                word[tmp] = '\0';
                if( check_occurence(dictionary, word, count) != 1 ){
                	strncpy(dictionary[count], word, tmp);
                	count++;
				}
                tmp = 0;
                j++;
            }
        }
        if (tmp > 0) {
            word[tmp] = '\0';
            if( check_occurence(dictionary, word, count) != 1 ){
               	strncpy(dictionary[count], word, tmp);
               	count++;
			}
			tmp = 0;
        }
    }
    return count;
}

int check_occurence(char **dictionary, char *word, int check_until){
	int i=0;
	while( i<check_until){
		if( strcmp(dictionary[i], word) == 0 ){
			return 1;
		}
		i++;
	}
	return 0;
}

int compute_number_of_words(char *text){
	int count = 0, len = strlen(text), i;
	for( i=0; i<len; i++ ){
		if( text[i] == ' ' ){
			count++;
		}
	}
	
	return count+1;
}

void remove_punctuation(char *text){
	const char *punctuations = "!()-[]{};:??,<>./?@#$%^&*\"_~?-";
	int i=0, len = strlen(text);
	while( i<len && text[i] != '\0' ){
		if( strchr(punctuations, text[i]) ){
			text[i] = ' ';
		}
		i++;
	}
}

void remove_multiple_spaces(char *text, int tlen){
	int i=0, j, tmp;
	while( text[i++] != '\0' ){
		if( text[i] == ' ' ){
			tmp = 0;
			j = i;
			while( text[j++] == ' ' ){
				tmp++;
			}
			if( tmp > 1 ){
				slide_text(text, tlen, i, tmp-1, 1);
			}			
		}
	}
}

void make_lowercase(char **quotes){
	int i, j, len;
	for( i=0; i<MAX_QUOTE; i++ ){
		len = strlen(quotes[i]);
		j=0;
		while( j<len && quotes[i][j] != '\0' ){
			quotes[i][j] = tolower(quotes[i][j]);
			j++;
		}
	}
}

void text_to_vector(char **dictionary, char **quotes, int **vectors, int wordcount) {
	int i, j;
	for( i=0; i<MAX_QUOTE; i++ ){
		for( j=0; j<wordcount; j++ ){
			if( strstr( quotes[i], dictionary[j] )){
				vectors[i][j] = 1;
			}
			else{
				vectors[i][j] = 0;
			}
		}
	}
}


void slide_text(char *text, int tlen, int start, int step, int direction){
	int i, end = strlen(text);	
	if( direction == 1 ){
		for( i=start; i<end; i++ ){
			text[i] = text[i+step];
		}
		text[i] = '\0';
	}
	else if( direction == 0 ){
		for( i=tlen; i>start; i-- ){
			text[i+step] = text[i];
		}
		text[tlen+step-1] = '\0';
	}
}

void organize_add(char **quotes){
	int i, j, len;
	for( i=0; i<MAX_QUOTE; i++ ){
		len = strlen(quotes[i]);
		j=0;
		while( j<len && quotes[i][j] != '\0' ){
			if( quotes[i][j] == '\'' ){
				if( quotes[i][j-1] == 'n' && quotes[i][j+1] == 't' ){		//NOT
					slide_text(quotes[i], strlen(quotes[i]), j, 1, 0);
					quotes[i][j-1] = ' '; quotes[i][j] = 'n'; quotes[i][j+1] = 'o'; quotes[i][j+2] = 't'; quotes[i][j+3] = ' ';
				}
				else if( quotes[i][j+1] == 'v' && quotes[i][j+2] == 'e' ){		//HAVE
					slide_text(quotes[i], strlen(quotes[i]), j, 2, 0);
					quotes[i][j] = ' ';  quotes[i][j+1] = 'h';  quotes[i][j+2] = 'a';  quotes[i][j+3] = 'v';  quotes[i][j+4] = 'e';  quotes[i][j+5] = ' ';  
				}
			}
			j++;
		}
	}
}
