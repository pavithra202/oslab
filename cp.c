#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(int argc,char* argv[]){
   int f1=open(argv[1],O_RDONLY);
   int f2=open(argv[2],O_RDWR|O_CREAT,S_IRWXU);
   char buff[1];
   while(read(f1,buff,sizeof(buff))!=0){
      write(f2,buff,sizeof(buff));
   }
   close(f1);
   close(f2);
   return 0;

}