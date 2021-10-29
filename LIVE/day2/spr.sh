X=ple_brut
BRUT=brut
GEN=gen
CHECK=check
make $X && make $GEN && make $CHECK

for i in {1..100}; do
	echo $i:
	bin/$GEN $i > inp
	cat inp > outx
	echo "" >> outx
	bin/$X < inp >> outx
	bin/$CHECK < outx || break
	echo "success"
done
