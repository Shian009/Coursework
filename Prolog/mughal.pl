reigns(babur,1526,1530).
reigns(humayun,1530,1540).
reigns(humayun,1555,1556).
reigns(akbar,1556,1605).
reigns(jahangir,1605,1627).
reigns(shahjahan,1626,1640).
emperor(X):-reigns(A,B,C),X>=B,X<=C,write(A).
