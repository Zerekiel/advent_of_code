#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int getValueFromLine(char *line) {

    //premier et denier chiffre de chaque ligne meme si plusieurs chiffres
    //si 1 seul chiffre on le double

    int length = strlen(line);
    int i = 0;
    int firstTime = 0; 
    char *charResult;
    char duoResult[2];
    int result = 0;

    while (i < length) {
        if (line[i] > 47 &&  line[i] < 58) {
            if (firstTime == 0) {
                charResult = malloc(1);
                firstTime = 1;
            } else {
                charResult = realloc(charResult, 1);
            }
            strncat(charResult, &line[i], 1);
        }
        i++;
    }

    if (strlen(charResult) == 1) {
        //on double le chiffre
        duoResult[0] = charResult[0];
        duoResult[1] = charResult[0];
    } else {
        //on prends le premier et le dernier chiffre
        duoResult[0] = charResult[0];
        duoResult[1] = charResult[strlen(charResult) - 1];
    }
    result = atoi(duoResult);
    printf("%d\n", result);
    free(charResult);
    return result;
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
        //printf("Retrieved line of length %zu :\n", read);
        finalResult += getValueFromLine(line);
    }

    printf("%d", finalResult);
    free(line);
    exit(EXIT_SUCCESS);
}