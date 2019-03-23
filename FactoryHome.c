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
	"<body bgcolor=" FACTORY_HOME_BGCOLOR ">",
	"<h1>",
	"Linux Gateway Factory Test",
	"</h1>",
	"<form action=\"http://" DEFAULT_MY_HOST_ADDR "/" CGI_BIN "/" FACTORY_PSW_NAME "\">",
	"<div><label><H3>Password for enabling Factory test: <input name=\"PSW\" size=\"20\"></H3></label></div>",
	"<div><input type=\"submit\" value=\"Start Factory-Test\"></div>",
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

int main(int argc,char *argv[])
{
	CGI_Init();

	CGI_PrintScript(HTML_START);

	CGI_PrintScript(HTML_HEADER_START);
	CGI_PrintScript(HTML_HEADER_END);

	CGI_PrintScript(HTML_BODY_START);
	CGI_PrintScript(HTML_BODY_END);

	CGI_PrintScript(HTML_END);

	return 0;
}

