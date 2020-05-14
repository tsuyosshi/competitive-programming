#include<stdio.h>
#include<cmath>
int main(){
    int n=1;
    while(true){
        if(1.0+pow(0.5,n)>1.0)n++;
        else {
            printf("%d",n);
            break;
        }
    }

}