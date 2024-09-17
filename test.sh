#!/bin/bash

# Simple test of the command interpreter

in="abbabaq"
out="0,3,5;"

[[ $(./cmd_int <<< "$in") == "$out"* ]] && echo "PASSED" || echo "FAILED"

in2="aabbcaaq"
out2="0,1,5,6;"

[[ $(./cmd_int <<< "$in2") == "$out2"* ]] && echo "PASSED" || echo "FAILED"

in3="abababababababababababababaccccccccccccccccq"
out3="0,2,4,6,8,10,12,14,16,18,20,22,24,26;"

[[ $(./cmd_int <<< "$in3") == "$out3"* ]] && echo "PASSED" || echo "FAILED"

in4="sadccccaq"
out4="0,5;"

[[ $(./cmd_int <<< "$in4") == "$out4"* ]] && echo "PASSED" || echo "FAILED"

in5="abababababcccccccqls"
out5="0,2,4,6,8;"

[[ $(./cmd_int <<< "$in5") == "$out5"* ]] && echo "PASSED" || echo "FAILED"
