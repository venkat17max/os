//PAGING
#include <stdio.h>

int main() {
    int page_size, log_addr;
    int page_no, offset, phy_addr;

    printf("Enter page size: ");
    scanf("%d", &page_size);

    printf("Enter logical address: ");
    scanf("%d", &log_addr);

    page_no = log_addr / page_size;
    offset  = log_addr % page_size;

    phy_addr = page_no * page_size + offset;

    printf("Page No: %d\n", page_no);
    printf("Offset: %d\n", offset);
    printf("Physical Address: %d\n", phy_addr);

    return 0;
}
//SEGMENTATION
#include <stdio.h>

int main() {
    int base[10], limit[10], n;
    int seg_no, offset;

    printf("Enter number of segments: ");
    scanf("%d", &n);

    printf("Enter base and limit for each segment:\n");
    for(int i=0;i<n;i++){
        printf("Segment %d: ", i);
        scanf("%d %d", &base[i], &limit[i]);
    }

    printf("Enter segment number and offset: ");
    scanf("%d %d", &seg_no, &offset);

    if(seg_no >= n){
        printf("Invalid segment\n");
        return 0;
    }

    if(offset >= limit[seg_no]){
        printf("Segmentation Fault\n");
    } else {
        int phy_addr = base[seg_no] + offset;
        printf("Physical Address: %d\n", phy_addr);
    }

    return 0;
}