split([],[],[]).
split([X|L],[X|P],N):-Z is mod(X,2),
                      Z==0,
                      split(L,P,N).
split([X|L],P,[X|N]):-Z is mod(X,2),
                      Z==1,
                      split(L,P,N).