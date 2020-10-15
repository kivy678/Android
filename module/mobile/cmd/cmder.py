# -*- coding:utf-8 -*-

#############################################################################

from module.mobile.cmd.shell import SHELL
from functools import wraps

#############################################################################

class COMMANDER(SHELL):
    def mode(f):
        @wraps(f)
        def inner(*args, **kwargs):
            self, cmd = args

            try:
                if kwargs['su'] == True:
                    cmd = repr('su -c ' + repr(cmd))
            except KeyError:
                pass

            try:
                if kwargs['shell'] == True:
                    cmd = 'adb shell ' + cmd
            except KeyError:
                pass

            try:
                if kwargs['java'] == True:
                    cmd = 'java -jar ' + cmd
            except KeyError:
                pass

            return f(self, cmd, **kwargs)
        return inner

    @mode
    def runCommand(self, cmd, shell=False, java=False, su=False, timeout=60, encoder='utf-8'):
        return super().runCommand(cmd, timeout, encoder)
