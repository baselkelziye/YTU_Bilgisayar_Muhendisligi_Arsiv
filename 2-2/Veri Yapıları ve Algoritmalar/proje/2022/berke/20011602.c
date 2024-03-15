/* Berke Ozgen 20011602 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_NAME 100
#define ENCODED_FILE_NAME "test_encoded.txt"
#define DECODED_FILE_NAME "test_decoded.pgm"

/* PGM */
typedef struct PGM {
	int rows;
	int cols;
	int **contents;
} PGM;

PGM *createPGM();
int readPGM(PGM *pgm, char *name);
void writePGM(PGM *pgm, char *name);
void freePGM(PGM *pgm);

/* EncodedPGM */
typedef struct EncodedPGM {
	int rows;
	int cols;
	int length;
	int *counts;
	int *values;
} EPGM;

EPGM *createEPGM();
int readEPGM(EPGM *epgm, char *name);
void writeEPGM(EPGM *epgm, char *name);
void freeEPGM(EPGM *epgm);
void packEPGM(EPGM *epgm);

/* Functions */
EPGM *encodePGM(PGM *pgm);
PGM *decodeEPGM(EPGM *epgm);
int changeColor(EPGM *epgm, int color1, int color2);
int changePixel(EPGM *epgm, int row, int col, int color);
void calculateHistogram(EPGM *epgm);

/* Util */
void skipUntilNonNewline(FILE *f);
void skipUntilNonWhitespace(FILE *f);

int main() {
	int menu, i;
	char *str = (char *) malloc(MAX_FILE_NAME * sizeof(char));
	PGM *pgm;
	EPGM *epgm;
	int color1, color2;
	int row, col;
	do {
		printf("0. Quit\n1. Encode PGM\n2. Decode PGM\n3. Change a color value\n4. Change a pixel's value\n5. Calculate histogram\nChoice: ");
		scanf("%d", &menu);
		switch (menu) {
			case 1:
				printf("--> PGM file name: ");
				scanf("%s", str);
				pgm = createPGM();
				if (!readPGM(pgm, str)) {
					epgm = encodePGM(pgm);
					writeEPGM(epgm, ENCODED_FILE_NAME);
					printf("Encoded data:\n");
					for (i = 0; i < epgm->length; i++) {
						printf("%d %d\n", epgm->counts[i], epgm->values[i]);
					}
					printf("Wrote encoded data to %s\n", ENCODED_FILE_NAME);
					freeEPGM(epgm);
				}
				freePGM(pgm);
				break;
			case 2:
				printf("--> Encoded PGM file name: ");
				scanf("%s", str);
				epgm = createEPGM();
				if (!readEPGM(epgm, str)) {
					pgm = decodeEPGM(epgm);
					writePGM(pgm, DECODED_FILE_NAME);
					printf("Wrote decoded data to %s\n", DECODED_FILE_NAME);
					freePGM(pgm);
				}
				freeEPGM(epgm);
				break;
			case 3:
				printf("--> PGM file name: ");
				scanf("%s", str);
				pgm = createPGM();
				if (!readPGM(pgm, str)) {
					printf("--> Old color value: ");
					scanf("%d", &color1);
					printf("--> New color value: ");
					scanf("%d", &color2);
					epgm = encodePGM(pgm);
					printf("Changed %d occurences.\n", changeColor(epgm, color1, color2));
					writeEPGM(epgm, ENCODED_FILE_NAME);
					printf("Encoded data:\n");
					for (i = 0; i < epgm->length; i++) {
						printf("%d %d\n", epgm->counts[i], epgm->values[i]);
					}
					printf("Wrote encoded data to %s\n", ENCODED_FILE_NAME);
					freeEPGM(epgm);
				}
				freePGM(pgm);
				break;
			case 4:
				printf("--> PGM file name: ");
				scanf("%s", str);
				pgm = createPGM();
				if (!readPGM(pgm, str)) {
					printf("--> Row value (0-%d): ", pgm->rows - 1);
					scanf("%d", &row);
					printf("--> Column value (0-%d): ", pgm->cols - 1);
					scanf("%d", &col);
					printf("--> Color value: ");
					scanf("%d", &color1);
					epgm = encodePGM(pgm);
					if (!changePixel(epgm, row, col, color1)) {
						writeEPGM(epgm, ENCODED_FILE_NAME);
						printf("Encoded data:\n");
						for (i = 0; i < epgm->length; i++) {
							printf("%d %d\n", epgm->counts[i], epgm->values[i]);
						}
						printf("Wrote encoded data to %s\n", ENCODED_FILE_NAME);
					}
					freeEPGM(epgm);
				}
				freePGM(pgm);
				break;
			case 5:
				printf("--> PGM file name: ");
				scanf("%s", str);
				pgm = createPGM();
				if (!readPGM(pgm, str)) {
					epgm = encodePGM(pgm);
					writeEPGM(epgm, ENCODED_FILE_NAME);
					printf("Encoded data:\n");
					for (i = 0; i < epgm->length; i++) {
						printf("%d %d\n", epgm->counts[i], epgm->values[i]);
					}
					printf("Wrote encoded data to %s\n", ENCODED_FILE_NAME);
					calculateHistogram(epgm);
					freeEPGM(epgm);
				}
				freePGM(pgm);
				break;
		}
	} while (menu != 0);
	free(str);
	return 0;
}

