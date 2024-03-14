SELECT count(NumCom) FROM commande NATURAL JOIN client WHERE NomC = 'Pierre';
SELECT NumCom FROM commande WHERE qte >= (SELECT qte FROM commande NATURAL JOIN client WHERE NomC = 'Vincent');
SELECT NumCom FROM commande WHERE qte >= ANY (SELECT qte FROM commande NATURAL JOIN client);
SELECT NomP FROM commande NATURAL JOIN client WHERE NomC != 'Jean';
SELECT commande.NomP FROM fournisseur INNER JOIN produit ON fournisseur.NumF = produit.NumF INNER JOIN commande ON produit.NomP = commande.NomP INNER JOIN client ON commande.NumC = client.NumC WHERE VilleC = VilleF;