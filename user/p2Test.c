#include "syscall.h"
#include "types.h"
#include "user.h"

int main(int argc, char *argv[]){
	int count = getreadcount();
	printf(1, "\n[Read Count]: %d\n", count);
	exit();;
}
