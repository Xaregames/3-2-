#include <stdio.h>
int main()
{
    
    char lineText[1024][1024];
    char lineAdd[1024];
    char *filename = "text7.txt";
    int lineNum = 0;
  
    
    FILE * fpWrite = fopen(filename, "a");
    FILE * fpRead = fopen(filename,"r");
    
    
    
    if(fpWrite && fpRead)
    
    {
          printf("Текст файл до работы программы:\n\n");
          while(fgets(lineText[lineNum],1024,fpRead) != NULL)
        {
          printf("%s", lineText[lineNum]);
          lineNum++;
        }
        
        fclose(fpRead);
        FILE * fpWrite2 = fopen(filename,"w");
    
        printf("\nВведите строку: ");
        fgets(lineAdd,1024,stdin);
        
        fputs(lineAdd,fpWrite2);
        for (int i = 0; i < lineNum; i++) {
            /* code */
            fputs(lineText[i],fpWrite2);
        }
        
        
        fclose(fpWrite);
        fclose(fpWrite2);
        
        FILE * fpRead = fopen(filename,"r");
        printf("\nТекст файл после работы программы:\n\n");
        
         while(fgets(lineText,1024,fpRead) != NULL)
        {
          printf("%s", lineText);
          lineNum++;
        }
        
        
        fclose(fpRead);
        return 0;
        
    }
    
}
