# -*- coding:utf-8 -*-

################################################################################

import shutil

import glob

from cmd import dev

from util.util import zipDecompress

from util.Logger import LOG
from util.fsUtils import *

from settings import *

################################################################################

def commit():
    cmd = f"mkdir /data/local/tmp/.cache"
    dev.runCommand(cmd, shell=True)

    cmd = f"echo '1' > /data/local/tmp/.cache/AndroidDevice"
    dev.runCommand(cmd, shell=True)


def isRunning():
    cmd = f"find /data/local/tmp/.cache -name AndroidDevice"
    stdin = dev.runCommand(cmd, shell=True)

    if stdin == '':
        return False
    else:
        return True


def fridaServer():
    TOO_PATH = Join(
        SERVER_PATH, f"frida-server-12.7.15-android-{dev.platform}")

    cmd = f"adb push {TOO_PATH} /data/local/tmp/frida-server"
    dev.runCommand(cmd, shell=False)

    cmd = f"chmod 755 /data/local/tmp/frida-server"
    dev.runCommand(cmd, shell=True)

    cmd = f"nohup /data/local/tmp/frida-server &"
    dev.runCommand(cmd, shell=True, su=True)

    LOG.info(f"{'':>5}-> FridaServier Run")


def androidServer():
    TOO_PATH = Join(SERVER_PATH, f"android_server")

    cmd = r"adb forward tcp:23946 tcp:23946"
    dev.runCommand(cmd, shell=False)

    cmd = f"adb push {TOO_PATH} /data/local/tmp/android_server"
    dev.runCommand(cmd, shell=False)

    cmd = f"chmod 755 /data/local/tmp/android_server"
    dev.runCommand(cmd, shell=True)

    cmd = f"nohup /data/local/tmp/android_server &"
    dev.runCommand(cmd, shell=True, su=True)

    LOG.info(f"{'':>5}-> AndroidServer Run")


def cowExploit():
    cmd = "adb push {0} /data/local/tmp".format(Join(PROP_PATH, 'mprop'))
    dev.runCommand(cmd, shell=False)

    cmd = "chmod 755 /data/local/tmp/mprop && /data/local/tmp/mprop ro.debuggable"
    dev.runCommand(cmd, shell=True)

    cmd = "getprop ro.debuggable"
    stdin = dev.runCommand(cmd, shell=True)

    LOG.info(f"{'':>5}-> Done")

    return True if stdin == '1' else False


def appDecompress():
    for _path in glob.glob(Join(APP_PATH, '*')):
        _, app_name = PathSplit(_path)

        zipDecompress(_path, TMP_PATH)

        yield Join(TMP_PATH, app_name.replace('zip', 'apk'))


def appInstaller():
    for app in appDecompress():
        cmd = "adb install {0}".format(app)
        dev.runCommand(cmd, shell=False)

    Delete(TMP_PATH)
    DirCheck(TMP_PATH)

    LOG.info(f"{'':>5}-> Done")
