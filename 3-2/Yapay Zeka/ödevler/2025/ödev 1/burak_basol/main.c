//...............................Includes Start................................//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <math.h>

//...............................Includes Stop.................................//

//................................Defines Start................................//

#define DEBUG_MODE // Disable for normal mode

#define GENERATION 50
#define PATTERN_COUNT 7
#define PATTERN_SIDE 3
#define PATTERN_SIZE (PATTERN_SIDE * PATTERN_SIDE)
#define IMAGE_COUNT 5
#define IMAGE_SIDE 24
#define IMAGE_SIZE (IMAGE_SIDE * IMAGE_SIDE)

//................................Defines Stop.................................//

//..............................Prototypes Start...............................//

void generate_population(int POPULATION);
void read_images();
void file_Init();
void evaluate(int POPULATION);
void selection(int POPULATION, int *fitness_scores);
void cross_over(int POPULATION);
void mutation(int POPULATION, float MUTATION_RATE);
void save_best_individual();
void save_patterns_to_csv(const char *filename);
void save_fitness_progress_to_csv(const char *filename);
void save_reconstructed_images_info(const char *filename);

//..............................Prototypes Stop................................//

//...........................Global Variables Start............................//

int i, j;
int **population;
int *images;
int *fitness_scores;
int best[] = { 0, 0 };
int generation_best_fitness[GENERATION];
int best_individual_patterns[PATTERN_COUNT * PATTERN_SIZE];
float avg_fitness_per_generation[GENERATION];
FILE *IMAGES;

//...........................Global Variables Stop.............................//

//..............................User Code Start................................//

int main() {
    srand(time(NULL));

    int populations[] = { 50, 100, 200 };
    float mutation_rates[] = { 0.01, 0.05, 0.1 };

    char prefix[100];
    char command[200];

    for (int pi = 0; pi < sizeof(populations) / sizeof(int); pi++) {
        for (int mi = 0; mi < sizeof(mutation_rates) / sizeof(float); mi++) {

            int POPULATION = populations[pi];
            float MUTATION_RATE = mutation_rates[mi];

            sprintf(prefix, "run_pop%d_mut%.2f_", POPULATION, MUTATION_RATE);

            population = (int **)malloc(POPULATION * sizeof(int *));
            for (i = 0; i < POPULATION; i++) {
                population[i] = (int *)malloc(PATTERN_COUNT * PATTERN_SIZE * sizeof(int));
            }

            images = (int *)calloc(IMAGE_COUNT * IMAGE_SIZE, sizeof(int));
            fitness_scores = (int *)calloc(POPULATION, sizeof(int));
            best[0] = INT_MAX;

            file_Init();
            generate_population(POPULATION);

            for (i = 0; i < GENERATION; i++) {
                #ifdef DEBUG_MODE
                printf("\nGeneration %d start\n\n", i);
                #endif
                evaluate(POPULATION);
                float sum_fitness = 0;
                for (j = 0; j < POPULATION; j++)
                    sum_fitness += fitness_scores[j];
                avg_fitness_per_generation[i] = sum_fitness / POPULATION;
                generation_best_fitness[i] = best[0];
                #ifdef DEBUG_MODE
                printf("Best fitness: %d, Avg fitness: %.2f\n", best[0], avg_fitness_per_generation[i]);
                #endif
                selection(POPULATION, fitness_scores);
                cross_over(POPULATION);
                mutation(POPULATION, MUTATION_RATE);
            }

            FILE *f;

            char patterns_file[128];
            sprintf(patterns_file, "%spatterns.csv", prefix);
            save_patterns_to_csv(patterns_file);

            char fitness_file[128];
            sprintf(fitness_file, "%sfitness_progress.csv", prefix);
            save_fitness_progress_to_csv(fitness_file);

            char images_file[128];
            sprintf(images_file, "%sreconstructed_images.csv", prefix);
            save_reconstructed_images_info(images_file);

            sprintf(command, "python analyze.py %s", prefix);
            system(command);

            for (i = 0; i < POPULATION; i++) free(population[i]);
            free(population); free(images); free(fitness_scores);
        }
    }

    return 0;
}

