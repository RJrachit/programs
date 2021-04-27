#include <stdio.h>

void CSCAN(int arr[], int n, int head, int disk_size)
{
// Sorting Disk Locations
for (int i = 0; i < n; i++)
{
for (int j = i; j < n; j++)
{
if (arr[i] > arr[j])
{
int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
}
}
}

int disk_location;
for (int i = 0; i < n; i++)
{
if (head == arr[i])
{
disk_location = i; break;
}
}

int seek_count = 0;
int distance, cur_track; int sequence[n + 1], j = 0;

// Scanning Left Direction
for (int i = disk_location; i >= 0; i--)
{
cur_track = arr[i];
distance = (cur_track - head > 0) ? (cur_track - head) : (head - cur_track); seek_count += distance;
head = cur_track; sequence[j] = arr[i]; j++;

}

// To mark the Direction reversal
sequence[j] = 0;
j++;

// Scanning Right Direction starting from right
seek_count += head + disk_size;
head = disk_size;
for (int i = n - 1; i > disk_location; i--)
{
cur_track = arr[i];
distance = (cur_track - head > 0) ? (cur_track - head) : (head - cur_track); seek_count += distance;
head = cur_track; sequence[j] = arr[i]; j++;
}

printf("Total number of seek operations = %d\n", seek_count); printf("Seek Sequence is: ");

for (int i = 0; i <= n; i++) printf("%d ", sequence[i]);
printf("\n");
}

int main()
{
int requests[] = {50, 156, 39, 67, 145, 76, 11, 66, 122};
int n = sizeof(requests) / sizeof(requests[0]);
int head = 50;
int disk_size = 200;

CSCAN(requests, n, head, disk_size);
return 0;
}
