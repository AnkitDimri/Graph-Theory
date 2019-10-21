#!/usr/bin/env bash

g++ rnd.cpp -o rnd
echo
echo "Testing with test input test case 1: "
./rnd < input1.txt
echo
echo "Testing with test input test case 2: "
./rnd < input2.txt
echo
echo "Testing with test input test case s3: "
./rnd < input3.txt
echo
