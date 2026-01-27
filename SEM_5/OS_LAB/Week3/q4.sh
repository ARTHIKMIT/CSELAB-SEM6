#!/bin/bash
echo "Enter n "
read n
fact=1
i=1 
until [ $i -gt $n ]
do 
fact=$(( fact * i ))
i=`expr $i + 1`
done
echo $fact
