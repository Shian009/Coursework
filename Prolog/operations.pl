add(X,Y,Z):-Z is X+Y.
sub(X,Y,Z):-Z is X-Y.
mul(X,Y,Z):-Z is X*Y.
div(X,Y,Z):-Y\=0,
            Z is X/Y.
exp(X,Y,Z):-Z is X**Y.
maximum(X,Y,X):-X>Y.
maximum(X,Y,Y):-Y>X.
maximum(X,X,X):-X=X.
minimum(X,Y,X):-X<Y.
minimum(X,Y,Y):-Y<X.
minimum(X,X,X):-X=X.
squareroot(X,Y):-Y is sqrt(X).
