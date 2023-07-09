#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<dirent.h>
#include<errno.h>
#include<time.h>

int main(int argc,char **argv){
	
	time_t t;
	printf("%s\n",ctime(&t));
}
