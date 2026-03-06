echo "enter a string you want to check it is palidrom : "
read str 

rev=$(echo $str | rev)

if [ "$str" = "$rev" ]
then 
	echo "Given string is palindrom."
else
	echo "Given string is not palindrom."	
fi
