male(a).
male(x).
male(d).
male(q).
male(z).
male(s).
male(m).
female(b).
female(c).
female(p).
female(y).
female(t).
 female(n).

parent(a,c).
parent(a,d).
parent(b,c).
parent(b,d).

parent(c,y).
parent(c,z).
parent(x,y).
parent(x,z).

parent(d,m).
parent(d,n).
parent(p,m).
parent(p,n).

parent(y,s).
parent(y,t).
parent(q,s).
parent(q,t).

father(X,Y):-male(X),parent(X,Y).
mother(X,Y):-female(X),parent(X,Y).

grandfather(X,Y):-male(X),parent(X,M),parent(M,N),parent(N,Y).
grandfather(X,Y):-male(X),parent(X,Z),parent(Z,Y).

grandmother(X,Y):-female(X),parent(X,M),parent(M,N),parent(N,Y).
grandmother(X,Y):-female(X),parent(X,Z),parent(Z,Y).

sibling(X,Y):-parent(Z,X),parent(Z,Y).
sister(X,Y):-female(X),sibling(X,Y).
brother(X,Y):-male(X),sibling(X,Y).

cousin(X,Y):-sibling(P,Q),parent(P,X),parent(Q,Y).
aunt(X,Y):-female(X),sister(X,Z),parent(Z,Y).
uncle(X,Y):-male(X),brother(X,Z),parent(Z,Y).







