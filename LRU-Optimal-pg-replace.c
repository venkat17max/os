//FCFS OR FIFO
#include <stdio.h>

int main() {
    int n,f,i,j,k=0,flag,frames[10],pages[30],fault=0;

    printf("Enter no. of pages: ");
    scanf("%d",&n);

    printf("Enter page sequence: ");
    for(i=0;i<n;i++) scanf("%d",&pages[i]);

    printf("Enter no. of frames: ");
    scanf("%d",&f);

    for(i=0;i<f;i++) frames[i] = -1;

    for(i=0;i<n;i++) {
        flag = 0;

        for(j=0;j<f;j++)
            if(frames[j] == pages[i]) flag = 1;

        if(!flag) {
            frames[k] = pages[i];
            k = (k+1)%f;
            fault++;
        }

        for(j=0;j<f;j++) printf("%d ",frames[j]);
        printf("\n");
    }

    printf("Page Faults = %d\n",fault);
}
//LRU
#include <stdio.h>

int main() {
    int n,f,i,j,frames[10],pages[30],time[10];
    int count=0,fault=0,flag,pos,min;

    printf("Enter no. of pages: ");
    scanf("%d",&n);

    printf("Enter page sequence: ");
    for(i=0;i<n;i++) scanf("%d",&pages[i]);

    printf("Enter no. of frames: ");
    scanf("%d",&f);

    for(i=0;i<f;i++) frames[i] = -1;

    for(i=0;i<n;i++) {
        flag = 0;

        for(j=0;j<f;j++) {
            if(frames[j]==pages[i]) {
                flag=1;
                time[j]=++count;
            }
        }

        if(!flag) {
            min = 9999;
            for(j=0;j<f;j++) {
                if(frames[j]==-1) { pos=j; break; }
                if(time[j]<min) {
                    min=time[j];
                    pos=j;
                }
            }

            frames[pos]=pages[i];
            time[pos]=++count;
            fault++;
        }

        for(j=0;j<f;j++) printf("%d ",frames[j]);
        printf("\n");
    }

    printf("Page Faults = %d\n",fault);
}
//OPTIMAL
#include <stdio.h>

int main() {
    int n,f,i,j,k,frames[10],pages[30];
    int fault=0,flag,pos,far,idx;

    printf("Enter no. of pages: ");
    scanf("%d",&n);

    printf("Enter page sequence: ");
    for(i=0;i<n;i++) scanf("%d",&pages[i]);

    printf("Enter no. of frames: ");
    scanf("%d",&f);

    for(i=0;i<f;i++) frames[i]=-1;

    for(i=0;i<n;i++) {
        flag=0;

        for(j=0;j<f;j++)
            if(frames[j]==pages[i]) flag=1;

        if(!flag) {
            pos=-1; far=i+1;

            for(j=0;j<f;j++) {
                for(k=i+1;k<n;k++)
                    if(frames[j]==pages[k]) break;

                if(k==n) { pos=j; break; }

                if(k>far) {
                    far=k;
                    pos=j;
                }
            }

            if(pos==-1) pos=0;

            frames[pos]=pages[i];
            fault++;
        }

        for(j=0;j<f;j++) printf("%d ",frames[j]);
        printf("\n");
    }

    printf("Page Faults = %d\n",fault);
}