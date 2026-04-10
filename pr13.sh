if [ $# -ne 2 ]
then 
	echo "Enter two file names "
	exit 1
fi
if cmp -s "$1" "$2"
then
	echo "Files are same"
else
	echo "Files are different"
fi
