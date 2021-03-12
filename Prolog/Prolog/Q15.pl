lengthoflist([],0).
lengthoflist([_|T],N):-lengthoflist(T,N1),
                       N is N1+1.
oddeven(List):- lengthoflist(List,N),
                N>0 ->(
                L1 is mod(N,2),
                L1=:=0->
                write("Even length list");
                write("Odd length list")
                );
                write("List is empty").