/* PGM */
PGM *createPGM() {
	PGM *pgm = (PGM *) malloc(sizeof(PGM));
	pgm->rows = -1;
	pgm->cols = -1;
	pgm->contents = NULL;
	return pgm;
}

int readPGM(PGM *pgm, char *name) {
	int i, j;
	FILE *f = fopen(name, "rb");

	if (f == NULL) {
		printf("File not found.\n");
		return 1;
	} else {
		/* Skip version */
		if ((i = fgetc(f)) != 'P') {
			printf("Not a PGM file.\n");
			return 1;
		} else if ((i = fgetc(f)) != '2') {
			printf("Only P2 files are supported. Found P%c.\n", i);
			return 1;
		} else {
			skipUntilNonWhitespace(f);
		}

		/* Skip comment */
		if (fgetc(f) == '#') {
			skipUntilNonNewline(f);
		} else {
			fseek(f, -1, SEEK_CUR);
		}

		fscanf(f, "%d", &pgm->cols);
		skipUntilNonWhitespace(f);
		fscanf(f, "%d", &pgm->rows);
		skipUntilNonWhitespace(f);

		/* Skip max value */
		skipUntilNonWhitespace(f);
		
		pgm->contents = (int **) malloc(pgm->rows * sizeof(int *));
		for (i = 0; i < pgm->rows; i++) {
			pgm->contents[i] = (int *) malloc(pgm->cols * sizeof(int));
			for (j = 0; j < pgm->cols; j++) {
				fscanf(f, "%d", &pgm->contents[i][j]);
				skipUntilNonWhitespace(f);
			}
		}

		fclose(f);
		return 0;
	}
}

void writePGM(PGM *pgm, char *name) {
	FILE *f = fopen(name, "wb");
	int i, j, k = 0;

	fprintf(f, "P2\n%d %d\n255\n", pgm->cols, pgm->rows);
	for (i = 0; i < pgm->rows; i++) {
		for (j = 0; j < pgm->cols; j++) {
			fprintf(f, "%d ", pgm->contents[i][j]);
			if (++k % 50 == 0) fprintf(f, "\n");
		}
	}

	fclose(f);
}

void freePGM(PGM *pgm) {
	int i;
	for (i = 0; i < pgm->rows; i++) {
		free(pgm->contents[i]);
	}
	free(pgm->contents);
	free(pgm);
}

/* EPGM */
EPGM *createEPGM() {
	EPGM *epgm = (EPGM *) malloc(sizeof(EPGM));
	epgm->rows = -1;
	epgm->cols = -1;
	epgm->length = -1;
	epgm->counts = NULL;
	epgm->values = NULL;
	return epgm;
}

