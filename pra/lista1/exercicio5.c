#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void backtracking (int n, char* str, int *maneiras) { //ESSA FUNCAO É BASICAMENTE UM FIBONACI, NA REAL É FIBONACI
        if ( n == 0) {
                str[strlen(str)-1]=']';
                str[strlen(str)]='\0';// para garantir q pra frente n vem lixo de memoria.
                printf("%s", str);
                (*maneiras)++;
        } else if(n > 0) {
                int index = strlen(str);
                str[index] = '1';
                str[index+1] = ',';
                str[index+2] = '\0';
                backtracking(n-1, str, maneiras);
                str[index] = '2';
                str[index+1] = ',';
                str[index+2] = '\0'; // dps q andei eu finalizo para n continuar andando..
                backtracking(n-2, str, maneiras);
        }
}
int main () {
        int n, maneiras = 0;
        char str[100]; // para printar.
        str[0] = '['; // coloca o parenteses para printar o parenteses certin
        str[1] = '\0'; // evita lixo de memoria.
        scanf("%d",&n);
        if (n ==0) {
                printf("%d\n",n );
                return 0;
        }
        backtracking(n, str, &maneiras); // mando a string vazia, o n e o endereco pras maneiras.
        printf("\nmaneiras possíveis %d\n", maneiras);
        return 0;
}
