Bonjour!
Le cryptage password a été réalisé dans un Projet PHP de Benard Jules et Polverini Noa, voici les étapes si vous voulez essayer de lancer notre projet : (compliqué)

■■■■■■■■■■■■  Pour créer notre base de données colle ce bout de code dans une bdd: ■■■■■■■■■■■■  
		(ce code vient de laragon, laragon l'a généré automatiquement)

CREATE TABLE `utilisateur` (
	`nom_prenom` VARCHAR(50) NULL DEFAULT NULL COLLATE 'utf8mb4_0900_ai_ci',
	`email` VARCHAR(50) NULL DEFAULT NULL COLLATE 'utf8mb4_0900_ai_ci',
	`mot_de_passe` LONGTEXT NULL DEFAULT NULL COLLATE 'utf8mb4_0900_ai_ci',
	`colonne_token` LONGTEXT NULL DEFAULT NULL COLLATE 'utf8mb4_0900_ai_ci',
	`role` INT(10) NOT NULL DEFAULT '0'
)
COLLATE='utf8mb4_0900_ai_ci'
ENGINE=InnoDB
;


■■■■■■■■■■■■ Pour lancer notre projet : ■■■■■■■■■■■■ 

Installer laragon ou autres, démarrer le serveur aller sur l'adresse en dessous
pour laragon : 
http://localhost/Projet_final/login.php

Et créer vous un compte.



■■■■■■■■■■■■  Si vous voulez modifier votre mdp : ■■■■■■■■■■■■  

Dans le cmd de laragon :

composer require phpmailer/phpmailer
npm install -g maildev

Et enfin taper "maildev" pour lancer le serveur, allez ensuite sur cette adresse :
http://127.0.0.1:1080/#/

Et vous pouvez ensuite cliquer sur mot de passe oubliée, renseignez votre email
allez sur le mail recu et cliqué le lien dans le mail.

Vous pouvez désormais changez votre mot de passe, puis repartir à l'accueil pour vous connecter.



■■■■■■■■■■■■  Système de Roles fonctionnels ■■■■■■■■■■■■  

Pour avoir un role différent, dans la base de donnée, attribut toi 1 dans la colonne role et tu aura le role admin, 
une phrase en plus s'affichera pour te le prouver lorsque tu sera connecté.
