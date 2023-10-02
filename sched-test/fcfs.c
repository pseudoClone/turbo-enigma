#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct proc {
	int br_time;
	int ar_time;
	int cm_time;
	int wt_time;
	int ta_time;
	char pid[100];
} Proc;

int main(int argc, char *argv[]) {
	int n_proc;
	int idle_time = 0;
	int total_wt = 0, total_ta = 0;
	printf("Enter the number of processes: \n");
	scanf("%d", &n_proc);
	Proc temp;

	Proc *process = malloc(n_proc * sizeof(Proc));

	for (int i = 0; i < n_proc; i++) {
		printf("Enter pid:");
		scanf("%s", process[i].pid);
		printf("Enter arrival time:");
		scanf("%d", &process[i].ar_time);
		printf("Enter burst time:");
		scanf("%d", &process[i].br_time);
	}

	for (int i = 0; i < n_proc; i++) {
		for (int j = 0; j < n_proc - i - 1; ++j) {
			if (process[j].ar_time > process[j + 1].ar_time) {
				temp = process[j];
				process[j] = process[j + 1];
				process[j + 1] = temp;
			}
		}
	}

	if(process[0].ar_time != 0){
		idle_time+= process[0].ar_time;
	}

	process[0].cm_time = process[0].ar_time + process[0].br_time;
	process[0].ta_time = process[0].cm_time - process[0].ar_time;
	process[0].wt_time = process[0].ta_time - process[0].br_time;

	total_wt += process[0].wt_time;
	total_ta += process[0].ta_time;

	for(int i = 1; i < n_proc; ++i){
		process[i].cm_time = process[i-1].cm_time + process[i].br_time;
		process[i].ta_time = process[i].cm_time - process[i].ar_time;
		process[i].wt_time = process[i].ta_time - process[i].br_time;

		total_wt += process[i].wt_time;
		total_ta += process[i].ta_time;

		if(process[i-1].cm_time < process[i].ar_time)
			idle_time += (process[i].ar_time - process[i-1].cm_time);
	}

	printf("Average Waiting Time: %f\n", (float)total_wt/n_proc);
	printf("Average Turnaround Time: %f\n", (float)total_ta/n_proc);
	printf("Total Idle Time: %d\n", idle_time);

	free(process);
	return 0;
}
