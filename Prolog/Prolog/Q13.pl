myconc([],L2,L2).
myconc([H|T1],L2,[H|L3]):- myconc(T1,L2,L3).
reverselist([],[]).
reverselist([H|T],R):- reverselist(T,R1),myconc(R1,[H],R).
isEqual([],[]):- true.
isEqual([H1|_],[H2|_]):- false.
isEqual([H1|T1],[H1|T2]):- isEqual(T1,T2).
palindrome(L):- reverselist(L,R),isEqual(L,R),
               write('It is a palindrome list.').
myinput:-write("Enter the list "),
    read(L),
     palindrome(L).

% Suppose my list is [m,a,d,a,m]
% First it reverses the list as: [m,a,d,a,m]
% Goes to check isPalindrome with original list and reverse list
% Checks for both the heads returns true
% goes to check the tails and then recurses itself.
