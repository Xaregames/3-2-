
#include <stdlib.h>
#include <stdio.h>






typedef  struct {
    
    int price;
    char name[20];
}product;

void quickSort(product* nums, int begin, int end)
    {
    int l = begin, r = end;
    int v = nums[l+(r-l)/2].price;
    while(l <= r)
    {
        while(nums[l].price < v) l++;
        while(nums[r].price > v) r--;
        if(l <= r)
        {
            product tmp = nums[l];
            nums[l] = nums[r];
            nums[r] = tmp;
            l++, r--;
        }
    }
    if(begin < r)
        quickSort(nums, begin, r);
    if(l < end)
        quickSort(nums, l, end);
}





int main()
{
    
    
    
    
    product *product1;
    printf("%ld\n",sizeof(product1));
    product1 = malloc(sizeof(product));
    int i = 0;
    FILE *fp = fopen("text.txt","r");
    
    
    while(fscanf(fp,"%s %d", product1[i].name, &product1[i].price) != EOF){
        printf("%s %d\n", product1[i].name, product1[i].price);
        i++;
        printf("1: %ld\n",sizeof(product1));
        product1 = realloc(product1,sizeof(product)*(i+1));
        printf("2: %ld\n",sizeof(product1));

    }
    fclose(fp);
    
    quickSort(product1,0,i-1);
    
   /* printf(" 1: \n");
    for (int k = 0; k < i; k++) {
        printf("%s Пробел %d\n", product1[k].name, product1[k].price);
    }
    printf(" 2: \n");*/
    
    
    
    FILE* fp2 =fopen("text2.txt","w");
    
    for (int k = 0; k < i; k++) {
        fprintf(fp2,"%s %d\n", product1[k].name, product1[k].price);
        //printf("%s %d\n", product1[k].name, product1[k].price);
    }
    
    fclose(fp2);
   
    return 0;
}
