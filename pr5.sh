echo "Enter a number : "
read num 
fact=1
i=1 
while [ $i -le $num ]
do
	((fact*=i))
	((i++))
	done
echo "factorial of $num = $fact "
