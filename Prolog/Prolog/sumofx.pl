sum(0,Sum,Total):-Total is Sum.
sum(N,Sum,Total):-
    write('Enter your number '),
           read(X), nl,
           S1 is Sum+X,
           N1 is N-1,
           sum(N1,S1,Total).
input:-write('Enter number of integers you want to add '),
           read(N), nl,
           sum(N,0,Total),
           write('Total Sum:'),write(Total).
