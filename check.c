#include<stdio.h>
#include<string.h>
#include"convert.h"

void check(char* argv[])
{  
   int compare;
   double cups;
   
   compare = strcmp(argv[1],"-s");
   if (compare == 0 ) //it's suger
	{ 
		cups =equation_s(atoi(argv[2]));
	}
   else {
	printf("It's not suger\n");
	// that's for now only
	}
   //printf("%s\n", argv[2]);
   printf("You need %.2lf cups!\n", cups);
}
