#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "fileHandler.h"


int main() {
    char data[] = "";
    char fileName[] = "test.txt";

    // Create a pointer
    const char *dataPointer = data;
    writeFile(fileName, data);

    const char *dataToAppend1 = "{\"name\":\"John\",\"age\":30}";
    appendToFile(fileName, dataToAppend1);

    const char *dataToAppend2 = "{\"name\":\"Maria\",\"age\":65}";
    appendToFile(fileName, dataToAppend2);

    return 0;
}