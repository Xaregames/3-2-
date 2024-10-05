
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
    
    product1 = malloc(sizeof(product1));
    char line[20];
    int i = 0;
    FILE *fp = fopen("text.txt","r");
    
    
    while(fscanf(fp,"%s %d", product1[i].name, &product1[i].price) != EOF){
        printf("%s %d\n", product1[i].name, product1[i].price);
        i++;
        product1 = realloc(product1,sizeof(product1)+sizeof(product));
        
        
        
    }
    fclose(fp);
    
    for (int k = 0; k < i; k++) {
        printf("%s Пробел %d\n", product1[k].name, product1[k].price);
    }
    
    quickSort(product1,0,i-1);
    
    
    
    
    FILE* fp2 =fopen("text2.txt","w");
    
    for (int k = 0; k < i; k++) {
        fprintf(fp2,"%s %d\n", product1[k].name, product1[k].price);
        printf("%s %d\n", product1[k].name, product1[k].price);
    }

   
    return 0;
}
