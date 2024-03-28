SELECT nom || ' ' || prenom nom_prenom FROM musicien WHERE datnaiss < 1930;
SELECT nom || ' ' || prenom nom_prenom FROM joue INNER JOIN album ON joue.refAlbum = album.refAlbum WHERE titre = 'Electric Ladyland';
SELECT ville FROM label NATURAL JOIN album NATURAL JOIN joue WHERE nom = 'Coltrane' AND prenom = 'John';
SELECT titre FROM album WHERE annee = (SELECT annee FROM album WHERE titre = 'Are You Experienced');
SELECT MAX(duree) DureeMax FROM album;
SELECT ville, COUNT(ville) FROM album NATURAL JOIN label GROUP BY ville;
SELECT COUNT(refAlbum) albums FROM label NATURAL JOIN album NATURAL JOIN joue WHERE nom = 'Coltrane' AND prenom = 'John';

SELECT DISTINCT nom, prenom FROM label NATURAL JOIN album NATURAL JOIN joue WHERE nom != 'Coltrane' AND prenom != 'John' GROUP BY refAlbum, nom, prenom HAVING COUNT(refAlbum) > (SELECT COUNT(refAlbum) albums FROM label NATURAL JOIN album NATURAL JOIN joue WHERE nom = 'Coltrane' AND prenom = 'John');