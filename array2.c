#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    FILE *fp;
    int i=0;
    char answer;
    int notes[15];
    printf("Hi! Welcome to software class note system.\n");

    while(1){
        printf("who r u ? :");
        scanf("%c",&answer);
        if( answer == 's' || answer == 'S'){
            printf("Please enter your student number:\n");
            scanf("%d",&i);
            if(i<1 || i>15){
                printf("Your Number is Invalid!!");
            } else {
                fp = fopen("notes.txt", "r");
                if(fp == NULL){
                    printf("File can't read. Please try again!!");
                } else {
                    for(int j=0; j<15; j++){
                        fscanf(fp, "%d", &notes[j]);
                    }
                    fclose(fp);
                    printf("Your note is %d", notes[i-1]);
                }
            }
            break;

        } else if(answer == 't' || answer == 'T'){
            printf("Welcome Teacher!!\n");
            i=0;
            while(i<15){
                printf("Enter student %d. note:",(i+1));    //get variables from user
                scanf("%d",&notes[i]);                      //read variables                
                i=i+1;
            }
            //file open
            fp = fopen("notes.txt","w");
            if (fp == NULL){
                printf("File can't open correctly!! Please try again.");    //Error Check for file
            } else {
                for(int j=0; j<15; j++){
                    fprintf(fp,"%d\n",notes[j]);
                }
                fclose(fp);
                printf("Notes are saved!! Goodbye!");
            }
            break;
        }
        else if(answer == 'q'){
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
