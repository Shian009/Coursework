mymulti(0, _, 0).
mymulti(X, Y, Z) :-
    X > 0,
    X1 is X - 1,
    mymulti(X1, Y, Z1),
    Z is Y + Z1.

myinput(X,Y):-write('Enter first number: '),
       read(X),nl,
       write('Enter second number: '),
       read(Y), nl.

multiplication:-
       myinput(X,Y),
       mymulti(X, Y, ),
       write(X), write('*'), write(Y), write(' = '), write(S).
