#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#define PERMS 0644
#define MAXVAL 30
#define BUFSIZE 100

/* Task id */
int taskcount = 0;

/* Main name for a file with tasks */
char mname[MAXVAL] = "tasks.txt"; 

typedef struct
{
	char name[MAXVAL];
	char isdone[MAXVAL];
	int id;
} Task;

Task *tsksar[MAXVAL];

/* Help command */
void helpcom();

/* Show task by id */
void stask(int tid);

/* Scan a command for arguments */
void scancom(char flag[], char name[], char args[], char stat[]);

/* Create a task */
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

			int b = 0;
			switch(buffflag[b])
			{
				case 'n':
					ctask(buffname, mname, buffstat);
					printf("Task have been created!");
					break;
				case 'h':
					helpcom();
					break;
			}
		}
	}
		

}

void helpcom()
{
	printf("How to use commands:\n Create a task command: -n name_of_your_command is_done(1 or 0)\n Show a task command: -s id_of_your_task\n" 
			" Delete a task command: -d id_of_your_task\n Update a task command: -u id_of_a_task new_name_for_a_task new_status_for_a_task\n");
}

void stask(int tid)
{
	printf("name: %s\nis done: %s", tsksar[tid]->name, tsksar[tid]->isdone);
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
		b++, ++a;

		if(args[a] == ' ')
		{
			flag[b] = '\0';
		}
		if(args[a] == '\0')
		{
			flag[b] = '\0';
			return;
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

	tsksar[taskcount] = (Task *)malloc(sizeof(Task));

	tsksar[taskcount]->id = taskcount;
	strcpy(tsksar[taskcount]->name, taskname);
	strcpy(tsksar[taskcount]->isdone, vdone);

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
