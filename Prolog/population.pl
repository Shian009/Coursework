pop(india,548).
pop(china,800).
pop(brazil,108).
pop(usa,203).
area(usa,3).
area(india,1).
area(china,4).
area(brazil,3).

density(X):-pop(X,Y),area(X,Z),A is Y/Z, write(A).