#include <stdio.h>
  
int main(void)
{
    
    char c;
   
    char * filename = "tast5.txt";
 
    FILE * fp= fopen(filename, "r");
    if(fp)
    {
       
        while((c=getc(fp))!= EOF)
        {
            printf("%c", c);
        }
        fclose(fp);
    }
}
