echo "Enter date (dd-mm-yyyy):"
read date

if [[ $date =~ ^[0-9]{2}-[0-9]{2}-[0-9]{4}$ ]]
then
    day=${date:0:2}
    month=${date:3:2}
    year=${date:6:4}

    if [ $month -ge 1 ] && [ $month -le 12 ] && [ $day -ge 1 ] && [ $day -le 31 ]
    then
        echo "Valid Date"
    else
        echo "Invalid Date"
    fi
else
    echo "Invalid Date Format"
fi
