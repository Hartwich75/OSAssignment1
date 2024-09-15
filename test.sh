#!/bin/bash

# Simple test of the command interpreter

in="abbabaq"
out="0,3,5;"

[[ $(./cmd_int <<< "$in") == "$out"* ]] && echo "PASSED" || echo "FAILED"

in2="aabbcaaq"
out2="0,1,5,6;"

[[ $(./cmd_int <<< "$in2") == "$out2"* ]] && echo "PASSED" || echo "FAILED"

in3="ababababccccq"
out2="0,2,4,6;"

[[ $(./cmd_int <<< "$in3") == "$out3"* ]] && echo "PASSED" || echo "FAILED"


