#include "types.h"
#include "user.h"
#include "param.h"

#define assert(x) if (x) { /* pass */ } else { \
   printf(1, "assert failed %s %s %d\n", #x , __FILE__, __LINE__); \
   exit(); \
   }


void readfile(char *file, int howmany) {
  int i;
  // assumes file opens successfully...
  int fd = open(file, 0);
  char buf;
  // assumes file is big enough...
  for (i = 0; i < howmany; i++)
      (void) read(fd, &buf, 1);
  close(fd);
}

int
main(int argc, char *argv[])
{
  int rc1 = getreadcount();
  printf(1, "Read count  %d\n", rc1);
  readfile("README", 5);
  int rc2 = getreadcount();
  printf(1, "Read count  %d\n", rc2);
  assert((rc2 - rc1) == 5);
  printf(1, "TEST PASSED\n");
  exit();
}
