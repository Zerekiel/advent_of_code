#include <stdlib.h>
# include <string.h>
#include <stdio.h>

int main(int ac, char **av) {

    FILE *fp;
    char buffer[100];

    fp = fopen(av[1], "r");

    if (fp == NULL) {
        printf("ERROR : File is empty");
        return 1;
    }

    fread(buffer, 100, 1, fp);
    printf("%s\n", buffer);
    fclose(fp);
}