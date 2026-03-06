echo "enter number"
read num
echo "Multiplication table of $num"
echo "============================"
for i in {1..10}
do
	result=$((num * i))
	echo " $num x $i = $result "
	done
