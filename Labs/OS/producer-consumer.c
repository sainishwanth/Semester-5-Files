#include<stdio.h>
#include<stdlib.h>
int mutex=1,full=0,empty=3,x=0;  //Initialization of semaphores 
                                                       // mutex = 1
                                                       //Full = 0 - Initially, all slots are empty. Thus full slots are 0
                                                      //Empty = 3 // All slots are empty initially
void producer();
void consumer();
int main()
{
	int n;
	printf("\n1.Producer\n2.Consumer\n3.Exit");
	while(1)
	{
		printf("\nEnter your choice:");
		scanf("%d",&n);
		switch(n)
		{
			case 1:	if((mutex==1)&&(empty!=0))
						producer();
					else
						printf("Buffer is full!!");
					break;
			case 2:	if((mutex==1)&&(full!=0))
						consumer();
					else
						printf("Buffer is empty!!");
					break;
			case 3:
					exit(0);
					break;
		}
	}
	
	return 0;
}

int wait(int s)
{
	return (--s);
}

int signal(int s)
{
	return(++s);
}

void producer()
{
	mutex=wait(mutex);
	full=signal(full);          //producer has placed the item and thus the value of “full” is 						increased by 1
	empty=wait(empty);  //producer produces an item then the value of “empty” is 					reduced  by 1 
                                                   //because one slot will be filled now

	x++;
	printf("\nProducer produces the item %d",x);
	mutex=signal(mutex);
}

void consumer()
{
	mutex=wait(mutex);
	full=wait(full);                      //consumer is removing an item from buffer, therefore the 						value of 
					//“full” is reduced by 1
	empty=signal(empty);       //consumer has consumed the item, thus increasing the 						value of 
                                                              //“empty” by 1
	printf("\nConsumer consumes item %d",x);
	x--;
	mutex=signal(mutex);
}
