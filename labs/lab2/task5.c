


#include <stdlib.h>
#include <stdio.h>






typedef  struct {
    
    int price;
    char name[20];
}product;

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
    
    

    
   
    return 0;
}
