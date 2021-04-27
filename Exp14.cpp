#include <stdio.h>

int MFU_replacement(int pages[], int n, int m)
{
// To track the data stored in frames
// Initially, all frames are empty
int frame[m];

for (int i = 0; i < m; i++) frame[i] = -1;

// To track the no of references of each page
// Initially, none is used
int no_ref[10];

for (int i = 0; i < 10; i++) no_ref[i] = 0;

int faults = 0, frame_avail = 0; printf("Ref String\tPage Frames\n");
for (int i = 0; i < n; i++)
{
printf("	%d\t\t", pages[i]);

// Check if already available
int avail = 0;

for (int k = 0; k < m; k++)
{
if (frame[k] == pages[i])
{
avail = 1; no_ref[pages[i]]++;
}
}

if (avail == 0)
{
if (frame_avail < m)
{
frame[frame_avail] = pages[i]; no_ref[pages[i]]++; frame_avail++;
}
else
{
int max = -9999; int repindex;

for (int j = 0; j < m; j++)
{
if (no_ref[frame[j]] > max)
{
max = no_ref[frame[j]]; repindex = j;
}
}

frame[repindex] = pages[i]; no_ref[pages[i]]++;
}

faults++;

for (int k = 0; k < m; k++) printf("%d\t", frame[k]);
}

printf("\n");
}

return faults;
}

int main()
{
int pages[] = {5, 2, 0, 0, 2, 1, 2, 3, 5, 8, 7, 6,6};

int n = sizeof(pages) / sizeof(pages[0]); int capacity = 3;
int x = MFU_replacement(pages, n, capacity); printf("\nNumber of Page Faults: %d\n", x);
return 0;
}
