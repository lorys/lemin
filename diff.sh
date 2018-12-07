i=0

while [ $i -ne 50 ]
do
	mkdir -p map_test
	../../generator --big > map_test/big
	../../generator --big-superposition > map_test/big_superposition
	echo $(($(./lem-in < map_test/big | wc -l | tr -d ' ')-$(cat map_test/big_superposition | tr -d ' ')))
	i=$(($i + 1))
done
