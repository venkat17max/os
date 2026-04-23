//FCFS
#include <stdio.h>

int main() {
    int n,i;
    int at[10], bt[10], ct[10], wt[10], tat[10];

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("AT and BT of P%d: ",i+1);
        scanf("%d %d",&at[i],&bt[i]);
    }

    ct[0]=at[0]+bt[0];

    for(i=1;i<n;i++){
        if(ct[i-1] < at[i])
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i-1] + bt[i];
    }

    for(i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }

    printf("\nP\tAT\tBT\tCT\tWT\tTAT\n");
    for(i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],wt[i],tat[i]);
}
//SJF
#include <stdio.h>

int main() {
    int n,i,j,idx,time=0;
    int at[10], bt[10], ct[10], wt[10], tat[10], done[10]={0};

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("AT and BT of P%d: ",i+1);
        scanf("%d %d",&at[i],&bt[i]);
    }

    for(i=0;i<n;i++){
        int min=9999;
        idx=-1;

        for(j=0;j<n;j++){
            if(at[j]<=time && !done[j] && bt[j]<min){
                min=bt[j];
                idx=j;
            }
        }

        if(idx==-1){ time++; i--; continue; }

        time+=bt[idx];
        ct[idx]=time;
        done[idx]=1;
    }

    for(i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }

    printf("\nP\tAT\tBT\tCT\tWT\tTAT\n");
    for(i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],wt[i],tat[i]);
}
//Priority
#include <stdio.h>

int main() {
    int n,i,j,time=0,idx;
    int at[10], bt[10], pr[10], ct[10], wt[10], tat[10], done[10]={0};

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("AT BT Priority of P%d: ",i+1);
        scanf("%d %d %d",&at[i],&bt[i],&pr[i]);
    }

    for(i=0;i<n;i++){
        int min=9999;
        idx=-1;

        for(j=0;j<n;j++){
            if(at[j]<=time && !done[j] && pr[j]<min){
                min=pr[j];
                idx=j;
            }
        }

        if(idx==-1){ time++; i--; continue; }

        time+=bt[idx];
        ct[idx]=time;
        done[idx]=1;
    }

    for(i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }

    printf("\nP\tAT\tBT\tPR\tCT\tWT\tTAT\n");
    for(i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],pr[i],ct[i],wt[i],tat[i]);
}
//Round Robin
#include <stdio.h>

int main() {
    int n,i,time=0,remain;
    int at[10], bt[10], rt[10], ct[10], wt[10], tat[10];
    int tq, done[10]={0};

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("AT and BT of P%d: ",i+1);
        scanf("%d %d",&at[i],&bt[i]);
        rt[i]=bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d",&tq);

    remain=n;

    while(remain){
        for(i=0;i<n;i++){
            if(at[i]<=time && rt[i]>0){
                if(rt[i]<=tq){
                    time+=rt[i];
                    ct[i]=time;
                    rt[i]=0;
                    remain--;
                } else {
                    time+=tq;
                    rt[i]-=tq;
                }
            }
        }
        time++; // handles idle CPU
    }

    for(i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
    }

    printf("\nP\tAT\tBT\tCT\tWT\tTAT\n");
    for(i=0;i<n;i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],wt[i],tat[i]);
}