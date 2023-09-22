#include <unistd.h>
#include <stdio.h>

void yourTurn(void)
{
	while(1)
	{
	sleep(1);
	printf("Your Turn\n");

	}
}

void myTurn()
{
	while(1)
	{
		sleep(2);
		printf("My turn\n");
	}
}

int main(int argc, char *argv[])
{
	myTurn();
	yourTurn();

	return 0;
}
