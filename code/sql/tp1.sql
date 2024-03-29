SELECT * FROM produit;
SELECT NomF, VilleF FROM fournisseur;
SELECT NomP FROM produit WHERE prix > 1300;
SELECT NomP FROM produit WHERE prix > 1300 AND prix < 1500;
SELECT NomP FROM produit WHERE prix = 1300 OR prix = 1500;
SELECT NomC FROM client WHERE NomC LIKE 'J%';
SELECT DISTINCT NomP FROM produit ORDER BY NomP ASC;
SELECT NomC FROM client WHERE (2024 - AnneeNaissC) > 40;
SELECT NumF FROM produit WHERE NomP = 'parpaing' AND Prix > 1300;
SELECT NomF FROM produit INNER JOIN fournisseur ON produit.NumF = fournisseur.NumF WHERE NomP = 'parpaing' OR NomP = 'briques';
SELECT NomC FROM client INNER JOIN commande ON client.NumC = commande.NumC WHERE NomP = 'briques';
SELECT NomP FROM produit INNER JOIN fournisseur ON produit.NumF = fournisseur.NumF WHERE VilleF LIKE '%PARIS';
SELECT NomC, VilleC FROM client INNER JOIN commande ON client.NumC = commande.NumC WHERE Qte > 8 AND Qte < 14;