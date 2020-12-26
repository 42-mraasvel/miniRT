if [ $# -eq 0 ]
then
    make && ./a.out
elif [[ $1 == "re" ]]
then
	make re && ./a.out
else
	make && ./a.out $1
fi
