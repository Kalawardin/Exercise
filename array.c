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
        temp=notlar[sayac]; 
        notlar[sayac]=notlar[6-sayac];
        notlar[6-sayac]=temp;
        sayac=sayac+1;
        
        
    }
    sayac=0;
    while(sayac<7){
        printf("%d\n",notlar[sayac]);  //notlar arrayinin icindeki tum notlari sirasiyla yazdir
        sayac=sayac+1;
    }
}  






//bos baradagi o anki adimin bardagina esitle   
//once dizide bulunan toplam bardak sayisini bulundugumuz adimdaki bardak sayisindan cikartarak hangi bardagi hangisiyle degistermeliyiz buna ulasiriz. Ardindan bu 2 bardagi esitle.
//biraz once buldugumuz bardagi bos bardaga esitleriz








//kullanicidan 7 tane not al sirasi ile arraayin icine at 
//notlar arrayinin icindeki tum notlari sirasiyla yazdir
//sonra bu arrayin icindeki notlari siralama olarak tam tersi olsun while kullan
