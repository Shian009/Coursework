sum(0,Count):- write("Sum: "),
               write(Count).
sum(N,Count):-read(X),
              A is (Count+X),
              B is (N-1),
              sum(B,A).
main:- write("No.of terms: "),
       read(N),nl,
       write("Enter the terms: "),nl,
       sum(N,0).

