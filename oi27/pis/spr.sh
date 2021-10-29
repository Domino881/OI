a=0
b=0

t=10
for i in {1..10}; do
	echo $i
	python3 pistestgen.py 4 test4 ./
	python3 pis.py < test4.in > outx
	python3 check.py outx test4.out)
	print $a
	python3 pis_stare.py < test4.in > outx
	python3 check.py outx test4.out
done
echo $((a / t))
echo $((b / t))
