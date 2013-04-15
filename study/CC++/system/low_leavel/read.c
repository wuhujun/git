#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*系统调用read的作用是：从文件描述符fildes相关联的文件里读入nbytes个字
 * 节的数据，并将其写入到数据区buf中。
 */
 main(){
	char buffer [128] ;
	int nread ;

	nread = read(0 ,buffer , 128);
	if(nread ==-1){
		write(2,"A read error has occurred\n" ,26);
	}
	if((write(1,buffer ,nread))!= nread){
		write(2, "A write error has occurred\n" ,27);
	}
	exit (0);
}
