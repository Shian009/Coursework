maximum(X,Y,X):- X>=Y.
maximum(X,Y,Y):- X<Y.
minimum(X,Y,X):- X<Y.
minimum(X,Y,Y):- X>=Y.
myinput(X,Y):-write('Enter X: '),
    read(X),
    write('Enter Y: '),
    read(Y).

max:-myinput(X,Y),
    maximum(X,Y,Z),
    write('Max of '), write(X), write(' and '), write(Y), write(' is '), write(Z), nl.

min:-myinput(X,Y),
    minimum(X,Y,Z),
    write('Min of '), write(X), write(' and '), write(Y), write(' is '), write(Z), nl.
