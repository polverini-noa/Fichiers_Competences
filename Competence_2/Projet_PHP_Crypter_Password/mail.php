<!-- Fichier qui envoie le mail et indique à l'écran que le mail à été envoyé. -->

<html>
    <head>
        <meta charset="utf-8">
        <link rel="stylesheet" href="style.css" media="screen" type="text/css" />
        <title>Envoie Mail Validé</title>
    </head>
    <body>
        <div class="container" id="container_login">
            <form action="mail.php" id="form1" method="POST">
                <h2 id="">Votre Mail a été envoyé ! &#10003;</h2>
            </form>
        </div>
    </body>
</html>


<?php

// cette ligne est nécéssaire ce fichier pour pouvoir appeler les fonctions à l'intérieur
require 'fonction.php';

// Import du PHPMailer pour recevoir des mails localement
use PHPMailer\PHPMailer\PHPMailer;
use PHPMailer\PHPMailer\SMTP;
use PHPMailer\PHPMailer\Exception;

// Charge les composants pour le mail
require 'vendor/autoload.php';

// connexion à la BDD
$db = Db::getInstance();

// création du mail
$mail = new PHPMailer(true);

try {
    
    // Paramètres du serveurs
    $mail->isSMTP();                                           
    $mail->Host = 'localhost';                    
    $mail->Port = 1025;                                   

    // Expéditeur et destinataires
    $mail->setFrom('noa_jules@iut.fr', 'Noa et Jules');
    $mail->addAddress($_POST['email']);   

    // Récupération du Token
    $requete = "SELECT colonne_token FROM utilisateur where email LIKE '" . $_POST['email'] . "' ";
    $exec_requete = mysqli_query($db, $requete);
    $reponse = mysqli_fetch_array($exec_requete);

    // Création du lien href pour dans le mail créer une redirection vers la page changer mdp 
    $lien = "http://localhost/Projet_final/changemdp.php?token=" . $reponse[0];

    // Contenu mail
    $mail->isHTML(true);                             
    $mail->Subject = 'Renitialisation mot de passe';  // Titre du mail                                                                        Contenu du mail avec ici une balise html <a> pour créer la redirection vers notre lien créer précédemment                                                                                            
    $mail->Body = 'Bonjour, <br> <br> Vous avez recemment effectuee une demande de renitialisation de votre mot de passe sur notre site. <br> Veuillez cliquez <a href="'.$lien.'" >ici</a> pour changer votre mot de passe. <br><br> La direction.';
    $mail->AltBody = 'This is the body in plain text for non-HTML mail clients';

    // Envoi du mail
    $mail->send();
}   

catch (Exception $e) {
    echo "Message could not be sent. Mailer Error: {$mail->ErrorInfo}";
}