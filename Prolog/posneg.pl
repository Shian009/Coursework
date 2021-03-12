split([],[],[]).
split([X|L],[X|P],N):-X>=0,
                      split(L,P,N).
split([X|L],P,[X|N]):-X<0,
                      split(L,P,N).
