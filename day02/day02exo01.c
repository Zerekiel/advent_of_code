#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int checkValue(int value, char color){
    if (color == 'b') {
        if (value > 14)
            return 1;
        return 0;
    }
    else if (color == 'r') {
        if (value > 12)
            return 1;
        return 0;
    }
    else if (color == 'g') {
        if (value > 13)
            return 1;
        return 0;
    }
    return 1;
}


int checkLine(char *line) {

    int i = 0;
    char *value;
    int globalValueOfLine = 0;

    while (i < strlen(line)) {
        
        if (line[i] > 47 &&  line[i] < 58) {

            if (line[i+1] > 47 &&  line[i+1] < 58) {
                value = malloc(2);
                strncat(value, &line[i], 1);
                strncat(value, &line[i+1], 1);
                globalValueOfLine = checkValue(atoi(value), line[i+3]);
                i += 2;
            } else {
                value = malloc(1);
                strncat(value, &line[i], 1);
                globalValueOfLine = checkValue(atoi(value), line[i+2]);
                i++;
            }
            free(value);
        }
        i++;
        if (globalValueOfLine == 1)
            return globalValueOfLine;
    }
    return globalValueOfLine;
    // return 0 if line is ok
    // return 1 if not
}


int main(int ac, char **av) {

    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int finalResult = 0;
    int gameId = 1;

   fp = fopen("game", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);


   while ((read = getline(&line, &len, fp)) != -1) {
        if (checkLine(line) == 0)
            finalResult += gameId;
        gameId++;
    }

    printf("%d", finalResult);
    free(line);
    fclose(fp);
    exit(EXIT_SUCCESS);
}