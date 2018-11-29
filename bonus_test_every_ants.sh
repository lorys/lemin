i=0

while [ $i -ne $1 ]
do
	./lem-in -select $i < $2
	sleep 0.1
	i=$(( $i + 1 ))
done
