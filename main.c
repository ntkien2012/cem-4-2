#include <stdio.h>
#include <stdlib.h> // atoi lib
#define __MAX_SIZE 256

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("ERROR #1: Command has not enough parameters\n");
		return -1;
	}
	
	FILE *fs = fopen(argv[1], "r");
	if (!fs)
	{
		printf("ERROR #2: FIle error\n");
		return -2;
	}
	
	int n = 10;
	if (argc > 2)
		n = atoi(argv[2]);//ham chuyen char to int
	
	rewind(fs); //Dua con tro ve vi tri dau tien cua file
	int total = 0;
	char tmp[__MAX_SIZE];
	while (fgets(tmp, __MAX_SIZE, fs))
		total++;
	
	//print N lines
	rewind(fs);
	int j = total - n, i = 0, ip = 1;
	while (fgets(tmp, __MAX_SIZE, fs))
	{
		++i;
		if (i > j)
			printf("#%d: %s", ip++, tmp);
	}
	
	fclose(fs);
	return 0;
}