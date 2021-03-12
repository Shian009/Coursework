mymember(X, [X|_]):-write(X),write(' is a member of the list.').
mymember(X, [_|T]):- mymember(X, T).

%Suppose my list is: [John, Mary, Lorem] and checking for Mary
%   X                [_|T]
%  Mary          [Mary, Lorem]
%  Mary          [X|_] matched     #base case
