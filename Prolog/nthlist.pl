find_nth_element(1,[X|_],X).
find_nth_element(N,[_|L],X):- N>1,
                              N1 is (N-1),
                              find_nth_element(N1,L,X).


































find_nth_element(1,[X|_],X).
find_nth_element(N,[_|L],X):- N>0,N is (N-1),find_nth_element(N,L,X).