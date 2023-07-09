#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/stat.h>
int main(int argc,char **argv){

	for(int i=1;i<argc;i++){
		struct stat st;
		if(stat(argv[i],&st)==-1){
			printf("%s\n","ERROR: DIRECTORY/FILE DOES NOT EXISTS!!" );
		}
		else{
			remove(argv[i]);
		}
	}
	return 0;
}