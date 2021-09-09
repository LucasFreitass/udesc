#include <stdio.h>
#include <stdlib.h>
int somaMaximos (int *v, int n)
{
        int var1 = v[0], var2 = 0, var1_novo, i;
        for (i = 1; i < n; i++)
        {
                var1_novo = (var1 > var2) ? var1 : var2;        // Como se fosse um for, se incl for maior q excl excl_new = incl, se n vai ser igual a excl, o primeiro é se for vdd se n é o segundo.
                var1 = var2 + v[i];
                var2 = var1_novo;
        }
        return ((var1 > var2) ? var1 : var2);
}
int main()
{
        int *v, n, i;
        scanf("%d",&n);
        v = malloc(sizeof(int)*n);
        for (i = 0; i < n; i++) {
                scanf("%d",&v[i]);
        }
        printf("%d\n", somaMaximos(v, n));
        return 0;
}
