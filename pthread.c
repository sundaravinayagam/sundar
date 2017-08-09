#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_var = PTHREAD_COND_INITIALIZER;

int count = 0;

void *even_thread()
{
	while(1)
		{
		pthread_mutex_lock(&lock);
		
		if(count % 2 == 0)
		{
			pthread_cond_wait(&cond_var,&lock);
		}
		count++;
		printf("even thread: %d\n",count);
		pthread_cond_signal(&cond_var);
		if(count >= 10)
		{
			pthread_mutex_unlock(&lock);
			break;
			return 0;
		}
		pthread_mutex_unlock(&lock);
		}
}

void *odd_thread()
{
	while(1)
		{
		if(count % 2 != 0)
			{
			pthread_cond_wait(&cond_var,&lock);
			}
		count++;
		printf("odd thread: %d\n",count);
		pthread_cond_signal(&cond_var);
		if(count >= 10)
		{
			pthread_mutex_unlock(&lock);
			break;
			return 0;
		}
		pthread_mutex_unlock(&lock);
		}
}

int main(void)
{
	pthread_t t1,t2;
	int res;
	
	res = pthread_create(&t1,NULL,(void *)&odd_thread,NULL);
	if(res == 0)
	{
		printf("odd thread created....\n");
	}
	
	res = pthread_create(&t2,NULL,(void *)&even_thread,NULL);
	if(res == 0)
	{
		printf("even thread created....\n");
	}

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);

	return(0);
}
