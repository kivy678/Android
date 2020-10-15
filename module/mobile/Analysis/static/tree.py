# -*- coding:utf-8 -*-

##########################################################################

import os
from io import StringIO

from util.fsUtils import *
from util.hash import *
from util.tree import getTree
from util.Logger import LOG

from common import getSharedPreferences
from webConfig import SHARED_PATH

##########################################################################

sp                  = getSharedPreferences(SHARED_PATH)
ANALYSIS_DIR        = sp.getString('ANALYSIS_DIR')
APP_DIR             = Join(ANALYSIS_DIR, 'tree', 'app')

STRIP_STRING = ['res', 'Data']

Delete(APP_DIR)
DirCheck(APP_DIR)

##########################################################################

class ESCAPE_CONDITION(Exception):
    pass

def getPath(path):
    for r, d, f in os.walk(path):
        try:
            _, subPath = PathSplit(r)
            for s in STRIP_STRING:
                if subPath == s:
                    raise ESCAPE_CONDITION
        except ESCAPE_CONDITION:
            break

        for fileName in f:
           yield Join(r, fileName)


def startCmp(CMP_DIR1, CMP_DIR2):
    cmp_dict1 = dict()
    cmp_set1 = set()

    cmp_dict2 = dict()
    cmp_set2 = set()

    for path in getPath(CMP_DIR1):
        cmp_dict1.update( {getSHA256(path): path} )


    for path in getPath(CMP_DIR2):
        cmp_dict2.update( {getSHA256(path): path} )

    cmp_set1 = set(cmp_dict1.keys())
    cmp_set2 = set(cmp_dict2.keys())


    for sha256 in cmp_set1.symmetric_difference(cmp_set2):
        filePath = cmp_dict1.get(sha256)
        if (filePath is not None):
            cfilePath = Join(APP_DIR, 'CMP1', filePath.replace(CMP_DIR1, '')[1:])
            Copy(filePath, Join(APP_DIR, cfilePath))

        filePath = cmp_dict2.get(sha256)
        if (filePath is not None):
            cfilePath = Join('CMP2', filePath.replace(CMP_DIR2, '')[1:])
            Copy(filePath, Join(APP_DIR, cfilePath))


    with StringIO() as fw:
        for s in getTree(APP_DIR):
            fw.write(s)
            fw.write('\n')

        return fw.getvalue()
