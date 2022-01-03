#include<stdio.h>
#include<time.h>
void main(){
    clock_t start_time;
    clock_t end_time;
    double CTU;
    start_time = clock();
    end_time = clock();
    CTU= (end_time - start_time) / CLOCKS_PER_SEC;
    printf("Time: %f",CTU);
}