#include <stdio.h>

int fifo_replacement(int pages[], int n, int m)
{
// To track the data stored in frames
// Initially, all frames are empty
int frame[m];
for (int i = 0; i < m; i++) frame[i] = -1;

int j = 0;
int faults = 0;
printf("Ref String\tPage Frames\n"); for (int i = 0; i < n; i++)
{
printf("	%d\t\t", pages[i]);

// Check if already available
int avail = 0;
for (int k = 0; k < m; k++)
{
if (frame[k] == pages[i]) avail = 1;
}

if (avail == 0)
{
frame[j] = pages[i]; j = (j + 1) % m; faults++;

for (int k = 0; k < m; k++) printf("%d\t", frame[k]);
}
printf("\n");
}
return faults;
}

int main()
{
int pages[] = {8, 2, 1, 4, 1, 0, 0, 5, 2, 1, 0, 3, 6, 7, 2, 6, 7, 7, 7, 1};
int n = sizeof(pages) / sizeof(pages[0]); int capacity = 3;

int x = fifo_replacement(pages, n, capacity); printf("\nNumber of Page Faults: %d\n", x); return 0;
}
