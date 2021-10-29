import sys
fX = open(sys.argv[1], "r")
fY = open(sys.argv[2], "r")

X = fX.read().split()
Y = fY.read().split()

licz=0
for i in range(0,len(X)):
    if(X[i] == Y[i]): licz+=1

print(100.0*licz/len(X))
