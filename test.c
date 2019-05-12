#include<pthread.h>
#include<stdio.h>

void *mythread1();  //thread prototype
void *mythread2();

int main(){
    pthread_t thread[2];
    //starting the thread
    pthread_create(&thread[0],NULL,mythread1,NULL);
    pthread_create(&thread[1],NULL,mythread2,NULL);
    //waiting for completion
	printf("TEST1\n");
    //pthread_join(thread[0],NULL);
	printf("OK\n");
    pthread_join(thread[1],NULL);
	printf("TEST2\n");


    return 0;
}

//thread definition
void *mythread1(){
    int i;
    for(i=0;i<5;i++)
        printf("Thread 1 Running\n");
	return 0;
}
void *mythread2(){
    int i;
    for(i=0;i<5;i++)
        printf("Thread 2 Running\n");
	return 0;
}
