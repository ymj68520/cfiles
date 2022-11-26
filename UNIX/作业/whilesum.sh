#!/bin/bash
sum=0
while [ $# -gt 0 ]
do
    echo -n $1
    if [[ $# -gt 1 ]]
    then
        echo -n " + "
    fi
    ((sum=sum+$1))
    shift
done
echo " = $sum"