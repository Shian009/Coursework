len([],0).
len([_|L],N):- len(L,N1),
               N is N1+1.
evenlength(L):- len(L,X),
                A is mod(X,2),
                A==0.
oddlength(L):- len(L,X),
               A is mod(X,2),
               A==1.