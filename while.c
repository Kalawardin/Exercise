#include <stdio.h>
int main(){

    int a;
    int counter=0;
    printf("Hello, Pls enter a number:");
    scanf("%d",&a);

    if(a>10) {
        while(counter<5){
        printf("fuat\n");
        counter++;
        }
    }       
    else{
        counter=10;
        while(counter>=-30){
            if(!(counter%2)){
                printf("%d\n",counter);
                
        }
            counter--;          
        }
    }

return 0;

}
