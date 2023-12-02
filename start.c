#include<stdio.h>
#include<stdlib.h> // exec()
#include<unistd.h>

int main(int argc, char *argv[])
{

int ch;

while(1)
{
printf("\n 1. DataInput\n");
printf("\n 2. Semaphore\n");
printf("\n 3. weather Module\n");
printf("\n 4. Client\n");
printf("\n 5. Exit\n");
scanf("%d", &ch);
switch(ch)
{
case 1: execl("/home/sys1/project_case/ddd/input","./input" ,argv[1] ,argv[2] ,argv[3], NULL);
	break;
	
case 2: execl("./sem",NULL);
	break;
	
case 3: execl("./pred",NULL);
	break;

case 4: execl("./cli",NULL);
	break;
	
case 5: printf("\nprogram terminated successfully\n");
	exit(1);
}		
}

return 0;
}
