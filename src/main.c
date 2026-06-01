#include <unistd.h>
#include <stdio.h>
#include "../include/task.h"

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
					printf("Task have been created!\n");
					printf("Task id: %d\n", taskcount);
					break;
				case 'h':
					helpcom();
					break;
				case 's':
					stask(buffname);
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