#include <stdio.h>
#include <dirent.h>
#include<sys/stat.h>
#include<time.h>
void getFilesize(const char* filename) {
    struct stat st;
    if(stat(filename, &st) != 0) {
        return ;
    }
    printf("%ld B\t",st.st_size);  
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
   
  struct dirent *entry;
 
  DIR *dp;

  dp = opendir(path);
  if (dp == NULL) 
  {
    printf("not a directory");
    return -1;
  }

  while((entry = readdir(dp)))

  {  printf("%s\t",entry->d_name);
     getFilesize(entry->d_name);
   } 

  closedir(dp);
  return 0;
}

int main() {

  listdir(".");
  return 0;
}
