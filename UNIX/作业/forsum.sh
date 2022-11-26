#!/bin/bash
sum=0
count=$#
num=0 
for i in $@
do
((num=num+1)) 
echo -n $i
if [[ $num -lt $count ]]
then
echo -n " + "
fi    
((sum=sum+$i))
done
echo " = $sum" 