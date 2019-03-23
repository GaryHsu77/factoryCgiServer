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
	"<body bgcolor=" FACTORY_PSW_BGCOLOR ">",
	NULL,
};

static char * HTML_PASSWORD_ERROR_MSG [] = 
{
	"<h1>",
	"<font color=\"red\">Facotry Test Password Error!!</font>",
	"</h1>",
	"<form action=\"http://" DEFAULT_MY_HOST_ADDR "/" CGI_BIN "/" FACTORY_CGI_NAME "\">",
	"<div><input type=\"submit\" value=\"Go back to Factory Password\"></div>",
	"</form>",
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
	"function TriggerProcess(){",
	"   window.location.replace(\"http://" DEFAULT_MY_HOST_ADDR "/" CGI_BIN "/" FACTORY_PROCESS_NAME "\");",
	"}",
	"//-->",
	"</script>",
	NULL,
};

static char * JavaScript_Trigger [] = 
{
	"<script>",
	"setInterval(function(){ TriggerProcess() },1000);",
	"</script>",
	NULL,
};

static void DeleteFactoryMsgLog()
{
	system("rm -f " FACTORY_MSG_LOG);
}
static bool CheckPSW(char *query_str)
{
	if(query_str == NULL)
		return FALSE;
	if(strlen(query_str) <= 4)
		return FALSE;
	if(memcmp(query_str,"PSW=",4) != 0)
		return FALSE;
	if(strcmp(&(query_str[4]),FACTORY_PSW_CODE) != 0)
		return FALSE;
	return TRUE;
}

int main(int argc,char *argv[])
{
	CGI_Init();

	CGI_PrintScript(HTML_START);

	if(CheckPSW((char *)getenv("QUERY_STRING"))){
		DeleteFactoryMsgLog();

		CGI_PrintScript(HTML_HEADER_START);
		CGI_PrintScript(JavaScript_FactoryTestProcess);
		CGI_PrintScript(HTML_HEADER_END);

		CGI_PrintScript(HTML_BODY_START);

		printf("<h1>\n\n");
		printf("Linux Gateway Factory Test start!!\n\n");
		printf("</h1>\n\n");

		CGI_PrintScript(JavaScript_Trigger);

		CGI_PrintScript(HTML_BODY_END);
	}else{
		CGI_PrintScript(HTML_HEADER_START);
		CGI_PrintScript(HTML_HEADER_END);
		CGI_PrintScript(HTML_BODY_START);

		CGI_PrintScript(HTML_PASSWORD_ERROR_MSG);

		CGI_PrintScript(HTML_BODY_END);
	}

	CGI_PrintScript(HTML_END);

	return 0;
}

