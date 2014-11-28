#!/bin/bash

/usr/bin/qmake
/usr/bin/lupdate -verbose birthday.pro
/usr/bin/lrelease  -verbose birthday.pro
make -j4
