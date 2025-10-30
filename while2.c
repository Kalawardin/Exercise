#include <stdio.h> 

int main(){
    int a;
    int mom = 0;

    printf("Hello! Please enter a number:");
    scanf("%d",&a);

    if(a<10){
        while(mom < 5){
        printf("Anan\n");
        mom++;
    }
    }
    else{
        mom = 200;
        while(mom > -200){
        printf("%d\n",mom);
        mom--;
    }
    }
    return 0;
}