/*与文件有关的系统调用。
 *1.lseek系统调用
 *lseek系统调用对文件描述符fildes的读写指针进行设置。也就是说
 *可以用它来设置文件的下一个读写位置。
 *
 */
 #include <unistd.h>
 #include <sys/types.h>
 off_t lseek(int fildes , off_t offset , int whence) ;
 /*
  *offset参数用来指定位置，而whence参数定义该偏移值的用法，
  *SEEK_SET offset是一个绝对位置。
  *SEEK_CUR offset是相对于当前位置的一个相对位置。
  *SEEK_END offset是相对于文件尾的一个相对位置。
  *
  */ 
  #include <unistd.h>
  #include <sys/stat.h>
  #include <sys/types.h>
  int fstat (int fildes ,struct stat * buf);
  int stat (const char * path , struct stat * buf);
  int lstat (const char * path , struct stat *buf);
  /*相关函数stat和lstat返回的是
   *其他与文件管理有关的系统调用。
   *除此之外，还有许多其他的系统调用能够操作这些底层文件描述。
   *通过它们，程序可以控制文件的使用方式和返回文件的状态信息。
   *2. fstat ,stat 和lstat系统调用
   *fstat系统调用返回与打开文件描述符相关的文件状态信息，该信息将会写到一个buf结构中
   *buf的地址以参数形式传给fstat.
   *stat 结构在不同的类unix系统上会有所变化。
   *3.dup2系统调用提供了一种复制文件描述符的方法，使我们能够通过两个或者多个
   *不同的文件描述符来访问同一个文件。
   */
   #include <unistd>
   int dup( int fildes);
   int dup( int fildes , int fildes2);
