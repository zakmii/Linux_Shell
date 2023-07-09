#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/stat.h>
int main(int argc,char **argv){

	for(int i=1;i<argc;i++){
		struct stat st;
		if(stat(argv[i],&st)==0){
			printf("%s\n","ERROR: DIRECTORY ALREADY EXISTS!!" );
		}
		else{
			mkdir(argv[i],0777);
		}
	}
	return 0;
}