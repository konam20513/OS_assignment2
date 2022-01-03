#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<time.h>
void sigterm(){
    printf("Program ends");
}
void sigalrm(){
    alarm(2);
}
void main(){
    pid_t S1=fork();
    if(S1==0){
        signal(SIGTERM, sigterm);
    }
    waitpid(S1,NULL,0);
    pid_t SR=fork();
    if(SR==0){
		char *temp[]={"./E1",NULL};
		execvp(temp[0],temp);
        signal(SIGALRM,sigalrm);
    }
    waitpid(SR,NULL,0);
    pid_t ST=fork();
    if(ST==0){
		char *temp[]={"./E2",NULL};
		execvp(temp[0],temp);
        signal(SIGALRM,sigalrm);
    }
    waitpid(ST,NULL,0);
}