int readEPGM(EPGM *epgm, char *name) {
	int i;
	int count = 0;
	int prev = -1;
	int valid, a, b, sum, temp1, temp2;
	FILE *f = fopen(name, "rb");

	if (f == NULL) {
		printf("File not found.\n");
		return 1;
	} else {
		fscanf(f, "%d", &epgm->cols);
		skipUntilNonWhitespace(f);
		fscanf(f, "%d", &epgm->rows);
		skipUntilNonWhitespace(f);
		fscanf(f, "%d", &epgm->length);
		skipUntilNonNewline(f);

		epgm->counts = (int *) malloc(epgm->length * sizeof(int));
		epgm->values = (int *) malloc(epgm->length * sizeof(int));

		valid = 1;
		i = 0;
		do {
			a = fscanf(f, "%d", &temp1);
			b = fscanf(f, "%d", &temp2);
			if (i < epgm->length) {
				epgm->counts[i] = temp1;
				epgm->values[i] = temp2;
			}
			if (!(a == EOF && b == EOF && i == epgm->length || i < epgm->length && a != EOF && b != EOF)) {
				valid = 0;
			}
			i++;
		} while (valid && a != EOF && b != EOF);

		if (!valid) {
			printf("Not a valid encoded PGM file. Length of the file is incorrect.\n");
			fclose(f);
			return 1;
		}

		printf("The contents are read. Running checks.\n");

		sum = 0;
		for (i = 0; i < epgm->length; i++) {
			sum += epgm->counts[i];
		}

		count = epgm->rows * epgm->cols;
		if (count != sum) {
			printf("Not a valid encoded PGM file. Pixel count %d * %d = %d differs from %d.\n", epgm->cols, epgm->rows, count, sum);
			fclose(f);
			return 1;
		}

		printf("Pixel counts match.\n");

		for (i = 0; i < epgm->length; i++) {
			if (epgm->values[i] < 0 || epgm->values[i] > 255) {
				printf("Not a valid encoded PGM file. Pixel color %d is out of bounds.\n", epgm->values[i]);
				fclose(f);
				return 1;
			}
		}

		printf("Pixels are between 0-255.\n");

		prev = epgm->values[0];
		for (i = 1; i < epgm->length; i++) {
			if (prev == epgm->values[i]) {
				printf("Not a valid encoded PGM file. Pixel color %d repeats more than once.\n", epgm->values[i]);
				fclose(f);
				return 1;
			} else {
				prev = epgm->values[i];
			}
		}

		printf("No repeating pixels.\nAll checks passed.\n");
	}

	fclose(f);
	return 0;
}

void writeEPGM(EPGM *epgm, char *name) {
	FILE *f = fopen(name, "wb");
	int i;

	fprintf(f, "%d %d %d\n", epgm->cols, epgm->rows, epgm->length);

	i = 0;
	while (i < epgm->length) {
		fprintf(f, "%d %d ", epgm->counts[i], epgm->values[i]);
		i++;
	}

	fclose(f);
}

void freeEPGM(EPGM *epgm) {
	free(epgm->counts);
	free(epgm->values);
	free(epgm);
}

void packEPGM(EPGM *epgm) {
	int length = epgm->length;
	int prev = 0;
	int i, j, k;
	for (i = 1; i < epgm->length; i++) {
		if (epgm->values[i] == epgm->values[prev]) {
			length--;
			epgm->counts[prev] += epgm->counts[i];
			epgm->values[i] = -1;
		} else {
			prev = i;
		}
	}
	for (i = 0; i < epgm->length; i++) {
		if (epgm->values[i] == -1) {
			j = i + 1;
			k = i;
			while (j < epgm->length) {
				while (epgm->values[j] == -1) {
					j++;
				}
				epgm->counts[k] = epgm->counts[j];
				epgm->values[k] = epgm->values[j];
				j++;
				k++;
			}
		}
	}
	epgm->length = length;
	epgm->counts = (int *) realloc(epgm->counts, length * sizeof(int));
	epgm->values = (int *) realloc(epgm->values, length * sizeof(int));
}

/* Functions */
EPGM *encodePGM(PGM *pgm) {
	EPGM *epgm = createEPGM();
	int i, j, k, count;
	int prev;

	epgm->rows = pgm->rows;
	epgm->cols = pgm->cols;
	epgm->length = pgm->rows * pgm->cols;
	epgm->counts = (int *) malloc(epgm->length * sizeof(int));
	epgm->values = (int *) malloc(epgm->length * sizeof(int));

	k = 0;
	count = 0;
	prev = pgm->contents[0][0];
	for (i = 0; i < pgm->rows; i++) {
		for (j = 0; j < pgm->cols; j++) {
			if (pgm->contents[i][j] == prev) {
				count++;
			} else {
				epgm->counts[k] = count;
				epgm->values[k] = prev;
				k++;
				count = 1;
				prev = pgm->contents[i][j];
			}
		}
	}
	epgm->counts[k] = count;
	epgm->values[k] = prev;
	k++;
	
	epgm->length = k;
	epgm->counts = (int *) realloc(epgm->counts, k * sizeof(int));
	epgm->values = (int *) realloc(epgm->values, k * sizeof(int));

	return epgm;
}

