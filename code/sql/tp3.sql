SELECT NomF, commande.NomP, Prix FROM fournisseur INNER JOIN produit ON fournisseur.NumF = produit.NumF INNER JOIN commande ON produit.NomP = commande.NomP INNER JOIN client ON commande.NumC = client.NumC WHERE NomC = 'Jean';
SELECT NomF, commande.NomP, Prix FROM fournisseur INNER JOIN produit ON fournisseur.NumF = produit.NumF INNER JOIN commande ON produit.NomP = commande.NomP INNER JOIN client ON commande.NumC = client.NumC WHERE NomC = 'Jean' ORDER BY NomF ASC, NomP DESC;
SELECT MIN(NomP) FROM produit;
SELECT NomP, AVG(Prix) FROM produit GROUP BY NomP;
SELECT NomP, AVG(Prix) FROM produit GROUP BY NomP HAVING AVG(Prix) > 1000;
SELECT NomP FROM produit WHERE Prix > (SELECT AVG(Prix) FROM produit);
SELECT NomP, AVG(Prix) FROM produit GROUP BY NomP HAVING count(NumF) >= 2;
SELECT commande.NomP, Prix FROM fournisseur INNER JOIN produit ON fournisseur.NumF = produit.NumF INNER JOIN commande ON produit.NomP = commande.NomP INNER JOIN client ON commande.NumC = client.NumC WHERE fournisseur.VilleF LIKE '%ANGERS' AND client.VilleC LIKE '%Paris';