#include <semaphore.h>
#include <stdio.h>
#include <pthread.h>
#include<unistd.h>
#include<stdlib.h>

sem_t bowl;
void* phil(void * ab){
    while(1){

    if(sem_wait(&bowl)!=0){
        perror("error:");
    };
    
    printf("philoshpher is eating\n");
    
    sleep(2);

    if(sem_post(&bowl)!=0){
        perror("error:");
    };
    printf("philoshpher is thinking\n");
   
    }
}
int main(){
    pthread_t t[5];
    
   
 
    if(sem_init(&bowl, 0, 4)){
        perror("error ");
    };
    
    pthread_create(&t[0],NULL,phil,NULL);
    pthread_create(&t[1],NULL,phil,NULL);
    pthread_create(&t[2],NULL,phil,NULL);
    pthread_create(&t[3],NULL,phil,NULL);
    pthread_create(&t[4],NULL,phil,NULL);
    pthread_join(t[1],NULL);
    pthread_join(t[2],NULL);
    pthread_join(t[2],NULL);
    pthread_join(t[3],NULL);
    pthread_join(t[4],NULL);
    

    
}