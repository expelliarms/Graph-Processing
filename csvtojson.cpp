#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

const char* getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ",");
            tok && *tok;
            tok = strtok(NULL, ",\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}

int main()
{
  FILE* stream = fopen("WeightedDataset.csv", "r");
  char line[1024];
  while (fgets(line, 1024, stream))
  {
    printf("Outer: %s",line );
    sleep(3);
    char* tmp = strdup(line);
    char* tmp1 = strdup(line);
    double weight = atof(getfield(tmp1, 3));
    int target = atoi(getfield(tmp, 2));
    int source = atoi(getfield(tmp, 1));
    printf("Outer: %d %d %lf\n", source, target, weight);
    sprintf(wrline, "[%d,0,[%d,%d]]",source,target,(int)(weight*100));
    FILE* streami = fopen("WeightedDataset.csv", "r");
    char linei[1024];
    while (fgets(linei, 1024, streami))
    {
      printf("Inner: %s",linei );
      sleep(3);
      char* tmpi = strdup(linei);
      char* tmp1i = strdup(linei);
      double weighti = atof(getfield(tmp1i, 3));
      int targeti = atoi(getfield(tmpi, 2));
      int sourcei = atoi(getfield(tmpi, 1));
      printf("Inner: %d %d %lf\n", sourcei, targeti, weighti);
    }
    char wrline[1024];

    printf("Outer: %s\n",wrline);
    free(tmp);
    free(tmp1);
  }
}
