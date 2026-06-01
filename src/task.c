#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "../include/task.h"

Task *taskcount[MAXVAL];
int taskcount = 0;
char mname[MAXVAL] = "tasks.txt";

void stask(char tid[])
{
	int b = 0;

	if(strlen(tid) > 2)
	{
		b = (tid[0] - '0') * 10 + (tid[1] - '0');
	}
	else
	{
		b = tid[0] - '0';
	}

	if(b > taskcount || b > 30)
	{
		printf("Such task doesn't exist\n");
	}
	else
	{
		printf("name: %s\nis done: %s", tsksar[b]->name, tsksar[b]->isdone);
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
		c++, ++a;

		if(args[a] == ' ')
		{
			name[c] = '\0';
		}
		if(args[a] == '\0')
		{
			name[c] = '\0';
			return;
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

void update(char tskid[], char newname[], char newstatus[])
{

}