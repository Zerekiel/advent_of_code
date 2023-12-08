#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int checkLine(char *line) {

    int i = 0;
    char *value;
    int actualValueOfColor = 0;
    char actualColor = 'g';

    // Blue / Red / Green
    int * maxValue = malloc(3);
    maxValue[0] = 0;
    maxValue[1] = 0;
    maxValue[2] = 0; 

    while (i < strlen(line)) {
        
        if (line[i] > 47 &&  line[i] < 58) {

            if (line[i+1] > 47 &&  line[i+1] < 58) {
                value = malloc(2);
                strncat(value, &line[i], 1);
                strncat(value, &line[i+1], 1);
                actualValueOfColor = atoi(value);
                actualColor = line[i+3];
                i += 2;
            } else {
                value = malloc(1);
                strncat(value, &line[i], 1);
                actualValueOfColor = atoi(value);
                actualColor = line[i+2];
                i++;
            }
            free(value);
            

            if (actualColor == 'b') {
                if (actualValueOfColor > maxValue[0])
                    maxValue[0] = actualValueOfColor;
            }
            else if (actualColor == 'r') {
                if (actualValueOfColor > maxValue[1])
                    maxValue[1] = actualValueOfColor;
            }
            else {
                if (actualValueOfColor > maxValue[2])
                    maxValue[2] = actualValueOfColor;
            }
        }
        i++;
        
    }

    int result = maxValue[0] * maxValue[1] * maxValue[2];
    free(maxValue);
    return result;
}


int main(int ac, char **av) {

    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

   int finalResult = 0;

   fp = fopen("game", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);


   while ((read = getline(&line, &len, fp)) != -1) {
        finalResult += checkLine(line);
    }

    printf("%d", finalResult);
    free(line);
    fclose(fp);
    exit(EXIT_SUCCESS);
}