X=gan
TESTDIR=testy/gan/subtask3
INPREF=gan
OUTPREF=gan

make $X
trap "tput ed" SIGINT

[[ $# == 0 ]] && i=0
[[ $# == 0 ]] || i=$1

tput sc
while [[ -e $TESTDIR/in/$INPREF$i.in ]]; do
	oiejq/oiejq.sh bin/$X < $TESTDIR/in/$INPREF$i.in > $X.out
	[[ $? == 0 ]] || break
	diff -sb $X.out $TESTDIR/out/$OUTPREF$i.out || break
	i=$(( i + 1 ))
	#for i in {1..7}; do tput cuu1; done
	tput rc
done

