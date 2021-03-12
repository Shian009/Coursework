splitposneg([],[],[]).
splitposneg([H|T], [H|P], N) :-
                                 H>=0,
                                 splitposneg(T, P, N).
splitposneg([H|T], P, [H|N]) :-
                                 H<0,
                                 splitposneg(T, P, N).
mymain:- write('Enter the list: '),read(L),nl,
       splitposneg(L,L1,L2),
       write('Positive sublist is: '),write(L1),nl,
       write('Negative sublist is: '),write(L2).

