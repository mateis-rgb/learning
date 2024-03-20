SELECT count(NumCom) FROM commande NATURAL JOIN client WHERE NomC = 'Pierre';
SELECT NumCom FROM commande WHERE qte >= (SELECT qte FROM commande NATURAL JOIN client WHERE NomC = 'Vincent');
SELECT NumCom FROM commande WHERE qte >= ANY (SELECT qte FROM commande NATURAL JOIN client);
SELECT NomP FROM commande NATURAL JOIN client WHERE NomC != 'Jean';
SELECT commande.NomP FROM fournisseur INNER JOIN produit ON fournisseur.NumF = produit.NumF INNER JOIN commande ON produit.NomP = commande.NomP INNER JOIN client ON commande.NumC = client.NumC WHERE LOWER(SUBSTRING(VilleC, 6)) = LOWER(SUBSTRING(VilleF, 6));
SELECT DISTINCT VilleC, VilleF FROM fournisseur INNER JOIN produit ON fournisseur.NumF = produit.NumF INNER JOIN commande ON produit.NomP = commande.NomP INNER JOIN client ON commande.NumC = client.NumC WHERE LOWER(SUBSTRING(VilleC, 6)) = LOWER(SUBSTRING(VilleF, 6));
SELECT NomP FROM fournisseur INNER JOIN produit on fournisseur.NumF = produit.NumF GROUP BY NomP;
SELECT produit.NomP, produit.NumF FROM fournisseur INNER JOIN produit ON fournisseur.NumF = produit.NumF INNER JOIN commande ON produit.NomP = commande.NomP INNER JOIN client ON commande.NumC = client.NumC WHERE NomC = 'Daniel' GROUP BY produit.NumF, produit.NomP HAVING NumF;


SELECT NomF FROM fournisseur INNER JOIN produit ON fournisseur.NumF = produit.NumF WHERE produit.NomP IN (SELECT NomP FROM commande INNER JOIN client ON commande.NumC = client.NumC WHERE NomC = 'Daniel');