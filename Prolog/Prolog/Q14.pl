sumoflist([],0).
sumoflist([H|T],Mysum):- sumoflist(T,N),
                   Mysum is H+N.
main:-write("Enter your list "),
     read(L),
     sumoflist(L,X),
     write(" Sum of elements in the list: "),write(X).

%   0th recursion   1st recursion   2nd recursion   3rd recursion
%   H=1             H=2             H=3              H=[]
%   T=[2,3]         T=[3]           T=[]             returns 0 #basecase
%   Mysum=N+1       Mysum=N+2       Mysum=N+3
%   =6      <-----  =5  <-------    =0+3=3
