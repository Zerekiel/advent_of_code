#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getFirstAndLastValue(char *strValue) {

    char duoResult[2];
    int result = 0;

    if (strlen(strValue) == 1) {
        // doubling the alone number
        duoResult[0] = strValue[0];
        duoResult[1] = strValue[0];
    } else {
        // taking only first and last digit
        duoResult[0] = strValue[0];
        duoResult[1] = strValue[strlen(strValue) - 1];
    }
    result = atoi(duoResult);
    free(strValue);
    return result;

}

int getValueFromLine(char *line) {

    int length = strlen(line);
    int i = 0;
    int firstTime = 0; 
    char *charResult;
    

    while (i < length) {

        // Initialization of string containing result or reallocation
        if (firstTime == 0) {
                charResult = malloc(1);
                firstTime = 1;
            } else {
                charResult = realloc(charResult, 1);
            }



        // IF numbers
        if (line[i] > 47 &&  line[i] < 58) {
            strncat(charResult, &line[i], 1);
        // ELIF start like one of those numbers written
        } else {

            if (line[i] == 'o' && line[i+1] != '\n' && line[i+1] == 'n' && line[i+2] != '\n' && line[i+2] == 'e') {
                strncat(charResult, "1", 1);
                i++;
            }
            else if (line[i] == 't') {
                if (line[i+1] != '\n' && line[i+1] == 'w' && line[i+2] != '\n' && line[i+2] == 'o') {
                    strncat(charResult, "2", 1);
                    i += 1;
                } else if (line[i+1] != '\n' && line[i+1] == 'h' && line[i+2] != '\n' && line[i+2] == 'r' && line[i+3] != '\n' && line[i+3] == 'e' && line[i+4] != '\n' && line[i+4] == 'e') {
                    strncat(charResult, "3", 1);
                    i += 3;
                }
            }
            else if (line[i] == 'f') {
                if (line[i+1] != '\n' && line[i+1] == 'o' && line[i+2] != '\n' && line[i+2] == 'u' && line[i+3] != '\n' && line[i+3] == 'r') {
                    strncat(charResult, "4", 1);
                    i += 2;
                }
                else if (line[i+1] != '\n' && line[i+1] == 'i' && line[i+2] != '\n' && line[i+2] == 'v' && line[i+3] != '\n' && line[i+3] == 'e') {
                    strncat(charResult, "5", 1);
                    i += 2;
                }
            }
            else if (line[i] == 's') {
                if (line[i+1] != '\n' && line[i+1] == 'i' && line[i+2] != '\n' && line[i+2] == 'x') {
                    strncat(charResult, "6", 1);
                    i += 1;
                }
                else if (line[i+1] != '\n' && line[i+1] == 'e' && line[i+2] != '\n' && line[i+2] == 'v' && line[i+3] != '\n' && line[i+3] == 'e' && line[i+4] != '\n' && line[i+4] == 'n') {
                    strncat(charResult, "7", 1);
                    i += 3;
                }
            }
            else if (line[i] == 'e') {
                if (line[i+1] != '\n' && line[i+1] == 'i' && line[i+2] != '\n' && line[i+2] == 'g' && line[i+3] != '\n' && line[i+3] == 'h' && line[i+4] != '\n' && line[i+4] == 't') {
                    strncat(charResult, "8", 1);
                    i += 3;
                }
            }
            else if (line[i] == 'n') {
                if (line[i+1] != '\n' && line[i+1] == 'i' && line[i+2] != '\n' && line[i+2] == 'n' && line[i+3] != '\n' && line[i+3] == 'e') {
                    strncat(charResult, "9", 1);
                    i += 2;
                }
            }
        }
        i++;
    }
    return getFirstAndLastValue(charResult);
}

int main(int ac, char **av) {

    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int finalResult = 0;

   fp = fopen(av[1], "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);


   while ((read = getline(&line, &len, fp)) != -1) {
        finalResult += getValueFromLine(line);
    }

    printf("%d", finalResult);
    free(line);
    fclose(fp);
    exit(EXIT_SUCCESS);
}