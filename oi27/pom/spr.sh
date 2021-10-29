X=pom
BRUT=brut
GEN=gen
make $X && make $BRUT && make $GEN

for i in {1..1000}; do
	echo $i:
	./$GEN > inp
	time ./$X < inp > outx 
	./$BRUT < inp > outb
	diff -s outx outb || break
done
