declare NAMES

NAMES[0]=libft
NAMES[1]=libvect
NAMES[2]=libftprintf

TOOLDIR=~/work/tools
bash $TOOLDIR/cp_libs.sh

for i in ${NAMES[*]}
do
	mv $i.h ./include
	mv $i.a ./libs
done
