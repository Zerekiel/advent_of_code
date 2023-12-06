#include <stdlib.h>
# include <string.h>
#include <stdio.h>

int main(int ac, char **av) {

    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

   fp = fopen(av[1], "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

   while ((read = getline(&line, &len, fp)) != -1) {
        //printf("Retrieved line of length %zu :\n", read);
        printf("%s", line);
    }

   free(line);
    exit(EXIT_SUCCESS);
}