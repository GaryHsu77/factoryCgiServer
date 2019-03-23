#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define FACTORY_MSG_LOG "/var/www/data/factorylog.txt"

int main(int argc,char *argv[])
{
//	FILE *fd = fopen(FACTORY_MSG_LOG,"a");
	FILE *fd = stdout;

	fprintf(fd,"<H3>Tool 1 start execution...</H3>\n");
	sleep(1);
	fprintf(fd,"<H3>Tool 1 step1 start...</H3>\n");
	fprintf(fd,"<H3>Tool 1 step2 start...</H3>\n");
	fprintf(fd,"<H3>Tool 1 step3 start...</H3>\n");
	sleep(1);
	fprintf(fd,"<H3>Tool 1 test passed...</H3>\n");

	return 1;
}

