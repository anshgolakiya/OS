echo "Enetr student name : "
read name 
echo "Enetr frist subject mark : "
read m1
echo "Enter second subject mark : "
read m2 
echo "Enter third subject mark : "
read m3 

total=$((m1+m2+m3))
percentage=$((total/3))

if [ $percentage -ge 80 ]
then
	class="frist class"
elif [ $percentage -ge 60 ]
then 
	class="second class"
elif [ $percentage -ge 35 ]
then 
	class="third class"
else
	class="you are fail" 
fi
echo "Mark Sheet"
echo "==========================="
echo "student name : $name "
echo "subject no. 1 mark : $m1 "
echo "subject no. 2 mark : $m2 "
echo "subject no. 3 mark : $m3 "
echo "=========================="
echo "Total mark : $total "
echo "Percentage : $percentage "
echo "class : $class "
echo "=========================="
