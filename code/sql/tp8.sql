SELECT titre FROM film WHERE genre = 'Comédie' AND annee = 2003;
SELECT nom, prenom FROM personne INNER JOIN jouer ON personne.num_personne = jouer.num_acteur NATURAL JOIN film WHERE film.titre = 'La folie des grandeurs';
SELECT nom, prenom FROM personne INNER JOIN jouer ON personne.num_personne = jouer.num_acteur WHERE jouer.num_film = (SELECT num_film FROM personne INNER JOIN film ON film.num_realisateur = personne.num_personne WHERE film.genre = 'Comédie' AND personne.prenom = 'Bertrand' AND personne.nom = 'Blier');
SELECT COUNT(num_film) nb_films_g_depardieu FROM personne INNER JOIN jouer ON personne.num_personne = jouer.num_acteur NATURAL JOIN film WHERE personne.nom = 'Depardieu' AND personne.prenom = 'Gérard';
SELECT COUNT(jouer.num_acteur) nb_acteurs, titre, film.num_film FROM film NATURAL JOIN jouer GROUP BY titre, film.num_film;
SELECT DISTINCT nom, prenom FROM personne INNER JOIN jouer ON personne.num_personne = jouer.num_acteur WHERE num_film IN (SELECT num_film FROM personne INNER JOIN jouer ON personne.num_personne = jouer.num_acteur WHERE personne.nom = 'Depardieu' AND personne.prenom = 'Gérard') AND personne.nom != 'Depardieu' OR personne.prenom != 'Gérard';
SELECT DISTINCT nom, prenom FROM personne INNER JOIN film ON film.num_realisateur = personne.num_personne WHERE NOT EXISTS (SELECT * FROM film WHERE genre != 'Comédie' AND num_realisateur = num_personne);
SELECT num_realisateur FROM film GROUP BY num_personne HAVING COUNT(num_film) >= 5;
SELECT nom, prenom FROM personne INNER JOIN film ON film.num_realisateur = personne.num_personne GROUP BY nom, prenom HAVING COUNT(num_film) >= 5;
SELECT titre FROM film NATURAL JOIN jouer GROUP BY num_film, titre HAVING SUM(salaire) >= ALL (SELECT SUM(salaire) FROM film NATURAL JOIN jouer GROUP BY num_film);
SELECT DISTINCT j1.num_acteur, j2.num_acteur FROM jouer j1 INNER JOIN jouer j2 ON j1.num_film = j2.num_film WHERE j1.num_acteur < j2.num_acteur;

SELECT DISTINCT nom, prenom FROM personne INNER JOIN jouer ON personne.num_personne = jouer.num_acteur WHERE num_film != ALL (SELECT num_film FROM personne INNER JOIN film ON film.num_realisateur = personne.num_personne WHERE personne.nom != 'Tarantino' AND personne.prenom != 'Quentin');