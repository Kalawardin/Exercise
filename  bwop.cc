/*
compounds    increment and decrement
+ =           ++x; x++; --x; x--;
- =            
* =          enum day{MON,TUE,WED,THU,FRI};
/ =          typedef int score; score s1=100;

Bitwise operators        
& =  int a=5; int b=3; int c=a&b; // c is 1 (0001 in binary)                    
% =  int a=5; int b=3; int c=a%b; // c is 2 (remainder of 5/3)         
| =  int a=5; int b=3; int c=a|b; // c is 7 (0111 in binary)         
: =  int arr[5] = {1,2,3,4,5}; int *p = arr; // p points to the first element of arr
<< = int a=3; int b=a<<1; // b is 6 (0011 << 1 = 0110)
>> = int a=8; int b=a>>1; // b is 4 (1000 >> 1 = 0100)   
~ = FLIP THE BITS
^ = XOR


A B  A&B  A|B   A^B  ~A
0 0   0    0     0    1
0 1   0    1     1    1
1 0   0    1     1    0   
1 1   1    1     0    0

increment and decrement:      
++x; x++; --x; x--;    

*/
#include <iostream>
using namespace std;

int main()
{
  int x = 11, y = 7, z;
  z = x|y;
  cout << z << endl;
  return 0;  
}