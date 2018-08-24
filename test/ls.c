#include "arrow.h"
#include <stdio.h>
#include <dirent.h>
#include<sys/stat.h>
#include<time.h>
void lscommand(const char* filename) {
    struct stat st;
    if(stat(filename, &st) != 0) {
        return ;
    }
    
    printf("%s\t",filename);
    printf("%ldB\t",st.st_size);  
    printf( (S_ISDIR(st.st_mode)) ? "d" : "-");
    printf( (st.st_mode & S_IRUSR) ? "r" : "-");
    printf( (st.st_mode & S_IWUSR) ? "w" : "-");
    printf( (st.st_mode & S_IXUSR) ? "x" : "-");
    printf( (st.st_mode & S_IRGRP) ? "r" : "-");
    printf( (st.st_mode & S_IWGRP) ? "w" : "-");
    printf( (st.st_mode & S_IXGRP) ? "x" : "-");
    printf( (st.st_mode & S_IROTH) ? "r" : "-");
    printf( (st.st_mode & S_IWOTH) ? "w" : "-");
    printf( (st.st_mode & S_IXOTH) ? "x" : "-");
    printf("\t%s",ctime(&st.st_mtime));

 
   
}
int listdir(const char *path) 
{
  int count=1;  
  struct dirent *entry;
 
  DIR *dp;

  dp = opendir(path);
  if (dp == NULL) 
  {
    printf("not a directory");
    return -1;
  }

  while((entry = readdir(dp)))

  {  
 //    printf("%d ",count);
     lscommand(entry->d_name);
     //count++;
   } 

  closedir(dp);
  return 0;
}

int main() {
  
  listdir(".");
  getch();
  cursor();

  return 0;
}
