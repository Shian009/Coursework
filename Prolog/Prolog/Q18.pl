check([],M2,M2).
check([H1|T1],Max,M):-
    max(H1,Max,R),
    check(T1,R,M).
sorts([],RList1,Rlist2).
sorts([H|T],Interm,R10):-
    check([H|T],M,H1),


