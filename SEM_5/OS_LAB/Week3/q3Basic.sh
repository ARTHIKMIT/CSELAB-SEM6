#!/bin/bash
echo "Enter a "
read a
echo "Enter b "
read b
echo "Enter c "
read c

d=$(( b * b - 4 * a * c ))

case $d in
[0]) echo "Equal Real roots" ;;
-*) echo "Imaginary Roots" ;;
*) echo "Distinct Real roots"
;;
esac
