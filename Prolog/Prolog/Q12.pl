conc([],L2,L2).
conc([H|T1],L2,[H|T2]):- conc(T1,L2,T2).
myreverse([],[]).
myreverse([H|T],R):- myreverse(T,R1),conc(R1,[H],R).
main:-write("Enter the list to be reversed "),read(L),
     myreverse(L,X),write("The reverse list is "),write(X).
%Suppose my list is [1,2,3]
%        H                         T              Conc
% myreverse([1,2,3],X)
%        1                        [2,3]           [1]
% myreverse([2,3],X)
%        2                         [3]            [2,1] #[H|Accum]
% myreverse([3],X)
%        3                         []              [3,2,1]
% myreverse([],X)
% bind the  conc to the final result
