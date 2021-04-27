#include <stdio.h>

void non_pre_pri(int processes[], int n, int bt[], int at[], int pri[])
{
int wt[n];	// Waiting Times
int tat[n]; // Turn Around Times
int pro[n]; // Track whether process is scheduled or not
for (int i = 0; i < n; i++)
pro[i] = 1;

int cur_time = 0, remain = n; while (remain > 0)
{
int min_value = 9999, min_key = -1; for (int i = 0; i < n; i++)
{
if (pro[i] == 1 && pri[i] < min_value && at[i] <= cur_time)
{
min_key = i; min_value = pri[i];
}
}

if (min_key != -1)
{
pro[min_key] = 0;
wt[min_key] = cur_time - at[min_key]; cur_time += bt[min_key];
tat[min_key] = bt[min_key] + wt[min_key]; remain--;
}
else
cur_time++;
}


printf("PID\tBT\tAT\tPTY\tWT\tTAT\tFT\n");

int total_wait = 0, total_turn_around = 0; for (int i = 0; i < n; i++)
{
total_wait += wt[i]; total_turn_around +=  tat[i]; int compl_time = tat[i] + at[i];
printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", processes[i], bt[i], at[i], pri[i], wt[i], tat[i], compl_time);
}

printf("Average waiting time = %f\n", (float)total_wait / (float)n); printf("Average turn around time = %f\n", (float)total_turn_around / (float)n);
}

void pre_pri(int processes[], int n, int bt[], int at[], int pri[])
{
int wt[n];	// Waiting Times
int tat[n]; // Turn Around Times
int pro[n]; // Track whether process is scheduled or not
for (int i = 0; i < n; i++)
pro[i] = 1;

int bt2[n];
for (int i = 0; i < n; i++) bt2[i] = bt[i];

int cur_time = 0, remain = n; while (remain > 0)
{
int min_value = 9999, min_key = -1; for (int i = 0; i < n; i++)
{
if (pro[i] == 1 && pri[i] < min_value && at[i] <= cur_time)
{
min_key = i; min_value = pri[i];
}
}

if (min_key != -1)
{
bt2[min_key]--;
if (bt2[min_key] == 0)
{
pro[min_key] = 0; remain--;
tat[min_key] = cur_time + 1 - at[min_key]; wt[min_key] = tat[min_key] - bt[min_key];
}

}
cur_time++;
}

printf("PID\tBT\tAT\tPTY\tWT\tTAT\tFT\n");

int total_wait = 0, total_turn_around = 0; for (int i = 0; i < n; i++)
{
total_wait += wt[i]; total_turn_around +=  tat[i]; int compl_time = tat[i] + at[i];
printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", processes[i], bt[i], at[i], pri[i], wt[i], tat[i], compl_time);
}

printf("Average waiting time = %f\n", (float)total_wait / (float)n); printf("Average turn around time = %f\n", (float)total_turn_around / (float)n);
}

int main()
{
int processes[] = {1, 2, 3, 4};
int n = sizeof processes / sizeof processes[0];

int burst_time[] = {6, 8, 7, 3};
int arrival_time[] = {1, 1, 2, 3};
int priority[] = {4, 3, 1, 2};

printf("Priority Scheduling (Non-Preemptive): \n"); non_pre_pri(processes, n, burst_time, arrival_time, priority);

printf("\nPriority Scheduling (Non-Preemptive): \n"); pre_pri(processes, n, burst_time, arrival_time, priority); return 0;
}