PGM *decodeEPGM(EPGM *epgm) {
	PGM *pgm = createPGM();
	int i, j, count;

	pgm->rows = epgm->rows;
	pgm->cols = epgm->cols;
	pgm->contents = (int **) malloc(pgm->rows * sizeof(int *));
	for (i = 0; i < pgm->rows; i++) {
		pgm->contents[i] = (int *) malloc(pgm->cols * sizeof(int));
	}

	j = 0;
	for (i = 0; i < epgm->length; i++) {
		count = epgm->counts[i];
		while (count) {
			pgm->contents[j / pgm->cols][j % pgm->cols] = epgm->values[i];
			j++;
			count--;
		}
	}

	return pgm;
}

int changeColor(EPGM *epgm, int color1, int color2) {
	int i, count = 0;
	for (i = 0; i < epgm->length; i++) {
		if (epgm->values[i] == color1) {
			epgm->values[i] = color2;
			count += epgm->counts[i];
		}
	}
	packEPGM(epgm);
	return count;
}

int changePixel(EPGM *epgm, int row, int col, int color) {
	int pos = epgm->cols * row + col;
	int i = 0, count = 0, j;
	int forwardOffset, backwardOffset;

	if (row >= 0 && col >= 0 && row < epgm->rows && col < epgm->cols) {
		while (i < epgm->length && count <= pos) {
			count += epgm->counts[i];
			i++;
		}

		forwardOffset = count - pos - 1;
		backwardOffset = pos - count + epgm->counts[i - 1];

		if (forwardOffset == 0 && backwardOffset == 0) {
			epgm->values[i - 1] = color;
		} else if (forwardOffset == 0) {
			epgm->length++;
			epgm->counts = (int *) realloc(epgm->counts, epgm->length * sizeof(int));
			epgm->values = (int *) realloc(epgm->values, epgm->length * sizeof(int));

			j = epgm->length - 1;
			while (j > i) {
				epgm->counts[j] = epgm->counts[j - 1];
				epgm->values[j] = epgm->values[j - 1];
				j--;
			}

			epgm->counts[i - 1]--;
			epgm->counts[j] = 1;
			epgm->values[j] = color;
		} else if (backwardOffset == 0) {
			epgm->length++;
			epgm->counts = (int *) realloc(epgm->counts, epgm->length * sizeof(int));
			epgm->values = (int *) realloc(epgm->values, epgm->length * sizeof(int));

			j = epgm->length - 1;
			while (j > i - 1) {
				epgm->counts[j] = epgm->counts[j - 1];
				epgm->values[j] = epgm->values[j - 1];
				j--;
			}

			epgm->counts[i]--;
			epgm->counts[j] = 1;
			epgm->values[j] = color;
		} else {
			epgm->length += 2;
			epgm->counts = (int *) realloc(epgm->counts, epgm->length * sizeof(int));
			epgm->values = (int *) realloc(epgm->values, epgm->length * sizeof(int));

			j = epgm->length - 1;
			while (j > i) {
				epgm->counts[j] = epgm->counts[j - 2];
				epgm->values[j] = epgm->values[j - 2];
				j--;
			}

			epgm->counts[i - 1] -= forwardOffset + 1;
			epgm->counts[i + 1] -= backwardOffset + 1;
			epgm->counts[i] = 1;
			epgm->values[i] = color;
		}
		packEPGM(epgm);

		return 0;
	} else {
		printf("Row and column values are out of bounds.\n");
		return 1;
	}
}

void calculateHistogram(EPGM *epgm) {
	int *arr = (int *) calloc(256, sizeof(int));
	int i;

	for (i = 0; i < epgm->length; i++) {
		arr[epgm->values[i]] += epgm->counts[i];
	}

	printf("Color: Count\n");
	for (i = 0; i < 256; i++) {
		if (arr[i]) {
			printf("%d: %d\n", i, arr[i]);
		}
	}

	free(arr);
}

/* Util */
void skipUntilNonNewline(FILE *f) {
	char temp;
	do {
		temp = fgetc(f);
	} while (temp != EOF && temp != '\n' && temp != '\r');
	while (temp != EOF && (temp == '\n' || temp == '\r')) {
		temp = fgetc(f);
	}
	fseek(f, -1, SEEK_CUR);
}

void skipUntilNonWhitespace(FILE *f) {
	char temp;
	do {
		temp = fgetc(f);
	} while (temp != EOF && temp != '\n' && temp != '\r' && temp != '\t' && temp != ' ');
	while (temp != EOF && (temp == '\n' || temp == '\r' || temp == '\t' || temp == ' ')) {
		temp = fgetc(f);
	}
	fseek(f, -1, SEEK_CUR);
}
