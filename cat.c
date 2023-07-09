#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char **argv){

	FILE *f;
	char buff[100000];
	f=fopen(argv[1],"r");
	if(argc==2){
		if(!f){
			printf("%s\n","FILE DOES NOT EXIST!!" );
			return 0;
		}
		else{
			while(fgets(buff,100000,f)){
				printf("%s",buff);
			}
		}
	}
	else if(strcmp(argv[2],"-n")==0){
		if(!f){
			printf("%s\n","FILE DOES NOT EXIST!!" );
			return 0;
		}
		else{
			while(fgets(buff,100000,f)){
				printf("$");
				printf("%s\n",buff);
			}
		}
	}
	else if(strcmp(argv[2],"-no")==0){
		if(!f){
			printf("%s\n","FILE DOES NOT EXIST!!" );
			return 0;
		}
		else{
			int i=1;
			while(fgets(buff,100000,f)){
				printf("%d",i );
				i++;
				printf("%s\n",buff);
			}
		}
	}
	fclose(f);
	return 0;
}