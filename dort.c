#include <stdio.h>

int toplama(int a, int b){
	
    return (a+b);
}

int cikarma(int a, int b){

    return (a-b);
}

int carpma(int a, int b){

    return (a*b);
}

int bolme(int a, int b){

    return (a/b);
}

int main(){

    int a,b;
    char islem;

    printf("Hello!! Pls enter 2 number:\n");
    printf("Number 1:");

    scanf("%d",&a);

    printf("Number 2:");

    scanf("%d",&b);

    printf("Please enter an operation (+, -, *, /): ");
    scanf(" %c", &islem);

    switch (islem) {
        case '+':
        printf("%d\n", toplama(a,b));
        break;

        case '-':
        printf("%d\n", cikarma(a,b));
        break;

        case '*':
        printf("%d\n", carpma(a,b));
        break;

        case '/':
        printf("%d\n", bolme(a,b));
        break;
    }
    
    return 0;
}