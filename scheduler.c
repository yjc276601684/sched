/******************************************************************************
* 
* Name: 	Jiacheng Yu
* Student No.: 	250799525
*
* scheduler.c 
*
******************************************************************************/

#include "scheduler.h"
#define FCFS 0
#define LIFO 1
#define SJF 2
#define RR 3



job_t *get_next_job(int mode, d_linked_list_t* jobs) {
	job_t *j;

	/*in the case of first come first serve*/
	if(mode == FCFS){
		j = dequeue(jobs);
	}

	/*in the case of last in first out*/
	else if(mode == LIFO){
		j = pop(jobs);
	}

	/*in the case of shortest job first*/
	else if(mode == SJF){
		job_t *current = pop(jobs);
		int shortest;
		/*if the linked list jobs is not empty, let shortest equals to the required time of the firt job*/
		if (current != NULL){
			shortest = current->required_time;
		}
		while (current != NULL){
			/*if there is any job takes shorter time than "shortest", reset "shortest"*/
			if (shortest > current->required_time){
				shortest = current->required_time;
				j = current;
			}
			
			current = pop(jobs);
			
		}
	}
	/*in the case of round robin*/
	else if(mode = RR){
		/*first round*/
		j = dequeue(jobs);
		/*second round*/
		if(jobs == NULL){
			j = pop(jobs);
		}
	}


	

	return j;
}
