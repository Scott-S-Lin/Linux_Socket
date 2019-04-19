#include <stdio.h>

int main (int argc, char *argv[])
{
    FILE *fin, *fout;
    int i;
    char string[40] = "This is something.";

    fout = fopen ("data", "w");

    i = 0x123456;
    //fwrite(&i, sizeof(int), 1, fout);
    fprintf(fout, "%x", i);

    //fprintf(fout, "%s", string);
    //fwrite(string, sizeof(string), 1, fout);

    fclose(fout);
    
    //fin = fopen ("data", "r");
    
    //fread(&i, sizeof(int), 1, fin);
    //fscanf(fin, "%x", &i);
    
    //printf("i=%x\n", i);
    //fclose(fin);    

    return 0;
}

