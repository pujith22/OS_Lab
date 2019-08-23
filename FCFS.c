#include<stdio.h>

typedef struct Process{
int arrival_time;
int burst_time;
int turn_around_time;
int waiting_time;
int completion_time;
}process;

void fcfs(process* p,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(i==0)
        {
            p[i].completion_time = p[i].arrival_time + p[i].burst_time;
            p[i].turn_around_time = p[i].completion_time - p[i].arrival_time;
            p[i].waiting_time = p[i].turn_around_time - p[i].burst_time;
    	}
        else{
            if (p[i].arrival_time<p[i-1].completion_time)
            {

                p[i].completion_time = p[i-1].completion_time + p[i].burst_time;
                p[i].turn_around_time = p[i].completion_time - p[i].arrival_time;
                p[i].waiting_time = p[i].turn_around_time - p[i].burst_time;
            }
            else
            {
               p[i].completion_time =  p[i].arrival_time + p[i].burst_time ;
               p[i].turn_around_time = p[i].completion_time - p[i].arrival_time;
            	p[i].waiting_time = p[i].turn_around_time - p[i].burst_time;
            }

        }
    }
}

void printProcess(process *p,int n)
{
    printf("Process No.\t Arrival_Time\tBurst_Time\tTurn_Around_Time\tWaiting_Time\tCompletion_Time\n\n");
    int i;
    for(i=0;i<n;i++)
    {
        printf("\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,p[i].arrival_time,p[i].burst_time,p[i].turn_around_time,p[i].waiting_time,p[i].completion_time);
    }
}
void main()
{
    process p[100];
    int i;
    for(i=0;i<3;i++)
    {
        printf("\nEnter Arrival time of Process %d: ",i+1);
        scanf("%d",&p[i].arrival_time);
        printf("\nEnter Burst_time of Process %d: ",i+1);
        scanf("%d",&p[i].burst_time);
    }
    fcfs(p,3);
    printProcess(p,3);
}
