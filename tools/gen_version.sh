#!/bin/bash
echo "const char gBuildTeam[] = \"`whoami`@`hostname`\";" 
echo "const char gBuildDate[] = \"`date '+%y-%m-%d %H:%M:%S'`\";"
echo 'const char gBuildMakeOption[] = "'$*'";'