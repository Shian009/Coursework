fact(0,1).
fact(Num, Fact):- Num1 is Num-1,
                  fact(Num1, Fact1),
                  Fact is Num*Fact1.

iFactorial(0,Fact,Fact).
iFactorial(Num,A,Fact):-
           Num>0,
           A1 is Num*A,
           Num1 is Num-1,
           iFactorial(Num1, A1, Fact).


factorial:-
           write('Enter Num: '), nl,
           read(Num), nl,
           fact(Num, Fact),
           write('The factorial of '), write(Num), write(' is = '), write(Fact).


iterative_Factorial:-
                    write('Enter Num: '), nl,
                    read(Num), nl,
                    A=1,
                    iFactorial(Num,A,Fact),
                    write('The factorial of '), write(Num), write(' is = '), write(Fact).
