power1(_,0,1).
power1(X,Y,Result):-
              Y1 is Y-1,
              power1(X,Y1,Result1),
              Result is Result1*X.

myinput(X,Y):-write('Enter Number: '), nl,
       read(X),nl,
       write('Enter Power: '), nl,
       read(Y), nl.

power:-myinput(Num,Pow),
       power1(Num, Pow, Ans),
       write(Num), write(' ** '), write(Pow), write(' = '), write(Ans).
