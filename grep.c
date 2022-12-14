#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char* argv[]){
    FILE* fp=fopen(argv[1],"r");
    char* buff=NULL;
    char line[50];
    size_t len;
    while(getline(&buff,&len,fp)!=-1){
        if(strstr(buff,argv[2])){
            printf("%s",buff);
        }
    }
fclose(fp);
return 0;
}