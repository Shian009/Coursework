nthelem(1,[H|_],H).
nthelem(N,[_|T],X):-   N1 is N-1,
                       nthelem(N1,T,X).
main:-write("Enter the list "),
    read(L),
    write("Enter N"),
    read(N),
    nthelem(N,L,X),N>0,
    write("The element is "),
    write(X).
% Suppose the list is [6,5,4,3,2,1]
% N=3
%      N             [_|T]           X
%      3           [5,4,3,2,1]
%      2           [4,3,2,1]
%      1           [3,2,1]           4  #base case
