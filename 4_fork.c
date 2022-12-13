#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<fcntl.h>
int main(void)
{
  pid_t cpid;
  int done, status;
  cpid = fork( );
  if (cpid == 0)
      {
    	printf("\nThe child is active.");
    	printf("\n pid = %d", getpid());
    	printf("\n ppid = %d", getppid());
   	 
      }
  else
      {
     	 sleep(3);
   	 done=wait(&status);
   	 printf("\nThe Parent process is active.");
   	 printf("\npid = %d", getpid());
   	 printf("\nparent id of the parent process = %d\n",getppid() );
    }
  return 0;

}
