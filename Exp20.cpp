#include <stdio.h> #include <stdlib.h> #include <sys/wait.h> #include <sys/types.h> #include <sys/stat.h> #include <unistd.h>

int main()
{
int n, flag = 1;
printf("1. Display List of Files in Current Directory\n"); printf("2. Create a New Directory\n");
printf("3. Change the Directory\n"); printf("4. Exit\n");

char str[20]; while (flag)
{
printf("\nEnter your choice: "); scanf("%d", &n);
switch (n)
{
case 1:
printf("List of Files in Directory: \n\n"); system("ls -a");
break; case 2:
printf("Enter the name of New Directory: "); scanf("%s", str);
mkdir(str, 0700);
printf("New Directory has been Created\n"); break;
case 3:
printf("Enter the name of Next Directory: "); scanf("%s", str);
if (chdir(str) != 0)
{
printf("No such Directory Found\n"); break;

}
chdir(str);
printf("Directory has been Changed\n"); break;
case 4:
flag = 0; break;
}
}
printf("\n"); return 0;
}
