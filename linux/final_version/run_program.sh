file='./test.rt'
EXEC='miniRT'

if [ $# -eq 0 ]
then
    make && time ./$EXEC $file
elif [[ $1 == "re" ]]
then
	make re && time ./$EXEC
else
	make && time ./$EXEC $1 $2 $3
fi
