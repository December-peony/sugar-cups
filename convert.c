#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include <string.h>
 
double equation_s(int x)
{  double power= pow(10,-3);
   int grams;
   double cups;
   grams = x;
   //printf("%d\n", grams);
   cups = grams /(240*power*845) ; 
printf("%.2lf\n", cups);
   return cups;
}
