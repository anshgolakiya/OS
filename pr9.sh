echo "Enter date (dd-mm-yyyy):"
read date

    day=${date:0:2}
    month=${date:3:2}
    year=${date:6:4}
     
    if [ $month -ge 1 ] && [ $month -le 12 ] && [ $day -ge 1 ] && [ $day -le 31 ]
    then
        echo "Valid Date"
    else
        echo "Invalid Date"
    fi
