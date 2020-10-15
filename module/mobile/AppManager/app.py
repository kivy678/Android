# -*- coding:utf-8 -*-

###########################################################################################

from datetime import datetime
import pandas as pd

from util.fsUtils import Join
from util.parser import *

from module.database.structure import STATUS
from module.database import df_app

###########################################################################################

class APP_INFOR:
    def __init__(self):
        self._fileName = None
        self._decodePath = None
        self._sha256 = None
        self._pkgName = None


    def __getattr__(self, key):
        try:
            return self.__dict__[key]
        except KeyError as e:
            return None

    def parser(self, p):
        if isinstance(p, XmlParser):
            self._pkgName = p.parser('manifest', 'package')
            applicatopmActivity = p.parser('application', 'android:name')

            data = {'pkg': self._pkgName, 'fileName': self._fileName, 'parent': 1, 'ctime': datetime.now(), 'status': STATUS.INIT.value}
            add_idx = pd.Series(data).rename(self._sha256)
            df_app.DATA_FRAME = df_app.DATA_FRAME.append(add_idx)
            df_app.DATA_FRAME = df_app.DATA_FRAME[~df_app.DATA_FRAME.duplicated(keep='first')]

            df_app.saveCSV()

        elif isinstance(p, JsonParser):
            ManifestJson = p.parser()

    @property
    def decodePath(self):
        return self._decodePath

    @decodePath.setter
    def decodePath(self, decodePath):
        self._decodePath = decodePath

    @property
    def sha256(self):
        return self._sha256

    @sha256.setter
    def sha256(self, sha256):
        self._sha256 = sha256

    @property
    def pkgName(self):
        return self._pkgName

    @pkgName.setter
    def pkgName(self, pkgName):
        self._pkgName = pkgName

    @property
    def fileName(self):
        return self._fileName

    @fileName.setter
    def fileName(self, fileName):
        self._fileName = fileName
