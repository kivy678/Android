# -*- coding:utf-8 -*-

#############################################################################

import os
from util.fsUtils import Join

#############################################################################

BASE_DIR 		= os.path.dirname(os.path.realpath(__file__))

LOGGER_PATH 	= Join(BASE_DIR, "LOG")
LOG_PRINT 		= True

GLOBAL_SETTINGS = Join(BASE_DIR, "global.ini")
SHARED_PATH_DIR = Join('common', 'shared_prefs')
SHARED_PATH 	= Join(SHARED_PATH_DIR, 'setup.xml')
PROCESS_PATH    = Join(SHARED_PATH_DIR, 'process.xml')

VAR_PATH 		= Join(BASE_DIR, "var")
TMP_PATH 		= Join(BASE_DIR, "tmp")

FLASK_SESSION	= Join(BASE_DIR, "__session__")

#############################################################################
############################### UTIL FILE ###################################

APP_PATH 		= Join(VAR_PATH, "app")
SERVER_PATH 	= Join(VAR_PATH, "server")
DECOMPLIE_PATH 	= Join(VAR_PATH, "decomplie")
TOOL_PATH       = Join(VAR_PATH, "tool")
TOOL_USER_PATH  = Join(VAR_PATH, "user")

#############################################################################

CACHE 			= Join(BASE_DIR, 'module', 'database', 'cache')

#############################################################################

ES_URL          = "http://127.0.0.1:9200"

REDIS_IP        = '127.0.0.1'
REDIS_PORT      = 6379
REDIS_PASSWD    = ''

_REDIS_CACHE_CONFIG = {
    'host'              : REDIS_IP,
    'port'              : REDIS_PORT,
    #'password'          : REDIS_PASSWD,
    'db'                : 0,
    'max_connections'   : 50,
    'encoding'          : 'utf-8'
}

_REDIS_SESSION_CONFIG = {
    'host'              : REDIS_IP,
    'port'              : REDIS_PORT,
    #'password'          : REDIS_PASSWD,
    'db'                : 1,
    'max_connections'   : 50,
    'encoding'          : 'utf-8'
}

#############################################################################
