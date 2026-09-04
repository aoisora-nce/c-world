/* Topic: FILE I/O
 *
 * #include <stdio.h>
 * FILE *ptr;
 * ptr = fopen("filename.txt", "mode")  mode => r, w, a, rb, wb, ab
 * fscanf(ptr, "format-specifier", address) // READING A FILE
 * fprintf(ptr, "format", variable) // WRITING A FILE
 * fclose(ptr)
 *
 * fgetc(ptr) fputc('C', ptr)
 *
 * fread() fwrite() for binary files.
 */

#include <stdio.h>
#include <unistd.h>

int write_txt();
int read_txt();
int read_txt_formatted();
int read_txt_char();
int rw_binary();

int main() {
    // write_txt();
    // read_txt();
    // read_txt_formatted();
    read_txt_char();
    rw_binary();
}


// +_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+
// Writing Data to a File
// +_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+

int write_txt() {
    // 1. Open file in write mode
    FILE *fptr = fopen("example.txt", "w");

    // 2. Error handling: Ensure file opened successfully
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // 3. Write data
    fprintf(fptr, "Hello, C File Handling!\n");
    fprintf(fptr, "Line %d\n", 2);

    // 4. Close file to release resources
    fclose(fptr);
    printf("File written successfully.\n");

    return 0;
}
// +_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+
// Reading Line-by-Line
// +_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+

int read_txt() {
    FILE *fptr = fopen("example.txt", "r");
    char buffer[10];

    if (fptr == NULL) {
        printf("Could not open file!\n");
        return 1;
    }

    // Read line-by-line until NULL
    while (fgets(buffer, sizeof(buffer), fptr) != NULL) {
        printf("%s", buffer);   // 10 chars per loop
        fflush(stdout);
        sleep(1);
    }

    fclose(fptr);
    return 0;
}

int read_txt_formatted() {
    FILE *fptr = fopen("example.txt", "r");
    if (fptr == NULL) {
        printf("File Read Error, possibly file doesnt exist.\n");
        return 1;
    }
    char buffer[100];
    while (1) {
        int status = fscanf(fptr, "%99s", buffer);
        if (status == EOF) {
            printf("\n**EOF Reached**");
            break;
        }
        else if (status == 1) {
            printf("%s", buffer);
            fflush(stdout);
            sleep(1);
        }
        else {
            printf("Parsing Error.");
            break;
        }
    }
    fclose(fptr);
    return 0;
}

int read_txt_char() {
    FILE *fptr = fopen("example.txt", "r");
    if (fptr == NULL) {
        printf("File Read Error, possibly file doesnt exist.\n");
        return 1;
    }
    while (1) {
        int c = fgetc(fptr);
        if (c == EOF) {
            printf("\n**EOF Reached**");
            break;
        }
        else {
            printf("%c", c);
            fflush(stdout);
            usleep(100000); // 10 texts/sec(1/10^5)
        }
    }
    fclose(fptr);
    return 0;
}

// +_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+
// Binary File I/O (fread & fwrite)
// +_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+

struct Point {
    int x;
    int y;
};

int rw_binary() {
    struct Point p1 = {10, 20};
    struct Point p2;

    // Write binary structure
    FILE *write_ptr = fopen("point.bin", "wb");
    fwrite(&p1, sizeof(struct Point), 1, write_ptr);
    fclose(write_ptr);

    // Read binary structure
    FILE *read_ptr = fopen("point.bin", "rb");
    fread(&p2, sizeof(struct Point), 1, read_ptr);
    fclose(read_ptr);

    printf("Read Point: x = %d, y = %d\n", p2.x, p2.y);
    return 0;
}
