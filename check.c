#include<stdio.h>
#include<string.h>
#include"convert.h"
void check(char* argv[])
{  
   int compare;
   double cups;
   compare = strcmp(argv[2],"-s");
   if (compare == 0 ) //it's suger
	{ 
		cups = equation_s(argv[2]);
	}
   else {
	printf("It's not suger");
	// that's for now only
	}
   printf("You need %.2lf cups!\n");
}
