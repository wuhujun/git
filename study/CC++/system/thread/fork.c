#include <stdio.h>
#include <unistd.h>

main(){
	pid_t pid ;
	printf("Now only one process\n") ;
	printf("Fork calling \n");
	pid = fork();
	if(!pid){
		printf("I am a child processes\n");
	}else if(pid >0 )
	{
         	printf("I am a partner\n");
	}
	else{
	     printf("Fork failed\n");
	}
	int i= 0 ;
	while(i!=10){
		int ret = 0 ;
		ret = fork();
		if(ret == -1){
			perror("fork");
		}
		i++ ;
	}
}
