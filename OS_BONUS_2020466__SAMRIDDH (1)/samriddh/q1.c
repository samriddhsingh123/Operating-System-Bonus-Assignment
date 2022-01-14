#include <semaphore.h>
#include <stdio.h>
#include <pthread.h>
#include<unistd.h>
#include<stdlib.h>

sem_t forks[5];
void* phil1(void * ab){
    int count=1;
    while(1){
    if(sem_wait(&forks[0])!=0){
        perror("");
    };
    if(sem_wait(&forks[1])!=0){
        perror("");
    };
    
    printf("Philoshpher 1 is eating %d times \n",count);
    sleep(2);

    if(sem_post(&forks[0])!=0){
        perror("");
    };
    if(sem_post(&forks[1])!=0){
        perror("");
    };
    
    printf("Philoshpher 1 is thinking %d times \n",count);
    count++;
    }
}
void* phil2(void * ab){
    int count =1;
    while(1){
    if(sem_wait(&forks[2]) !=0){
        perror("");
    }
    if(sem_wait(&forks[1]) !=0){
        perror("");
    };
   
    printf("Philoshpher 2 is eating %d times \n",count);
    sleep(2);

    if(sem_post(&forks[2])!=0){
        perror("");
    }

    if(sem_post(&forks[1]) !=0){
        perror("");
    };
    
    printf("Philoshpher 2 is thinking %d times \n",count);
    count++;
    }
}
void* phil3(void * ab){
    int count=0;
    while(1){
    if(sem_wait(&forks[3]) !=0){
        perror("");
    };
    if(sem_wait(&forks[2])!=0){
        perror("");
    };
    
    printf("Philoshpher 3 is eating %d times \n",count);
    sleep(2);

    if(sem_post(&forks[3])!=0){
        perror("");
    };
    if(sem_post(&forks[2])!=0){
        perror("");
    };
    
     printf("Philoshpher 3 is thinking %d times \n",count);
    count++;
    }
}
void* phil4(void * ab){
    int count=1;
    while(1){
    if(sem_wait(&forks[4])!=0){
        perror("");
    };
    if(sem_wait(&forks[3])!=0){
        perror("");
    };
    
    printf("Philoshpher 4 is eating %d times \n",count);
    sleep(2);

    if(sem_post(&forks[4])!=0){
        perror("");
    };
    if(sem_post(&forks[3])!=0){
        perror("");
    };
    
    printf("Philoshpher 4 is thinking %d times \n",count);
    count++;
    }
}

void* phil5(void * ab){
    int count=1;
    while(1){
    if(sem_wait(&forks[0])!=0){
        perror("");
    };
    if(sem_wait(&forks[4])!=0){
        perror("");
    };
    
    printf("Philoshpher 5 is eating %d times \n",count);
    sleep(2);

    if(sem_post(&forks[0])!=0){
        perror("");
    };
    if(sem_post(&forks[4])!=0){
        perror("");
    };
    
     printf("Philoshpher 5 is thinking %d times \n",count);
     count++;
    }
}
int main(){
    pthread_t t1;
    pthread_t t2;
    pthread_t t3;
    pthread_t t4;
    pthread_t t5;
    if(sem_init(&forks[0], 0, 1)!=0){
        perror("error");
    };
    if(sem_init(&forks[1], 0, 1)!=0){
        perror("error");
    };
    if(sem_init(&forks[2], 0, 1)!=0){
        perror("error");
    };
    if(sem_init(&forks[3], 0, 1)!=0){
        perror("error");
    };
    if(sem_init(&forks[4], 0, 1)!=0){
        perror("error");
    }; 

    pthread_create(&t1,NULL,phil1,NULL);
    pthread_create(&t2,NULL,phil2,NULL);
    pthread_create(&t3,NULL,phil3,NULL);
    pthread_create(&t4,NULL,phil4,NULL);
    pthread_create(&t5,NULL,phil5,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    pthread_join(t3,NULL);
    pthread_join(t4,NULL);
    pthread_join(t5,NULL);
}