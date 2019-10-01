#!/usr/bin/env bash

g++ rnd.cpp -o rnd
echo
echo "Testing with test input 1: "
./rnd < input1.txt
echo
echo "Testing with test input 2: "
./rnd < input2.txt
echo
echo "Testing with test input 3: "
./rnd < input3.txt
echo
