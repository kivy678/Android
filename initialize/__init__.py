# -*- coding:utf-8 -*-

from initialize.devices import *

def setDevice():
    print(f"{'[*]':<5}Settings Start")

    print(f"{'':>5}1. Basis App Install Start")
    appInstaller()

    print(f"{'':>5}2. Cow Exploit Start")
    cowExploit()

    print(f"{'':>5}3. Frida Server Install Start")
    fridaServer()
 
    print(f"{'':>5}4. Android Server Install Start")
    androidServer()

    print(f"{'[*]':<5}Settings End")
