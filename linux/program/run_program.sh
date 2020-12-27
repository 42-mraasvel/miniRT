if [ $# -eq 0 ]
then
    make && time ./a.out ./files/test.rt
elif [[ $1 == "re" ]]
then
	make re && time ./a.out
else
	make && time ./a.out $1 $2
fi
