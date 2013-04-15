/*open的系统调用。
 * 为了创建一个新的文件描述符，你需要使用系统调用open.
 */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
/*简单的说，open建立了一条到文件或设备的访问路径，如果调用成功。
 * 它将返回一个可以被read，write和其他系统调用使用的文件描述符。
 * 这个文件描述符是唯一的，它不会与任何其他运行中的程序共享。
 * 如果两个程序同时打开同一个文件，它们会分别得到两个不同的文件描述
 * 符。如果两个程序同时打开一个文件，它们会分别得到两个不同的文件描述
 * 符，如果它们都对文件操作，那么它们都会各写各的。它们分别接着上次离
 * 开的地方继续往下写。
 * 准备打开的文件或设备的名字作为参数path传给函数，oflags参数用于指定
 * 打开文件所采取的动作。
 * open调用还可以在oflags参数中包括下列可选模式的组合(用按位或)操作。
 */
 main(){
 int nopen ;
 /*O_RDONLY ： 以只读方式打开。
  *O_WRONLY ： 以只写方式打开。
  *O_RDWR   ： 以读写方式打开。
  *open调用还可以在oflag参数中包括下列可选模式的组合(用按位或操作)。
  *O_CREAT: 如果需要，就按照参数mode中给出的访问模式创建文件。
  *O_EXCL :与O_CREAT一起使用，确保调用者创建出文件。Open调用是一个原子操作，也就是说它
  *只执行一个函数调用。使用这个可选模式可以防止两个程序同时创建同一个文件。如果文件已经
  *存在，open调用将失败。
  *
  * open调用在成功时返回一个新的文件描述符(它总是一个非负整数)，在失败时返回-1并设置全
  * 局变量errno来指明失败的原因。
  * 当使用带有O_CREAT 标志的open调用来创建文件时，必须使用三个参数的open调用。
  * 第三个参数mode是几个标志按位或后得到的。
  * S_IRUSR:读权限，文件属主。
  * S_IWUSR:写权限，文件属主。
  * 1.umask是一个系统变量，它的作用是：当文件被创建时，为文件的访问权限设定一个掩码
  *
  */
 nopen = open("test3",O_CREAT ,S_IWUSR|S_IXOTH);
 nopen = open("test4",O_CREAT ,S_IWUSR|S_IRWXO|S_IXGRP|S_ISUID);
 if(nopen==-1){
 	printf("Open the files failed !");
 }
 /*
  * close系统调用，可以使用close调用终止文件描述符fildes与其对应文件之间的关联，
  */
 if(!close(nopen)){
 	printf("Close the files has been opened!\n\n");
 }
 exit(0);
 }
/*
 *关于文件的访问权限，有多个因素会对文件的访问权限产生影响。
 *首先，指定的访问权限只有在创建文件时会使用。其次，用户掩
 *码(由shell的umask命令设定)会影响到被创建文件的访问权限。
 *
 */
 /*
  * ioctl调用有点像是个大杂烩，它提供了一个用于控制设备及其描述符行为和配置底层服务的接口，
  * 终端，文件描述符，套接字甚至磁带机都可以有为它们定义的ioctl
  */
