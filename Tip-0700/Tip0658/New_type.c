#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[])
 {
   char line[255];  // Line read from the file

   FILE *fp;

   if (fp = fopen(argv[1], "r"))
     {
       while (fgets(line, sizeof(line), fp))
         fputs(line, stdout);
       fclose(fp);

       exit(0);  // Successful
     }
   else 
     {
       printf("Cannot open %s\n", argv[1]);
       exit (1);
     }
 }