//..............................User Code Stop................................//

//..........................Genetic Algorithm Start............................//

void generate_population(int POPULATION) {
    for (int i = 0; i < POPULATION; i++) {
        for (int j = 0; j < PATTERN_COUNT; j++) {
            for (int k = 0; k < PATTERN_SIZE; k++) {
                population[i][j * PATTERN_SIZE + k] = rand() % 2;
            }
        }
    }
}

void evaluate(int POPULATION) {
    for (int i = 0; i < POPULATION; i++) {
        int total_loss = 0;
        for (int image_index = 0; image_index < IMAGE_COUNT; image_index++) {
            for (int block_row = 0; block_row < IMAGE_SIDE / PATTERN_SIDE; block_row++) {
                for (int block_col = 0; block_col < IMAGE_SIDE / PATTERN_SIDE; block_col++) {
                    int min_distance = INT_MAX;
                    for (int pattern_index = 0; pattern_index < PATTERN_COUNT; pattern_index++) {
                        int distance = 0;
                        for (int bi = 0; bi < PATTERN_SIDE; bi++) {
                            for (int bj = 0; bj < PATTERN_SIDE; bj++) {
                                int image_pixel = images[image_index * IMAGE_SIZE + (block_row * PATTERN_SIDE + bi) * IMAGE_SIDE + (block_col * PATTERN_SIDE + bj)];
                                int pattern_pixel = population[i][pattern_index * PATTERN_SIZE + bi * PATTERN_SIDE + bj];
                                if (image_pixel != pattern_pixel) distance++;
                            }
                        }
                        if (distance < min_distance) min_distance = distance;
                    }
                    total_loss += min_distance;
                }
            }
        }
        fitness_scores[i] = total_loss;
        if (total_loss < best[0]) {
            best[0] = total_loss;
            best[1] = i;
            save_best_individual();
        }
    }
}

void selection(int POPULATION, int *fitness_scores) {
    int **new_population = (int **)malloc(POPULATION * sizeof(int *));
    for (int i = 0; i < POPULATION; i++) {
        new_population[i] = (int *)malloc(PATTERN_COUNT * PATTERN_SIZE * sizeof(int));
        int c1 = rand() % POPULATION;
        int c2 = rand() % POPULATION;
        int selected = fitness_scores[c1] < fitness_scores[c2] ? c1 : c2;
        memcpy(new_population[i], population[selected], PATTERN_COUNT * PATTERN_SIZE * sizeof(int));
    }
    for (int i = 0; i < POPULATION; i++) {
        memcpy(population[i], new_population[i], PATTERN_COUNT * PATTERN_SIZE * sizeof(int));
        free(new_population[i]);
    }
    free(new_population);
}

void cross_over(int POPULATION) {
    for (int i = 0; i < POPULATION; i += 2) {
        if (i + 1 >= POPULATION) continue;
        if (rand() % 100 < 70) {
            int cp = rand() % PATTERN_COUNT;
            for (int j = cp; j < PATTERN_COUNT; j++) {
                for (int k = 0; k < PATTERN_SIZE; k++) {
                    int tmp = population[i][j * PATTERN_SIZE + k];
                    population[i][j * PATTERN_SIZE + k] = population[i + 1][j * PATTERN_SIZE + k];
                    population[i + 1][j * PATTERN_SIZE + k] = tmp;
                }
            }
        }
    }
}

void mutation(int POPULATION, float MUTATION_RATE) {
    for (int i = 0; i < POPULATION; i++) {
        for (int j = 0; j < PATTERN_COUNT; j++) {
            for (int k = 0; k < PATTERN_SIZE; k++) {
                if ((rand() % 100) < (MUTATION_RATE * 100)) {
                    population[i][j * PATTERN_SIZE + k] ^= 1;
                }
            }
        }
    }
}

void save_best_individual() {
    memcpy(best_individual_patterns, population[best[1]], PATTERN_COUNT * PATTERN_SIZE * sizeof(int));
}

