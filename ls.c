#include<stdio.h>
#include<dirent.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>

void printfsubdir(char* dir){
	DIR* subdir=opendir(dir);
	struct dirent* subdirinfo;
	while(subdirinfo=readdir(subdir)){
		if(subdirinfo->d_type==DT_DIR){
			printf("DIR: %s",subdirinfo->d_name);
			if((strcmp(subdirinfo->d_name,".")!=0) && (strcmp(subdirinfo->d_name,".."))){
				printfsubdir(subdirinfo->d_name);
			}
			else{
				printf("\tFile: %s\n",subdirinfo->d_name);
			}
		}
	}
}

int main(int argc,char* argv[]){
	DIR* d=opendir(argv[1]);
	if(d==NULL){
		printf("Directory does not exist\n");
		return -1;
	}
struct dirent* dirinfo;
while(dirinfo=readdir(d)){
	if(dirinfo->d_type==DT_DIR){
		printf("dir: %s",dirinfo->d_name);
		if((strcmp(dirinfo->d_name,".")!=0) && ((strcmp(dirinfo->d_name,"..")!=0))){
			printfsubdir(dirinfo->d_name);
		}
		else{
			printf("file: %s\n",dirinfo->d_name);
		}
	}
}
closedir(d);
return 0;
}