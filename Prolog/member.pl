memb(X,[X|_]).
memb(X,[_|L]):- memb(X,L).
