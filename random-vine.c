#include <stdio.h>
#include <stdlib.h>
#define MAXCHAR 1000

int main()
{
  FILE *fp;
  char str[MAXCHAR];
  int num_vines;
  char* filename = "./info.txt";

  fp = fopen(filename, "r");
  if (fp == NULL){
      printf("Could not open file %s",filename);
      return 1;
  }

  while (fgets(str, MAXCHAR, fp) != NULL)
      printf("%s", str);
      num_vines = (int) strtol(str, (char **)NULL, 10);
      printf("%d", num_vines == 10);

  fclose(fp);
  return 0;
}
