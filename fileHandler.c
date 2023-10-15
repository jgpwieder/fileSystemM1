#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "fileHandler.h"


void writeFile(const char *fileName, const char *data) {
    int descriptor = open(fileName, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (descriptor == -1) {
        perror("Error opening file");
        return;
    }

    write(descriptor, data, strlen(data));
    close(descriptor);
}

void appendToFile(const char *fileName, const char *data) {
    int descriptor = open(fileName, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (descriptor == -1) {
        perror("Error opening file");
        return;
    }

    // Seek to the end of the file
    lseek(descriptor, 0, SEEK_END);

    // Append the JSON-like data to the file
    write(descriptor, data, strlen(data));

    // Append a newline after each JSON-like object
    write(descriptor, "\n", 1);

    close(descriptor);
}
