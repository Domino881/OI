X=gan
TESTDIR=testy/gan/subtask4
INPREF=gan
OUTPREF=gan

make $X

[[ $# == 0 ]] && i=0
[[ $# == 0 ]] || i=$1

while [[ -e $TESTDIR/in/$INPREF$i.in ]]; do
	SECONDS=0
	bin/$X < $TESTDIR/in/$INPREF$i.in > $X.out
	[[ $WORST_TIME < $SECONDS ]] && WORST_TIME=$SECONDS
	result=$(diff -sb $X.out $TESTDIR/out/$OUTPREF$i.out)
	[[ $? == 0 ]] || break
	echo -ne "worst time is $WORST_TIME s; "
	echo -ne "$result\r"
	i=$(( i + 1 ))
done

echo -e "\n$result"
echo "worst time is $WORST_TIME s"
echo "$TESTDIR/in/$INPREF$i.in doesn't exist or the program failed"
