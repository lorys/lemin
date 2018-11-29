i=0
bin=./../lem-in
bin_correct=/tmp/lemin/lem-in

make -C /tmp/lemin/
printf "\033[0m"

ls > list

all=$(cat list | wc -l)

mkdir -p trace
rm -rf trace/*

while [ $i -ne $all ]
do
	printf "\ntest n $i\n$(sed $i!d list)\n"
	$bin < $(sed $i!d list) > trace/$(sed $i!d list)
	$bin_correct < $(sed $i!d list) > trace/$(sed $i!d list)_correc
	diff trace/$(sed $i!d list) trace/$(sed $i!d list)_correc
	sleep 1
	rm trace/$(sed $i!d list)_correc
	i=$(($i + 1))
done
