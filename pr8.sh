echo "Enetr a number : "
read num

frist=0
sec=1
echo "Fibonnacci Series:"
echo -n "$sec "
for ((i=1; i<num ; i++))
do
	sum=$(($frist+$sec))
	echo -n "$sum "
	frist=$sec
	sec=$sum
done	
