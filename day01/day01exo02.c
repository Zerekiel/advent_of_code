#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int getValueFromLine(char *line) {

    int i = 0;

    while (i < strlen(line)) {

        if (line[i] == 'o' || line[i] == 't' || line[i] == 'f' || line[i] == 's' || line[i] == 'e' || line[i] == 'n') {

            if (line[i+1] != '\n') {


            
            
            
            
            
            }
        }

        



        i++;
    }


// o t f s e n

// on check le char d'apres si il est pas == \n
            // si il match le deuxieme char au cas par cas on regarde le 1 ou les 2 ou les 3 char d'apres
            // si ça match on prend et on ajoute à la liste des ints sous format char => fct de conversion nombre toute lettre en int ecrit sous format char 
            // si ça match pas on revient au i et on fait simplement +1 



    return 0;
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