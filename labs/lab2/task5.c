#include <stdlib.h>
#include <stdio.h>






struct product{
    
    int price;
    char name[20];
};

int main()
{
    
    
    
    
    struct product *product;
    
    product = malloc
    char line[20];
    int i = 0;
    FILE *fp = fopen("text.txt","r");
    
    
    while(fscanf(fp,"%s %d", product[i].name, &product[i].price) != EOF){
        printf("%s %d\n", product[i].name, product[i].price);
        i++;
        
    }
    
   
    return 0;
}
