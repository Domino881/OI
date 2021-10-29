make pro && make check

for i in {1..100}; do
	echo $(($RANDOM%10)) > in
	bin/pro < in > outx
	bin/check < outx > outb
	diff -s outb in || break
done

