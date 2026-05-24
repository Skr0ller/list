#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAXVAL 30
#define MAXNAME 20
#define BUFSIZE 100

int count = 0, j = 0;

/* Scan a command for arguments */
void scancom(char flag[], char name[], char args[], char stat[]);

/* create a task */
void ctask(char taskname[MAXNAME], int vdone);

int main()
{
	char argsbuffer[BUFSIZE];

	printf("Enter your command\n\n");
	printf("Example of creating a task: -n nameofyourtask isdone(1 or 0)\n\n");
	printf(" New task: -n\n Show task: -s\n Delete task -d\n Update task: -u\n Help: -h\n");

	while(1)
	{
		if(fgets(argsbuffer, sizeof(argsbuffer), stdin) != NULL)
		{
			char buffflag[MAXVAL], buffname[MAXVAL], buffstat[MAXVAL];

			scancom(buffflag, buffname, argsbuffer, buffstat);
			printf("%s ", buffflag);
			printf("%s ", buffname);
			printf("%s ", buffstat);

		}
	}
		

}


void scancom(char flag[], char name[], char args[], char stat[])
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;

	while(args[++a] == ' ')
		;

	while(args[a] != ' ')
	{
		flag[b] = args[a];
		++b, ++a;

		if(args[a] == ' ')
		{
			flag[b] = '\0';
		}

	}
	a++;

	while(args[a] != ' ')
	{
		name[c] = args[a];
		++c, ++a;

		if(args[a] == ' ')
		{
			name[c] = '\0';
		}
	}
	a++;

	while(args[a] != '\0')
	{
		stat[d] = args[a];
		++d, ++a;

		if(args[a] == '\0')
		{
			stat[d] = '\0';
		}
	}

}

void ctask(char taskname[], int vdone)
{

}
