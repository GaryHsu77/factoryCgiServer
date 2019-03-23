#include "FactoryCGI.h"

static char * HTML_START [] = 
{
	"Content-Type: text/html",
	"<html>",
	NULL,
};

static char * HTML_HEADER_START [] = 
{
	"<head>",
	"<title>Linux Gateway Factory Test Page!!</title>",
	NULL,
};

static char * HTML_HEADER_END [] = 
{
	"</head>",
	NULL,
};

static char * HTML_BODY_START [] = 
{
	"<body bgcolor=" FACTORY_PROCESS_BGCOLOR ">",
	"<h1>",
	"Linux Gateway Factory Test start!!",
	"</h1>",
	NULL,
};

static char * HTML_BODY_END [] = 
{
	"</body>",
	NULL,
};

static char * HTML_END [] = 
{
	"</html>",
	NULL,
};

static char * JavaScript_FactoryTestProcess [] = 
{
	"<script language=\"JavaScript\">",
	"<!--",
	"function GoProcess(){",
	"   window.location.reload();",
	"}",
	"//-->",
	"</script>",
	NULL,
};

static char * JavaScript_Trigger [] = 
{
	"<script>",
	"setInterval(function(){ GoProcess() },1000);",
	"</script>",
	NULL,
};

static int get_file_size(FILE *fd)
{
	long curpos, length;
	curpos = ftell(fd);
	fseek(fd,curpos,SEEK_END);
	length = ftell(fd);
	fseek(fd,curpos,SEEK_SET);
	return (int)length;
}
static char * get_factorymsglog()
{
	int size;
	char *buf;
	FILE *fd = fopen(FACTORY_MSG_LOG,"r");
	if(fd == NULL) return NULL;

	size = get_file_size(fd);
	buf = malloc(size+1);
	fread(buf,1,size,fd);
	buf[size]=0;
	fclose(fd);
	return buf;
}

int main(int argc,char *argv[])
{
	char *factorymsg;

	CGI_Init();

	CGI_PrintScript(HTML_START);

	CGI_PrintScript(HTML_HEADER_START);
	CGI_PrintScript(JavaScript_FactoryTestProcess);
	CGI_PrintScript(HTML_HEADER_END);

	CGI_PrintScript(HTML_BODY_START);

	factorymsg = get_factorymsglog();
	if(factorymsg == NULL){
		FILE *fd = fopen(FACTORY_MSG_LOG,"w");
		fclose(fd);
		system("/bin/bash -c " FACTORY_SCRIPT " &");
	}else{
		printf("%s\n\n",factorymsg);
	}

	CGI_PrintScript(JavaScript_Trigger);

	CGI_PrintScript(HTML_BODY_END);

	CGI_PrintScript(HTML_END);

	return 0;
}

