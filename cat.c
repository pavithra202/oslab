#include<stdio.h>
int main(int argc,char* argv[]){
    char ch;
    FILE* file=fopen(argv[1],"r");
    if(file==NULL){
        printf("file does not exist\n");
    }
    else{
        while(fread(&ch,sizeof(ch),1,file)){
          printf("%c",ch);
        }
    printf("file exist\n");
    }
fclose(file);
return 0;
}