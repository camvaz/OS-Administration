#include "/home/vic/Documents/apue.3e/include/apue.h"
#include "/home/vic/Documents/apue.3e/lib/error.c"
#define BUFFSIZE 4096
int
main(void) {
	int n;
       	char buf[BUFFSIZE];
	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
	       	if (write(STDOUT_FILENO, buf, n) != n)
		       	err_sys("write error");
	if (n < 0)
	     err_sys("read error");
        exit(0);
} 
