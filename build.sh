#!/bin/bash

/usr/bin/qmake-qt4
/usr/bin/lupdate-qt4 -verbose birthday.pro
/usr/bin/lrelease-qt4  -verbose birthday.pro
make -j4
