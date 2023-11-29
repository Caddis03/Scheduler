#ifndef JOB_HEADER
#define JOB_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/////////////////////
// data definitions //
//////////////////////

#define NAME_LEN 20
#define SIZE_LEN 3

/////////////////////////
// function prototypes //
/////////////////////////

void help();
void read(char *job_name, char *user_name, int *num_cpus, int *num_gpus, int *memory, double *time, int *priority);
struct job * add_job(struct job *scheduler, char *job_name, char *user_name, int num_cpus, int num_gpus, int memory, double time, int priority);
struct job * pop_job(struct job *scheduler);
void list_user(struct job *scheduler, char *user_name);
void list_jobs(struct job *scheduler, int num_cpus, int num_gpus, int memory, double time);
void list_all_jobs(struct job *scheduler);
struct job * clear_jobs(struct job *scheduler);

#endif