file='./files/easy.rt'

if [ $# -eq 0 ]
then
    make && time ./a.out $file
elif [[ $1 == "re" ]]
then
	make re && time ./a.out
else
	make && time ./a.out $1 $2
fi
