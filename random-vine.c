#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXCHAR 1000

int main()
{
  FILE *fp;
  FILE *vines;
  char str[MAXCHAR];
  char vine_str[MAXCHAR];
  int num_vines;
  char* filename = "./info.txt";
  char* vines_file = "./vines.txt";
  int random_num;

  // Get the amount of vines we have
  fp = fopen(filename, "r");
  if (fp == NULL){
      printf("Could not open file %s",filename);
      return 1;
  }

  while (fgets(str, MAXCHAR, fp) != NULL)
      num_vines = (int) strtol(str, (char **)NULL, 10);

  fclose(fp);

  // Decide which vine number to get
  srand(time(NULL));
  random_num = (rand() % num_vines) + 1;

  vines = fopen(vines_file, "r");
  if (fp == NULL){
      printf("Could not open file %s",vines_file);
      return 1;
  }

  char ch;
  int count = 0;

  while((ch = fgetc(vines)) != EOF)
          if(ch == '`')
          {
            count++;
            if(count >= random_num){
              break;  
            }
          }
  int index = 0;

  while ((ch = fgetc(vines)) != '`')
  {
    vine_str[index] = ch;
    index++;
  }

  printf("%s", vine_str);
  fclose(vines);
  

  return 0;
}
