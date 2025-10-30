#include <stdio.h>
#include <stdlib.h>

int main(){
    int sayac;  //while i dondurebilmek icin sayac tam sayi degiskinini olusturdum.
    int notlar[7];  //notlari depolayabilmek icin olusturdugumuz array
    int temp;
    sayac=0;    
    while(sayac<7){     //kullanidan 7 tane not istemeyebilmek icin while() kullan
        printf("Lutfen %d. notu giriniz:\n",(sayac+1));    //kullanicidan i ninci notu alabilmek adina terminala mesaj yazidir. 
        scanf("%d",&notlar[sayac]);  //verilen sayiyi al ve notlar arryinin i ninci elemanina koy.
        sayac=sayac+1;    //dongunun devam etmesi adina i yi 1 arttir.
    }
    sayac=0;
    while(sayac<(7/2)){
        //1 i al bosa dok, 
        //7yi al 1 e dok,
        //bosu al 7 ye dok,
        //2 i al bosa dok, 
        //6yi al 2 e dok,
        //bosu al 6 ye dok,
        //3 i al bosa dok, 
        //5yi al 3 e dok,
        //bosu al 5 ye dok,
        temp=notlar[sayac]; 
        notlar[sayac]=notlar[7-sayac];
        notlar[7-sayac]=temp;
        sayac=sayac+1;
        
        
    }
    sayac=0;
    while(sayac<7){
        printf("%d\n",notlar[sayac]);  //notlar arrayinin icindeki tum notlari sirasiyla yazdir
        sayac=sayac+1;
    }
}  















//kullanicidan 7 tane not al sirasi ile arraayin icine at 
//notlar arrayinin icindeki tum notlari sirasiyla yazdir
//sonra bu arrayin icindeki notlari siralama olarak tam tersi olsun while kullan
