#include <stdio.h>
#include <conio.h>
#include <string.h>

void main(void)
 {
   char *password;

   password = getpass("Enter Password:");

   if (strcmp(password, "Bible"))
     printf("Password Incorrect\n");
   else 
     printf("Password OK\n");
 }
