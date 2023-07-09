#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<dirent.h>
#include<errno.h>

int main(int argc,char *argv[]){
	struct dirent **d;
	if(argc==1){
		int n=scandir(".",&d,0,NULL);
		for(int i=0;i<n;i++){
			char *name;
			name=d[i]->d_name;
			if(name[0]!='.'){
				printf("%s ",name);
				free(d[i]);
			}
		}
		free(d);
		printf("\n");
	}
	else if(strcmp(argv[1],"-a")==0){
		int n=scandir(".",&d,0,NULL);
		for(int i=0;i<n;i++){
			char *name;
			name=d[i]->d_name;
			printf("%s ",name);
			free(d[i]);
		}
		free(d);
		printf("\n");	
	}
	else if(strcmp(argv[1],"-sort")==0){
		int n=scandir(".",&d,0,alphasort);
		for(int i=0;i<n;i++){
			char *name;
			name=d[i]->d_name;
			if(name[0]!='.'){
				printf("%s ",name);
				free(d[i]);
			}
		}
		free(d);
		printf("\n");	
	}
	return 0;
}
