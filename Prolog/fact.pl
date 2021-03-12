rec_fact(0,1).
rec_fact(X,Y):- X>0,
                X1 is X-1,
                rec_fact(X1,Y1),
                Y is Y1*X.

fact(0,F,F).
fact(X,A,F):-X>0,
                A1 is (X*A),
                X1 is (X-1),
                fact(X1,A1,F).
iter_fact(X,F):-A=1,
                fact(X,A,F).
