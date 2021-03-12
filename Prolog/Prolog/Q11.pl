concatenate([],L2,L2).
concatenate([H|T],L2,[H|L3]):-concatenate(T,L2,L3).
% Suppose my lists are: [1,2,3] and [a,b]
% Working:
% [1,|2,3] [a,b] => R=[1,....]
% [2|3] [a,b] => R =[2,...]
% [3] [a,b] =>R=[3,...]
% [] [a,b]=> R=[a,b]  #base case
% Now [a,b] is returned from stack to form R=[3,a,b] head was appended
% [3,a,b] is returned from stack to form R=[2,3,a,b]  "    "    "
% [2,3,a,b] is returned from stack to form R=[1,2,3,a,b]"   "   "
