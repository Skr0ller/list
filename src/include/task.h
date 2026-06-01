#ifndef TASK_H
#define TASK_H

#define PERMS 0644
#define MAXVAL 30
#define BUFSIZE 100

typedef struct
{
	char name[MAXVAL];
	char isdone[MAXVAL];
	int id;
} Task;

/* Task id */
extern int taskcount = 0;

extern Task *tsksar[MAXVAL];

/* Main name for a file with tasks */
extern char mname[MAXVAL] = "tasks.txt";

/* Help command */
void helpcom();

/* update a command */
void update(char tskid[], char newname[], char newstatus[]);

/* Show task by id */
void stask(char tid[]);

/* Scan a command for arguments */
void scancom(char flag[], char name[], char args[], char stat[]);

/* Create a task */
void ctask(char taskname[], char mainname[], char vdone[]);

#endif