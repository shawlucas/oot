#!/bin/bash

tools/ZAP2/ZAP2.out -e -i $1 -b baserom/ -o $2 -gsf 1 -sm tools/ZAP2/SymbolMap_OoTMqDbg.txt
