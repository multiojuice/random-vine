#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXCHAR 1000

int main()
{
  FILE *fp;
  char str[MAXCHAR];
  int num_vines;
  char* filename = "./info.txt";
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
  printf("%d", random_num);

  return 0;
}
