echo "How many prime numebr you want to dispaly : "
read num
count=0
i=2
num=2
while [ $count -lt $n ] 
do
	prime=1
	i=0
	while [ $i -le $((num/2)) ]
	do
		if [$(($num % $i)) -eq 0 ]
		then
			prime=0
		fi
		((i++))
	done
	if [ $prime -eq 1 ] 
	then 
		echo " $num" 
		((count++))
	fi
	((num++))
done
	

