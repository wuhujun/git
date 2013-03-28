#include <stdio.h>
//多线程开发的头文件。
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void * func_1(void* args)
{
    while(1){
        sleep(3);
        printf("this is func_1!\n");
    }
}

void * func_2(void* args)
{
    while(1){
        sleep(10);
        printf("this is func_2!\n");
    }
}

void * (* start) (void *) = &func_2 ;

int main()
{
    pthread_t pid1, pid2;

    if(pthread_create(&pid1, NULL, &func_1, NULL))
    {
        return 1;
    }

    if(pthread_create(&pid2, NULL, &func_2, NULL))
    {
        return 1;
    }

    while(1){
        sleep(3);
    }

    return 0;
}
