#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<pthread.h>

char *EOL(char *s)
{
    char *n = malloc(strlen(s?s:"\n"));
    if(s)
	    strcpy( n, s );
    n[strlen(n)-1]='\0';
    return n;
}

/*void *P(void* arg){
	pthread_detach(pthread_self());
	pthread_exit(NULL);
}

void pt(char *argv){
	pthread_t ptid;

	pthread_create(&ptid,NULL,(void*)system,"date");
	pthread_join(ptid,NULL);
	pthread_exit(NULL);
}*/

void f(char **argv){
	pid_t pid;
	pid=fork();
	if(pid<0){
		printf("%s\n","ERROR: CHILD ABORTED!!" );
	}
	else if(pid==0){
		if(execv(argv[0],argv)==-1){
			printf("%s\n","ERROR: NO SUCH EXTERNAL COMMAND!!" );
			return;		
		}
	}
	else{
		wait(NULL);
	}
}

void read_cmd(){
	for(;;){
		printf("> ");
		char** cmd = (char**)malloc(100* sizeof(char*));

		int bytes_read;
		size_t size1 = 100;
		char *commands;
		commands = (char *) malloc (size1);
		bytes_read = getline (&commands, &size1, stdin);
		
		char *piece=strtok(commands," \n");

		int counter=0;
		while(piece){
			cmd[counter]=(char*)malloc(100);
			cmd[counter++]=piece;
			piece=strtok(NULL," \n");
		}
		if(!cmd[0]){
			continue;
		}
		if(strcmp(cmd[0],"exit")==0 && counter==1){
			return;
		}
		else if(strcmp(cmd[0],"pwd")==0){
			char s[100];
			printf("%s\n",getcwd(s,100) );
		}
		else if(strcmp(cmd[0],"cd")==0){
			char s[100];
			chdir(cmd[1]);
			printf("%s\n",getcwd(s,100));

		}
		else if(strcmp(cmd[0],"echo")==0){
			
			if(strcmp(cmd[1],"-help")==0){
				printf("echo 'text' -> prints the text again\necho --help  -> opens help menu\n ");
				continue;
			}
			for(int i=1;i<counter;i++){
				printf("%s ",cmd[i]);
			}
			printf("\n");
		}
		else{
			f(cmd);
		}

		free(commands);
		
	}
}

int main(int argc, char **argv){

	read_cmd();
	return 0;
}