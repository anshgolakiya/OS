echo "How many prime numebr you want to dispaly : "
read n
count=0
i=2
num=2
echo "prime number list :"
while [ $count -lt $n ] 
do
	prime=0
	while [ $i -le $((num/2)) ]
	do
		if [ $(($num % $i)) -eq 0 ]
		then
			prime=1
			break
		fi
		((i++))
	done
	if [ $prime -eq 0 ] 
	then 
		echo -n "$num " 
		((count++))
	fi
	((num++))
done
	
