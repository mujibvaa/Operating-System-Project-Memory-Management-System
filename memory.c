#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 25
int main(){
	int ch;
	printf("Memory Managemnet System:\n");
	printf("1.First Fit");
	printf("\n2.Best Fit");
	printf("\n3.Worst Fit");
	printf("\n4.Exit");
	printf("\nEnter your choice here:");
	scanf("%d",&ch);
	switch(ch){
		case 1:
			firstfit();
			break;
		case 2:
			bestfit();
			break;
		case 3:
			worstfit();
			break;
		case 4:
			exit(0);
			break;
		default:
			printf("Invalid Choice");
	}


}
firstfit(){

	int frag[max],b[max],f[max],i,j,nb,nf,temp;
static int bf[max],ff[max];
printf("\n\tMemory Management Scheme - First Fit");
printf("\nEnter the number of blocks:");
scanf("%d",&nb);
printf("Enter the number of files:");
scanf("%d",&nf);
printf("\nEnter the size of the blocks:-\n");
for(i=1;i<=nb;i++)
{
printf("Block %d:",i);
scanf("%d",&b[i]);
}
printf("Enter the size of the files :-\n");
for(i=1;i<=nf;i++)
{
printf("File %d:",i);
scanf("%d",&f[i]);
}
for(i=1;i<=nf;i++)
{
 for(j=1;j<=nb;j++)
 {
if(bf[j]!=1)
 {
temp=b[j]-f[i];
if(temp>=0)
 {
ff[i]=j;
break;
 }
 }
 }
frag[i]=temp;
bf[ff[i]]=1;
}
printf("\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragement");
for(i=1;i<=nf;i++)
printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,f[i],ff[i],b[ff[i]],frag[i]);


}
bestfit(){
	int frag[max],b[max],f[max],i,j,nb,nf,temp,lowest=10000;
static int bf[max],ff[max];
printf("\nEnter the number of blocks:");
scanf("%d",&nb);
printf("Enter the number of files:");
scanf("%d",&nf);
//fflush(stdin);
printf("\nEnter the size of the blocks:-\n");

for(i=1;i<=nb;i++){
printf("\nBlock %d:",i);
scanf("%d",&b[i]);}
printf("Enter the size of the files :-\n");
for(i=1;i<=nf;i++)
{
printf("File %d:",i);
scanf("%d",&f[i]);
}
for(i=1;i<=nf;i++)
{
 for(j=1;j<=nb;j++)
{
if(bf[j]!=1)
{
temp=b[j]-f[i];
if(temp>=0)
if(lowest>temp)
{
ff[i]=j;
lowest=temp;
 }
 }
 }
 frag[i]=lowest;
 bf[ff[i]]=1;
 lowest=10000;
}
printf("\nFile No\tFile Size \tBlock No\tBlock Size\tFragment");
for(i=1;i<=nf && ff[i]!=0;i++)
printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,f[i],ff[i],b[ff[i]],frag[i]);
}
worstfit(){
    int frag[max],b[max],f[max],i,j,nb,nf,temp,highest=0;
static int bf[max],ff[max];
printf("\n\tMemory Management Scheme - Worst Fit");
printf("\nEnter the number of blocks:");
scanf("%d",&nb);
printf("Enter the number of files:");
scanf("%d",&nf);
printf("\nEnter the size of the blocks:-\n");
for(i=1;i<=nb;i++)
{
printf("Block %d:",i);
scanf("%d",&b[i]);
}
printf("Enter the size of the files :-\n");
for(i=1;i<=nf;i++)
{
printf("File %d:",i);
scanf("%d",&f[i]);
}
for(i=1;i<=nf;i++)
{
for(j=1;j<=nb;j++)
 {
if(bf[j]!=1) //if bf[j] is not allocated
 {
temp=b[j]-f[i];
 if(temp>=0)
if(highest<temp)
 {
 ff[i]=j;
highest=temp;
 }
 }
 }
 frag[i]=highest;
 bf[ff[i]]=1;
 highest=0;
}
printf("\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragement");
for(i=1;i<=nf;i++)
printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,f[i],ff[i],b[ff[i]],frag[i]);
}
