#include <stdio.h>
#include <stdlib.h>
int binary_search(int * list,int len,int target){
    int low = 0;
    int hight = len-1;
    int middle;
    while(low <= hight){
        middle = (low + hight)/2;
        if(list[middle] = target)
        {
            printf("已找到该值，数组下标为:%d\n",middle);
            return list[middle];
        }
        else if(list[middle] > target)
        {
            hight = middle -1;
        }
        else if(list[middle] < target)
        {
            low = middle + 1;
        }
    }
    printf("未找到该值");
    return -1;
}
 
int main()
{
 
    int a[] = {2,4,5,8,9,44};
    int b = binary_search(a,sizeof(a)/4,5);
    printf("b=%d\n",b);
    printf("Hello world!\n");
    return 0;
}
