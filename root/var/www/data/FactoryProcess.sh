#!/bin/bash

#PEGA Factory Bach file for launching test tools

/var/www/data/Tool1.exe >> /var/www/data/factorylog.txt
ERRORLEVEL=$?

if [ "$ERRORLEVEL" != "0" ]; then
	echo "<H4><font color=\"red\">FAIL!!!</font></H4>" >> /var/www/data/factorylog.txt
fi

/var/www/data/Tool1.exe >> /var/www/data/factorylog.txt
ERRORLEVEL=$?

if [ "$ERRORLEVEL" != "0" ]; then
	echo "<H4><font color=\"red\">FAIL!!!</font></H4>" >> /var/www/data/factorylog.txt
fi

/var/www/data/Tool1.exe >> /var/www/data/factorylog.txt
ERRORLEVEL=$?

if [ "$ERRORLEVEL" != "0" ]; then
	echo "<H4><font color=\"red\">FAIL!!!</font></H4>" >> /var/www/data/factorylog.txt
fi

/var/www/data/Tool1.exe >> /var/www/data/factorylog.txt
ERRORLEVEL=$?

if [ "$ERRORLEVEL" != "0" ]; then
	echo "<H4><font color=\"red\">FAIL!!!</font></H4>" >> /var/www/data/factorylog.txt
fi

/var/www/data/Tool1.exe >> /var/www/data/factorylog.txt
ERRORLEVEL=$?

if [ "$ERRORLEVEL" != "0" ]; then
	echo "<H4><font color=\"red\">FAIL!!!</font></H4>" >> /var/www/data/factorylog.txt
fi


