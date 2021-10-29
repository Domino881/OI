X=pom
IN_DIR="maxtest/"
OUT_DIR="maxtest/"

make $X

for i in {1..1000000}; do
	time ./$X < ${IN_DIR}in$i.in > outx || break
	diff -s outx ${OUT_DIR}out$i.out || break
done
