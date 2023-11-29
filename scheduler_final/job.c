#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "job.h"

//////////////////////
// data definitions //
//////////////////////

#define NAME_LEN 20
#define SIZE_LEN 3

struct job {
	char job_name[NAME_LEN+1], user_name[NAME_LEN+1];
	int num_cpus, num_gpus, memory, priority;
	double time;
	struct job *next;
};

//////////////////////////
// function definitions //
//////////////////////////

void help() {
	printf("List of operation codes:\n");
	printf("\t'h' for help;\n");
	printf("\t'a' for adding a job to the scheduler;\n");
	printf("\t'p' for removing a job from the scheduler;\n");
	printf("\t'u' for searching jobs per user;\n");
	printf("\t'j' for searching jobs per capacity;\n");
	printf("\t'l' for listing all jobs;\n");
	printf("\t'q' for quit.\n");
}

void read(char *job_name, char *user_name, int *num_cpus, int *num_gpus, int *memory, double *time, int *priority) {
	if(job_name != NULL) {
		printf("Enter the name of the job: ");
		scanf("%s", job_name);
	}
	if(user_name != NULL) {
		printf("Enter the name of the user: ");
		scanf("%s", user_name);
	}
	if(num_cpus != NULL) {
		printf("Enter the number of CPUs: ");
		scanf("%d", num_cpus);
	}
	if(num_gpus != NULL) {
		printf("Enter the number of GPUs: ");
		scanf("%d", num_gpus);
	}
	if(memory != NULL) {
		printf("Enter the amount of memory: ");
		scanf("%d", memory);
	}
	if(time != NULL) {
		printf("Enter the amount of time: ");
		scanf("%lf", time);
	}
	if(priority != NULL) {
		printf("Enter the priority: ");
		scanf("%d", priority);
	}
}

/////////////////////////////////////////////////////////
// WARNING - WARNING - WARNING - WARNING - WARNING     //
/////////////////////////////////////////////////////////
// Do not modify anything before this point, otherwise //
// your solution will be considered incorrect.         //
/////////////////////////////////////////////////////////

struct job* head = NULL;
struct job* tail = NULL;

struct job * add_job(struct job *scheduler, char *job_name, char *user_name, int num_cpus, int num_gpus, int memory, double time, int priority) {

	// add code
	struct job *q, *temp, *prev;
	q = malloc(sizeof(struct job));

	q->next = NULL;

	q->num_cpus = num_cpus;
	q->num_cpus = num_cpus;
	q->num_gpus = num_gpus;
	q->memory = memory;
	q->time = time;
	q->priority = priority;

	strcpy(q->job_name, job_name);
	strcpy(q->user_name, user_name);
	
// if scheduler is empty, insert the new job node at the beginning
    if (scheduler == NULL) {
        q->next = NULL;
        scheduler = q;
        return scheduler;
    }
    // if the priority of the new job is higher than the first job in the linked list,
    // insert the new job node at the beginning
    else if (priority > scheduler->priority) {
        q->next = scheduler;
        scheduler = q;
        return scheduler;
    }
    else {
        temp = scheduler;
        prev = NULL;
        // traverse the linked list to find the correct position to insert the new job node
        while (temp != NULL && priority <= temp->priority) {
            prev = temp;
            temp = temp->next;
        }
        // if the priority of the new job is lower than the last job in the linked list,
        // insert the new job node at the end
        if (temp == NULL) {
            prev->next = q;
            q->next = NULL;
            return scheduler;
        }
        // if the priority of the new job is in between two jobs,
        // insert the new job node between them
        else {
            prev->next = q;
            q->next = temp;
            return scheduler;
		}
}
}

struct job * pop_job(struct job *scheduler) {

	// add code

	if(scheduler==NULL)
		printf("List is empty");

	else{
		struct job *temp = scheduler;
		// output format
		printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
		printf("| Job name             | User name            | CPUs | GPUs | Mem. | Time   | Priority |\n");
		printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
		printf("| %-20s | %-20s | %4d | %4d | %4d | %6.2f | %8d |\n", scheduler->job_name, scheduler->user_name, scheduler->num_cpus, scheduler->num_gpus, scheduler->memory, scheduler->time, scheduler->priority);
		printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
		scheduler = scheduler->next;
		free(temp);
		temp = NULL;
	}
	return scheduler;
}

void list_user(struct job *scheduler, char *user_name) {

	// add code
	struct job *q = scheduler;

	if(scheduler == NULL) {
		printf("The List is Empty");
		exit(1);
	}

	else{

		// output format
		printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
		printf("| Job name             | User name            | CPUs | GPUs | Mem. | Time   | Priority |\n");
		printf("|----------------------|----------------------|------|------|------|--------|----------|\n");

			while(q != NULL) {
				if (strcmp(q->user_name, user_name) == 0){
					printf("| %-20s | %-20s | %4d | %4d | %4d | %6.2f | %8d |\n", q->job_name, q->user_name, q->num_cpus, q->num_gpus , q->memory, q->time, q->priority);
					printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
					q = q->next;
					continue;
				}
				else{
					q = q->next;
				}
			}
			//scheduler = scheduler->next;
	// ...
//}
}
}


void list_jobs(struct job *scheduler, int num_cpus, int num_gpus, int memory, double time) {

	// add code
	if(scheduler == NULL) {
		printf("The List is Empty");
		exit(1);
	}
	else{

		struct job *q = NULL;
		
		q = scheduler;

		//output format

		printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
		printf("| Job name             | User name            | CPUs | GPUs | Mem. | Time   | Priority |\n");
		printf("|----------------------|----------------------|------|------|------|--------|----------|\n");


		while(q != NULL) {
			if(num_cpus >= q->num_cpus && num_gpus >= q->num_gpus && memory >= q->memory && time >= q->time){
				printf("| %-20s | %-20s | %4d | %4d | %4d | %6.2f | %8d |\n", q->job_name, q->user_name, q->num_cpus, q->num_gpus, q->memory, q->time, q->priority);
				printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
				q = q->next;
				continue;
		}
		else{
			q = q->next;
		}
		}  
    }
	// ...
}



void list_all_jobs(struct job *scheduler) {

	// add code
	if(scheduler == NULL) {
		printf("The List is Empty");
		exit(1);
	}

	else {

		struct job *q = NULL;
		q = scheduler;
		

		// output format
		printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
		printf("| Job name             | User name            | CPUs | GPUs | Mem. | Time   | Priority |\n");
		printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
		while(q != NULL) {
			printf("| %-20s | %-20s | %4d | %4d | %4d | %6.2f | %8d |\n", q->job_name, q->user_name, q->num_cpus, q->num_gpus , q->memory, q->time, q->priority);
			printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
			q = q->next;
		}
		// ...
}
}
struct job * clear_jobs(struct job *scheduler) {

	// add code
	struct job *q = NULL;
	q = scheduler;

	while(q != NULL) {
		q = q->next;
		free(scheduler);
		scheduler = q;
	}

	return scheduler;
}

