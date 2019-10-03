#!/usr/bin/env bash

g++ search.cpp -o srch
echo
echo "Testing input1 :"
./srch < input1_search.txt
echo
