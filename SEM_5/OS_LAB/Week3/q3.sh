#!/bin/bash
echo "Enter a "
read a
echo "Enter b "
read b
echo "Enter c "
read c

d=$(( b * b - 4 * a * c ))

case $d in
[0]) echo "Equal Real roots "
root=$(( -1 * b / (2 * a)))
echo $root ;;
-*) echo "Imaginary Roots" ;;
*) echo "Distinct Real roots"
p1=$(( -1 * b / (2 * a)))
p2=$((b * b - 4 * a * c))
p2=`expr sqrt( p2 ) | -bc` #to be fixed
r1=$(( p1 + p2 / (2 * a)))
r2=$(( p1 - p2 / (2 * a)))
echo $r1
echo $r2
;;
esac
