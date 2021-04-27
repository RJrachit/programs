#include <stdio.h>
int main()
{
const int P = 5; const int R = 3;
int processes[5] = {0, 1, 2, 3, 4};
int avail[3] = {2, 4, 5};

int maxm[5][3] = {{1, 0, 3},

{3,	2,	2},
{1,	0,	1},
{2,	2,	2},
{7,	4,	3}};

int allot[5][3] = {{0, 1, 0},
{1, 0, 6},
{2, 0, 2},
{1, 1, 0},
{1, 1, 2}};

// Algorithm:
int need[P][R];
for (int i = 0; i < P; i++)
for (int j = 0; j < R; j++)
need[i][j] = maxm[i][j] - allot[i][j];

int finish[P];
for (int i = 0; i < P; i++) finish[i] = 0;

int safeSeq[P]; int work[R];
for (int i = 0; i < R; i++) work[i] = avail[i];

int count = 0; while (count < P)
{
int found = 0;

for (int p = 0; p < P; p++)
{
if (finish[p] == 0)
{
int j;
for (j = 0; j < R; j++)
if (need[p][j] > work[j]) break;

if (j == R)
{
for (int k = 0; k < R; k++) work[k] += allot[p][k];

safeSeq[count++] = p; finish[p] = 1;
found = 1;
}
}
}

if (found == 0)
{
printf("System is not in safe state\n"); return 0;
}
}

printf("System is in safe state.\nSafe Sequence: "); for (int i = 0; i < P; i++)
printf("%d ", safeSeq[i]); printf("\n");
return 0;
}
