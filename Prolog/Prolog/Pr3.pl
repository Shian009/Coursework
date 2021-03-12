recurfact(0,1).
recurfact(Num, Fact):- Num1 is Num-1,
                  recurfact(Num1, Fact1),
                  Fact is Num*Fact1.

iFactorial(0,Fact,Fact).
iFactorial(Num,A,Fact):-
           Num>0,
           A1 is Num*A,
           Num1 is Num-1,
           iFactorial(Num1, A1, Fact).

myinput(X):-write('Enter your number '),
           read(X), nl.


factorial:-myinput(Num),
           recurfact(Num, Fact),
           write('The factorial of '), write(Num), write(' is = '), write(Fact).


iterative_Factorial:-myinput(Num),
                    A=1,
                    iFactorial(Num,A,Fact),
                    write('The factorial of '), write(Num), write(' is = '), write(Fact).
