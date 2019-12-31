#include<stdio.h>
#include<string.h>
#include<math.h>
#include"check.h"
#include"convert.h"
#include"Gui.h"

int main(int argc, char* argv[])
{  if (argc > 1 )
  {
    check(argv);
  }
   else 
  {  create_window(argc, argv);
  }
   return 0;
}
