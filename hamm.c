#include<stdio.h>
int data[10];
int dataatrec[10],c,c1,c2,c3,i,n;
int sender()
{
data[6]=data[0]^data[2]^data[4];
data[5]=data[0]^data[1]^data[4];
data[3]=data[0]^data[1]^data[2];
if(n==1)
{
printf("\nEncoded data is\n");
for(i=0;i<7;i++)
 printf("%d",data[i]);
}
return 0;
}
int receiver()
{
printf("\n\nEnter received data bits\n");
for(i=0;i<7;i++){
 scanf("%d",&dataatrec[i]);
}
c1=dataatrec[6]^dataatrec[4]^dataatrec[2]^dataatrec[0];
c2=dataatrec[5]^dataatrec[4]^dataatrec[1]^dataatrec[0];
c3=dataatrec[3]^dataatrec[2]^dataatrec[1]^dataatrec[0];
c=c3*4+c2*2+c1 ;
if(c==0) {
 printf("\nNo error while transmission of data\n");
}
else {
 printf("\nError on position %d",c);
 printf("\nData sent : ");
 for(i=0;i<7;i++){
 printf("%d",data[i]);
 }
 printf("\nData received : ");
 for(i=0;i<7;i++){
 printf("%d",dataatrec[i]);
 }
 printf("\nCorrect message is\n");
 if(dataatrec[7-c]==0)
 dataatrec[7-c]=1;
 else
 dataatrec[7-c]=0;
 for (i=0;i<7;i++) {
 printf("%d",dataatrec[i]);
 }
 }
 return 0;
}
int main()
{
printf("Enter 4 bits of original data\n");
scanf("%d",&data[0]);
scanf("%d",&data[1]);
scanf("%d",&data[2]);
scanf("%d",&data[4]);
while(1)
{
printf("\nenter-\n 1 for sender side processing\n 2 for receiver side processing\n 3 for exit\n");
scanf("%d",&n);
switch(n)
{
case 1:
    sender();
    break;
case 2:
    sender();
    receiver();
    break;
case 3:
    exit(0);
default:
    printf("Invaid input");
}
}
}
