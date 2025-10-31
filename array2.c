#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int i=0;
    char answer;
    int notes[15];
    printf("Hi! Welcome to software class note system.\n");

    while(1){
        printf("who r u?");
        scanf("%c",&answer);
        if( answer == 's' || answer == 'S'){
            printf("Please enter your student number:\n");
            scanf("%d",&i);
            printf("Your note is %d",notes[i]);

        } else if(answer == 't' || answer == 'T'){
            printf("Welcome Teacher!!");
             while(i<15){
                printf("Enter student %d. note:",(i+1));    //get variables from user
                scanf("%d",&notes[i]);                      //read variables                
                i=i+1;
            }

        }else if(answer == 'q'){
            printf("Goodbye.\n");
            break;

        }else{
            printf("Unknown command type. Please enter 't' or 's'.\n");
            while (getchar() != '\n'); // buffer cleaning
            continue; // dongunun basina doner
        }
    }    
}
 
    
/*
    while(i<15){
        printf("Enter student %d. note:",(i+1));    //get variables from user
        scanf("%d",&notes[i]);                      //read variables                
        i=i+1;
    }

    printf("\nHere's the notes:\n");
    i=0;
    while (i<15){

        printf("Student %d\n",(i+1));
        printf("%d\n",notes[i]);
        i=i+1;
    }
    
    return 0;
*/











//kullanicidan 15 tane not al sirasi ile arraayin icine at sonra bu arrayin icindeki notlari siralama olarak tam tersi olsun while kullan
