if [ $# -eq 0 ] 
then 
	echo " Please provide number as command line arguments"
fi
numbers=("$@")
n=$#
for ((i=0 ; i<n ; i++))
do
	for ((j=i+1 ; j<n ; j++))
	do
		if [ ${numbers[$i]} -lt ${numbers[$j]} ]
		then
			temp=${numbers[$i]}
			numbers[$i]=${numbers[$j]}
			numbers[$j]=$temp
		fi
	done
done
echo "Numbers in descending order : "
for num in "${numbers[@]}"
do
	echo -n "$num "
done
