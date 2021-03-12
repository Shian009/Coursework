gcd(0,0,Res):-Res ='not defined'.
gcd(X,0,Res):- Res is X.
gcd(X,Y,Res):-C is X mod Y,
             gcd(Y,C,Res).
gcd:-
       write('Enter Number1: '), nl,
       read(X),nl,
       write('Enter Number2: '), nl,
       read(Y), nl,
       gcd(X, Y,Res),
       write('GCD of two numbers '), write(X), write(' and '), write(Y),
       write(' = '), write(Res).


