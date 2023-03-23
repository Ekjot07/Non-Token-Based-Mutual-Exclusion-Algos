#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void process1();
void process2();
int process[10],priority[10],no_of_process,i,j,count=0,ran_pr,temp,max_lmt,min_lmt;

int main()
{
    printf("Enter the no. of processses ");
    scanf("%d",&no_of_process);
    for(i=0; i<no_of_process; i++)
        process[i]=i+1;
      do
       {
           ran_pr=rand()%no_of_process;
       }
       while(ran_pr!=0);
    ran_pr=3;
    printf("Control process is P%d \n",ran_pr);
    printf("Enter the priority of processes \n");
    for(i=0; i<no_of_process; i++)
    {
        printf("Priority of process P%d : ",process[i]);
        scanf("%d",&priority[i]);
    }
    printf("\n");
    for(i=0; i<no_of_process-1; i++)
    {
        for(j=i+1; j<no_of_process; j++)
        {
            if(priority[i]>priority[j])
            {
                temp=priority[i];
                priority[i]=priority[j];
                priority[j]=temp;

                temp=process[i];
                process[i]=process[j];
                process[j]=temp;
            }
        }
    }
    for(i=0; i<no_of_process-1; i++)
    {
        if(process[i]<ran_pr)
        {
            max_lmt=ran_pr;
            process1();
        }
        else
        {
            min_lmt=ran_pr+1;
            process2();
        }
    }

    getch();
}

void process1()
{
    for(j=0; j<ran_pr; j++)
    {
        if(i!=j)
            printf("Process P%d is sending request to P%d \n",process[i],process[j]);
        else
            continue;
    }
    printf("\n");
    for(j=0; j<ran_pr; j++)
    {
        if(i!=j)
        {
            printf("Process P%d is acknowledging P%d \n",process[j],process[i]);
            count++;
        }
        else
            continue;
    }
    printf("\n");
    if(count==(ran_pr-1))
    {
        printf("Process P%d is entering CS \n",process[i]);
    }
    printf("\n");
    for(j=0; j<ran_pr; j++)
    {
        if(i!=j)
            printf("Process P%d is sending reply to P%d \n",process[i],process[j]);
        else
            continue;
    }
}

void process2()
{
    for(j=ran_pr+1; j<no_of_process; j++)
    {
        if(i!=j)
            printf("Process P%d is sending request to P%d \n",process[i],process[j]);
        else
            continue;
    }
    printf("\n");
    for(j=ran_pr+1; j<no_of_process; j++)
    {
        if(i!=j)
        {
            printf("Process P%d is acknowledging P%d \n",process[j],process[i]);
            count++;
        }
        else
            continue;
    }
    printf("\n");

    if(count==(no_of_process-ran_pr-1))
    {
        printf("Process P%d is entering CS \n",process[i]);
    }
    printf("\n");
    for(j=ran_pr+1; j<no_of_process; j++)
    {
        if(i!=j)
            printf("Process P%d is sending reply to P%d \n",process[i],process[j]);
        else
            continue;
    }
}