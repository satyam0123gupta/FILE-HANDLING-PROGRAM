#include <stdio.h>
#include <stdlib.h>

void createAndWriteFile(const char *filename) {
    FILE *fp = fopen(filename, "w");  
    if (fp == NULL) {
        perror("Error creating file");
        return;
    }

    fprintf(fp, "Hello! This is the first line.\n");
    fprintf(fp, "File handling in C is powerful.\n");
    fclose(fp);

    printf("File '%s' created and written successfully.\n", filename);
}

void readFile(const char *filename) {
    FILE *fp = fopen(filename, "r");
    char ch;

    if (fp == NULL) {
        perror("Error reading file");
        return;
    }

    printf("\n--- Contents of '%s' ---\n", filename);
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);
}

void appendToFile(const char *filename) {
    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        perror("Error opening file to append");
        return;
    }

    fprintf(fp, "This line is appended to the file.\n");
    fclose(fp);
    printf("\nData appended to '%s' successfully.\n", filename);
}

int main() {
    const char *filename = "demo_file.txt";

    createAndWriteFile(filename);  // Step 1: Create and write
    readFile(filename);            // Step 2: Read
    appendToFile(filename);        // Step 3: Append
    readFile(filename);            // Step 4: Read again to see appended data

    return 0;
}

