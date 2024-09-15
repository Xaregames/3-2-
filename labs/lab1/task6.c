include <stdio.h>
  //int size, char *nameFile[]
int main()
{
    
    char line[1024];
    char *filename = "text6.txt";
    scanf("%s", line);
    int lineNum = 0;
    
    FILE * fp= fopen(filename, "r");
    
    
    FILE * newFile2 = fopen(line, "w");
    
    if(fp)
    
    {
       
        while( lineNum < 3 && fgets(line,1024,fp))
        {
          fputs(line, newFile2);
          lineNum++;
        }
        fclose(fp);
