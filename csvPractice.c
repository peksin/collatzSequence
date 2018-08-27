#include <stdio.h>
#include <string.h>

int main(void)

{
    FILE *fp;
    fp = fopen("file.csv", "w+");
    fprintf(fp,"STudent id, ossi");

    fclose(fp);
    return(0);
    
}