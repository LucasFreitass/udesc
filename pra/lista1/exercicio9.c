#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main () {
        char *caracter;
        int n;
        int i;
        int cont=0;
        printf("Informe a quantidade de caracteries ( Podendo ser maior nao menor q a qnt desejada.)\n");
        scanf("%d",&n);

        caracter = malloc(sizeof(char)*n);
        scanf("%s", caracter);

        //printf("%s",caracter );

        for (i = 0; i < strlen(caracter); i++) {
                if (caracter[i] == caracter[i+1]) {
                        cont++;
                } else {
                        cont++;
                        printf("%d%c",cont, caracter[i] );
                        cont=0;
                }
        }
        //printf("%c%d", caracter[i],cont );
        free(caracter);
        return 0;
}
