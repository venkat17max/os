#include <stdio.h>

int main() {
    int n, m, i, j, k;
    int alloc[10][10], max[10][10], need[10][10];
    int avail[10], finish[10] = {0}, safe[10];

    printf("Enter processes and resources: ");
    scanf("%d %d", &n, &m);

    printf("Enter Allocation matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&alloc[i][j]);

    printf("Enter Max matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&max[i][j]);

    printf("Enter Available resources:\n");
    for(i=0;i<m;i++)
        scanf("%d",&avail[i]);

    // Need = Max - Allocation
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            need[i][j] = max[i][j] - alloc[i][j];

    int count = 0;
    while(count < n) {
        for(i=0;i<n;i++) {
            if(!finish[i]) {
                int flag = 1;
                for(j=0;j<m;j++) {
                    if(need[i][j] > avail[j]) {
                        flag = 0;
                        break;
                    }
                }
                if(flag) {
                    for(k=0;k<m;k++)
                        avail[k] += alloc[i][k];
                    safe[count++] = i;
                    finish[i] = 1;
                }
            }
        }
    }

    if(count == n) {
        printf("Safe sequence: ");
        for(i=0;i<n;i++)
            printf("P%d ", safe[i]);
    } else {
        printf("Deadlock (Unsafe state)");
    }

    return 0;
}
