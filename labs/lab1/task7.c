#include <stdio.h>
int main()
{
    
    char line[1024];
    char *filename = "text7.txt";
    int lineNum = 0;
  
    
    FILE * fpWrite = fopen(filename, "a");
    FILE * fpRead = fopen(filename,"r");
    
    
    
    if(fpWrite && fpRead)
    
    {
          printf("Текст файл до работы программы:\n\n");
          while(fgets(line,1024,fpRead) != NULL)
        {
          printf("%s", line);
          lineNum++;
        }
        
        fclose(fpRead);
        printf("\nВведите строку: ");
        fgets(line,1024,stdin);
        
        fputs(line,fpWrite);
        fclose(fpWrite);
        FILE * fpRead = fopen(filename,"r");
        printf("\nТекст файл после работы программы:\n\n");
         while(fgets(line,1024,fpRead) != NULL)
        {
          printf("%s", line);
          lineNum++;
        }
        
        
        fclose(fpRead);
        return 0;
        
    }
    
}