//..........................Genetic Algorithm Stop............................//

//.............................Image Functions Start............................//

void file_Init() {
    IMAGES = fopen("images.txt", "r");
    if (IMAGES == NULL) {
        printf("There's an error occurred during the file opening. Exiting...\n");
        exit(1);
    }
    read_images();
    fclose(IMAGES);
}

void read_images() {
    int i, j, k;
    char buffer[IMAGE_SIDE + 2];
    for (i = 0; i < IMAGE_COUNT; i++) {
        for (j = 0; j < IMAGE_SIDE; j++) {
            if (fgets(buffer, IMAGE_SIDE + 2, IMAGES) == NULL) {
                printf("\nError reading value\n");
            }
            for (k = 0; k < IMAGE_SIDE; k++) {
                *(images + (i * IMAGE_SIZE) + (j * IMAGE_SIDE) + k) = buffer[k] - '0';
            }
        }
    }
}

//.............................Image Functions Stop.............................//

//...........................Saving Functions Start...........................//

void save_patterns_to_csv(const char *filename) {
    FILE *patterns_file = fopen(filename, "w");
    if (patterns_file == NULL) {
        printf("Error opening patterns.csv file\n");
        return;
    }
    fprintf(patterns_file, "Pattern,Row,Col,Value\n");
    for (int p = 0; p < PATTERN_COUNT; p++) {
        for (int i = 0; i < PATTERN_SIDE; i++) {
            for (int j = 0; j < PATTERN_SIDE; j++) {
                fprintf(patterns_file, "%d,%d,%d,%d\n", p, i, j, best_individual_patterns[p * PATTERN_SIZE + i * PATTERN_SIDE + j]);
            }
        }
    }
    fclose(patterns_file);
    printf("Patterns saved to patterns.csv\n");
}

void save_fitness_progress_to_csv(const char *filename) {
    FILE *fitness_file = fopen(filename, "w");
    if (fitness_file == NULL) {
        printf("Error opening fitness_progress.csv file\n");
        return;
    }
    fprintf(fitness_file, "Generation,BestFitness,AvgFitness\n");
    for (int g = 0; g < GENERATION; g++) {
        fprintf(fitness_file, "%d,%d,%.2f\n", g, generation_best_fitness[g], avg_fitness_per_generation[g]);
    }
    fclose(fitness_file);
    printf("Fitness progress saved to fitness_progress.csv\n");
}

void save_reconstructed_images_info(const char *filename) {
    FILE *images_file = fopen(filename, "w");
    if (images_file == NULL) {
        printf("Error opening reconstructed_images.csv file\n");
        return;
    }
    fprintf(images_file, "Image,BlockRow,BlockCol,BestPattern\n");
    for (int img = 0; img < IMAGE_COUNT; img++) {
        for (int block_row = 0; block_row < IMAGE_SIDE / PATTERN_SIDE; block_row++) {
            for (int block_col = 0; block_col < IMAGE_SIDE / PATTERN_SIDE; block_col++) {
                int min_distance = INT_MAX;
                int best_pattern = 0;
                for (int p = 0; p < PATTERN_COUNT; p++) {
                    int dist = 0;
                    for (int bi = 0; bi < PATTERN_SIDE; bi++) {
                        for (int bj = 0; bj < PATTERN_SIDE; bj++) {
                            int img_pix = images[img * IMAGE_SIZE + (block_row * PATTERN_SIDE + bi) * IMAGE_SIDE + (block_col * PATTERN_SIDE + bj)];
                            int pat_pix = population[best[1]][p * PATTERN_SIZE + bi * PATTERN_SIDE + bj];
                            if (img_pix != pat_pix) dist++;
                        }
                    }
                    if (dist < min_distance) {
                        min_distance = dist;
                        best_pattern = p;
                    }
                }
                fprintf(images_file, "%d,%d,%d,%d\n", img, block_row, block_col, best_pattern);
            }
        }
    }
    fclose(images_file);
    printf("Reconstructed images information saved to reconstructed_images.csv\n");
}

//...........................Saving Functions Stop............................//
