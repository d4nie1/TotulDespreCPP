#include <stdio.h>
#include <conio.h>
#include <time.h>

void main(void)
 {
   int count;

   time_t start_time, stop_time;
   
   time(&start_time);
   for (count = 0; count < 1001; count++)
     printf("Jamsa\'s C/C++ Programmer\'s Bible\n");
   time(&stop_time);

   printf("\n\nTime required for printf %d seconds\n",
     stop_time-start_time);
   printf("Press any key...\n");
   getch();

   time(&start_time);
   for (count = 0; count < 1001; count++)
     puts("Jamsa\'s C/C++ Programmer\'s Bible");

   time(&stop_time);

   printf("\n\nTime required for puts %d seconds\n",
     stop_time-start_time);
 }

