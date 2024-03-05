#!/bin/bash


program=philo

for ((i=1; i<= 5000; i++))
do 
	echo "========================"
	./$program 2 400 200 199 
	echo "========================"
done


echo 


cat log.txt | grep "dead"
