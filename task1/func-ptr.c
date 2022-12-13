#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include "process.h"
#include "util.h"
#define DEBUG 1

typedef int (*Comparer) (const void *a, const void *b);

int comparer(const void *this, const void *that)
{
  Process *p_1 = (Process*)this;
	Process *p_2 = (Process*)that;
	if (p_1->priority > p_2->priority) {return -1;}
	else if(p_1->priority < p_2->priority) {return 1;}
  else {
	  if (p_1->arrival_time > p_2->arrival_time) {return 1;}
		else{return -1;}
	}
	return 0;
}


int main(int argc, char *argv[])
{
  if (argc < 2) {
    fprintf(stderr, "Usage: ./func-ptr <input-file-path>\n");
    fflush(stdout);
    return 1;
  }

  FILE *input_file = fopen(argv[1], "r");
  if (!input_file) {
    fprintf(stderr, "Error: Invalid filepath\n");
    fflush(stdout);
    return 1;
  }

  Process *processes = parse_file(input_file);



  Comparer compare_processes = &comparer;


  qsort(processes, P_SIZE, sizeof(Process), compare_processes);

  fflush(stdout);
	fflush(stderr);

  free(processes);
  fclose(input_file);
  return 0;
}
