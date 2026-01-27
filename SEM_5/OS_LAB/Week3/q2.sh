#!/bin/bash
echo "Enter a number"

read n
i=0
until [ $i -eq $n ]
do
if [ $((i%2)) != 0 ]
then echo $i
fi
i=`expr $i + 1` 
done
