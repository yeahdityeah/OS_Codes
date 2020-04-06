#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
int queue[100],t[100],head,seek=0,n,i,j,temp;
float avg;
// clrscr();
printf("*** SSTF Disk Scheduling Algorithm ***\n");
printf("Enter the size of Queue\t");
scanf("%d",&n);
printf("Enter the Queue\t");
for(i=0;i<n;i++)
{
scanf("%d",&queue[i]);
}
printf("Enter the initial head position\t");
scanf("%d",&head);
for(i=1;i<n;i++)
{
t[i]=head-queue[i];
if (t[i]<0)
t[i]=-t[i];
}
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(t[i]>t[j])
{
temp=t[i];
t[i]=t[j];
t[j]=temp;
temp=queue[i];
queue[i]=queue[j];
queue[j]=temp;
}
}
}
for(i=1;i<n-1;i++)
{
seek=seek+abs(head-queue[i]);
head=queue[i];
}
printf("\nTotal Seek Time is%d\t",seek);
avg=seek/(float)n;
printf("\nAverage Seek Time is %f\t",avg);
return 0;
}
