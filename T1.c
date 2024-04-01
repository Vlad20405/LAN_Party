#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fisierin, *fisierout;

    if((fisierin = fopen("date/t1/d.in", "rt")) == NULL)
    {
        puts("Fisierul de intrare nu poate fi deschis\n");
        exit(1);
    }

    char line[1000];
    while(fgets(line, sizeof(line), fisierin) != NULL) 
/*  {
        printf("%s", line);
    }
    printf("\n");
*/
    fclose(fisierin);

    if((fisierout = fopen("out/r.out", "wt")) == NULL)
    {
        puts("Fisierul de iesire nu poate fi deschis\n");
        exit(1);
    }

    fclose(fisierout);

    return 0;
}
