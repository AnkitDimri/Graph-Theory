#!/usr/bin/env bash

g++ search.cpp -o srch
echo
echo "Testing input 1 :"
./srch < input1_search.txt
echo
echo "Testing input 2 :"
./srch < input2_search.txt
