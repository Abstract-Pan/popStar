while true
do 
    scrot -o /run/media/hpp/softwaredata/Code/Projects/popStar/shot.jpg
    python3 '/run/media/hpp/softwaredata/Code/Projects/popStar/popStar_imageProcess.py'
    /run/media/hpp/softwaredata/Code/Projects/popStar/popStar.bin > /run/media/hpp/softwaredata/Code/Projects/popStar/instructions.temp
    cat /run/media/hpp/softwaredata/Code/Projects/popStar/instructions.temp | while read a b
        do
        if test $a = "score:" 
        then
            break
        fi
        xdotool mousemove $[87 + 93 * $b] $[552 + 93 * $a] click 1 click 1
        sleep 1
        echo $a $b
    done
    sleep 10
done 

#180 645 273
