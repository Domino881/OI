X=prz
IN_DIR="testy/in/"
OUT_DIR="testy/out/"

make $X

for i in {1..1000000}; do
	time ./$X < ${IN_DIR}in$i.in > outx || break
	diff -s outx ${OUT_DIR}out$i.out || break
done
