SELECT perso1.nom FROM (SELECT nom FROM personnels WHERE qualif = 'INFIRMIERE') AS perso1 INNER JOIN (SELECT nom FROM personnels WHERE qualif = 'SECRETAIRE MEDICALE') AS perso2 ON perso1.nom = perso2.nom;
SELECT perso.nom, perso.prenom FROM (SELECT nom, prenom FROM personnels) AS perso INNER JOIN (SELECT nom, prenom FROM patients) AS pats ON perso.nom = pats.nom;
SELECT nom, prenom FROM personnels WHERE qualif = 'SECRETAIRE MEDICALE' AND (nom, prenom) NOT IN (SELECT nom, prenom FROM patients);
SELECT perso.codpers, perso.nom, perso.prenom, perso.qualif, perso.codsup, sup.qualif FROM (SELECT * FROM personnels WHERE qualif = 'ASSISTANT' OR qualif = 'CHEF DE CLINIQUE') AS perso INNER JOIN (SELECT * FROM personnels) AS sup ON perso.codsup = sup.codpers;
SELECT personnels.nom, prenom, sx, datnais, services.nom FROM personnels INNER JOIN services ON personnels.codserv = services.codserv WHERE qualif = 'CHEF DE SERVICE';
SELECT serv.nom, perso.nom, perso.prenom, perso.sx FROM (SELECT  DISTINCT nom, codserv FROM services) AS serv LEFT JOIN (SELECT * FROM personnels) AS perso ON perso.codserv = serv.codserv;
SELECT codserv, nom FROM services WHERE codserv NOT IN (SELECT codserv FROM personnels);
SELECT serv.nom, perso.nom, perso.prenom, perso.sx FROM (SELECT  DISTINCT nom, codserv FROM services) AS serv LEFT JOIN (SELECT * FROM personnels WHERE qualif = 'CHEF DE SERVICE') AS perso ON perso.codserv = serv.codserv;
SELECT serv.nom, COALESCE(perso.nom, '*****'), COALESCE(perso.prenom, '*****'), COALESCE(perso.sx, '*****') FROM (SELECT  DISTINCT nom, codserv FROM services) AS serv LEFT JOIN (SELECT * FROM personnels WHERE qualif = 'CHEF DE SERVICE') AS perso ON perso.codserv = serv.codserv;