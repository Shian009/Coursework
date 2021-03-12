arithmetic:-
    write('Enter X: '),nl,
    read(X),
    write('Enter Y: '),nl,
    read(Y),
    MyAddition is X+Y,  %addition%
    write(X), write(' + '), write(Y), write(' = '), write(MyAddition), nl,
    MyDifference is X-Y,  %subtraction%
    write(X), write(' - '), write(Y), write(' = '), write(MyDifference), nl,
    MyProduct is X*Y,  %multiplication%
    write(X), write(' * '), write(Y), write(' = '), write(MyProduct), nl,
    MyDivision is X/Y,   %division%
    write(X), write(' / '), write(Y), write(' = '), write(MyDivision), nl,
    MyIntDiv is X//Y,   %integer division%
    write(X), write(' // '), write(Y), write(' = '), write(MyIntDiv), nl,
    MyExponent is X**Y,   %exponent%
    write(X), write(' ** '), write(Y), write(' = '), write(MyExponent), nl,
    MyMax is max(X,Y),  %maximum%
    write('Maximum of '), write(X), write(' and '), write(Y), write(' = '), write(MyMax), nl,
    MyMin is min(X,Y),  %minimum%
    write('Minimum of '), write(X), write(' and '), write(Y), write(' = '), write(MyMin), nl.
