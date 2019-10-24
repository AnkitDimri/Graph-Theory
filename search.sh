#!/usr/bin/env bash

g++ search.cpp -o srch
echo
echo "Testing input test case 1 :"
./srch < input1_search.txt
echo
echo "Testing input test case 2 :"
./srch < input2_search.txt
