#!/bin/bash

PRO_FILE=dontforget.pro

/usr/bin/qmake
/usr/bin/lupdate -verbose $PRO_FILE
/usr/bin/lrelease  -verbose $PRO_FILE
make -j4
