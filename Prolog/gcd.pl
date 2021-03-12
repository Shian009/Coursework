find_gcd(A,0,A).
find_gcd(A,B,C):- A>0,
                  X is A mod B,
                  find_gcd(B,X,C).
