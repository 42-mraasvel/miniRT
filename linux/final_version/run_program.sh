file='./test.rt'
EXEC='a.out'

if [ $# -eq 0 ]
then
    make > /dev/null && time ./$EXEC $file
elif [[ $1 == "re" ]]
then
	make re && time ./$EXEC
else
	make > /dev/null && time ./$EXEC $1 $2 $3
fi
