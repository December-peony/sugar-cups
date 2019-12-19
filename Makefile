suger: suger.c check.so convert.so
	gcc suger.c check.so convert.so -o suger -lm
check.so: check.h check.c
	gcc -c check.c -o check.so
convert.so: convert.h convert.h 
	gcc -c convert.c -o convert.so
