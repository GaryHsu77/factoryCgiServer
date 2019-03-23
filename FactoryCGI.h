#ifndef _FACTORY_CGI_H_
#define _FACTORY_CGI_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef unsigned char bool;
#define FALSE 0
#define TRUE 1

#define FACTORY_MSG_LOG "/var/www/data/factorylog.txt"
#define FACTORY_SCRIPT "/var/www/data/FactoryProcess.sh"

#define DEFAULT_MY_HOST_ADDR "192.168.0.1"

#define CGI_BIN "cgi-bin"

#define FACTORY_CGI_NAME "FactoryHome.cgi"
#define FACTORY_HOME_BGCOLOR "EEFFFF"

#define FACTORY_PSW_NAME "FactoryPSW.cgi"
#define FACTORY_PSW_BGCOLOR "99FFFF"
#define FACTORY_PSW_CODE "1234567"

#define FACTORY_PROCESS_NAME "FactoryProcess.cgi"
#define FACTORY_PROCESS_BGCOLOR "EEFF99"


static char HTTP_HOST_ADDR[100] = {'\0'};

static void CGI_Init()
{
	char *host_addr = (char *)getenv("HTTP_HOST");
	if(host_addr != NULL){
		strcpy(HTTP_HOST_ADDR,host_addr);
	}
}

static void CGI_PrintScript(char * Script[])
{
	int i, http_host_addr_len = strlen(HTTP_HOST_ADDR), default_host_addr_len = strlen(DEFAULT_MY_HOST_ADDR);
	for(i=0;Script[i];i++){
		if(http_host_addr_len != 0){
			int j, script_len = strlen(Script[i]), default_ip_index=-1;
			for(j=0;j<(script_len-default_host_addr_len);j++){
				if(memcmp(&(Script[i][j]),DEFAULT_MY_HOST_ADDR,default_host_addr_len) == 0){
					default_ip_index = j;
					break;
				}
			}
			if(default_ip_index == -1)
				printf("%s\n\n",Script[i]);
			else{
				char *tmp_buf = (char *)malloc(script_len+default_host_addr_len+http_host_addr_len);
				memcpy(tmp_buf,Script[i],default_ip_index);
				memcpy(&(tmp_buf[default_ip_index]),HTTP_HOST_ADDR,http_host_addr_len);
				tmp_buf[default_ip_index+http_host_addr_len] = '\0';
				strcpy(&(tmp_buf[default_ip_index+http_host_addr_len]),&(Script[i][default_ip_index+default_host_addr_len]));
				printf("%s\n\n",tmp_buf);
				free(tmp_buf);
			}
		}else{
			printf("%s\n\n",Script[i]);
		}
	}
}

#endif

