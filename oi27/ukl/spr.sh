X=ukl
CHECK=check
GEN=gen
make $X && make $CHECK && make $GEN
for i in {1..1000}; do
	echo $i
	./$GEN > inp
	./$X < inp > outx
	(cat inp && echo "" && cat outx) > outX
	./$CHECK < outX || break
done
