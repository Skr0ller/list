#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#define PERMS 0644
#define MAXVAL 30
#define BUFSIZE 100

/* task id */
int taskcount = 0;

/* main name for a file with tasks */
char mname[MAXVAL] = "tasks.txt"; 

typedef struct
{
	char *name;
	char *isdone;
	int id;
} Task;

Task *tsks = malloc(MAXVAL * sizeof(Task));

/* convert int to char */
void itoc(int n, char ln[]);

/* Scan a command for arguments */
void scancom(char flag[], char name[], char args[], char stat[]);

/* create a task */
void ctask(char taskname[], char mainname[], char vdone[]);

int main()
{
	char argsbuffer[BUFSIZE];

	printf("Enter your command\n\n");
	printf("Example of creating a task: -n nameofyourtask isdone(1 or 0)\n\n");
	printf("New task: -n\nShow task: -s\nDelete task -d\nUpdate task: -u\nHelp: -h\n");

	while(1)
	{
		if(fgets(argsbuffer, sizeof(argsbuffer), stdin) != NULL)
		{
			char buffflag[MAXVAL], buffname[MAXVAL], buffstat[MAXVAL];

			scancom(buffflag, buffname, argsbuffer, buffstat);
			printf("%s ", buffflag);
			printf("%s ", buffname);
			printf("%s ", buffstat);
			ctask(buffname, mname, buffstat);


		}
	}
		

}

void itoc(int n, char ln[])
{

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

void ctask(char taskname[], char mainname[],  char vdone[])
{
	taskcount++;

	FILE *fp;

	fp = fopen(mainname, "a");

	fputs("task name: ", fp);
	fputs(taskname, fp);
	fputs("\n", fp);
	fputs("is done: ", fp);
	fputs(vdone, fp);
	fputs("\n\n", fp);
	fclose(fp);



		
}
