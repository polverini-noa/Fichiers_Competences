<!-- Fichier qui concerne la page pour changez le mdp -->

<?php 
require 'fonction.php';
session_start(); 
?>
<html>
    <head>
        <meta charset="utf-8">
        <!-- importer le fichier de style -->
        <link rel="stylesheet" href="style.css" media="screen" type="text/css" />
        <title>Se connecter</title>
    </head>
    <body>    
        <div class="container" id="container_login">
            <!-- zone de connexion -->
            <form action="" method="POST">
                <!-- TITRE -->
                <label><h1 id="titre_mdp">Changement de Mot de passe</h1></label>
                
                <!-- Champ mot de passe -->
                <label><b>Mot de passe</b></label>
                <input type="password" placeholder="Entrer le mot de passe" name="password" required>

                <!-- confirmation mot de passe -->
                <label><b> Confirmation Mot de passe</b></label>
                <input type="password" placeholder="Entrer le mot de passe" name="confirm_password" required>

                <!-- Bouton envoyer -->
                <input type="submit" id='submit' value='Envoyer' >

                <!-- Lien vers la page d'accueil pour se reconnecter -->
                <a href="login.php" id="mdp_forgot">Retour à la connexion</a>

                <?php
                    // connexion a la BDD
                    $db = Db::getInstance();
                    
                    // Si les champs de mdp et confirm mdp ne sont pas vide
                    if (isset($_POST['password']) != "" && isset($_POST['confirm_password']) != "") {
                        $password = $_POST['password'];
                        $confirm_password = $_POST['confirm_password'];

                        // si le password est égale au confirm_password alors
                        if ($password == $confirm_password) {
                            // cryptage du password
                            $password = password_hash($password, PASSWORD_BCRYPT);

                            // requete pour recuperer l'email de l'utilisateur en cours
                            $requete = "SELECT email FROM utilisateur where colonne_token LIKE '" . $_GET['token'] . "' ";
                            $exec_requete = mysqli_query($db, $requete);
                            $reponse = mysqli_fetch_array($exec_requete);

                            // requete numéro 2 pour actualiser le mot de passe avec le nouveau
                            $requete2 = "UPDATE utilisateur set mot_de_passe = '" . $password . "' where email = '" . $reponse[0] . "' ";
                            $exec_requete2 = mysqli_query($db, $requete2);
                            header('Location: maj_mdp.php');
                        }
                    }
                ?>
            </form>
        </div>
    </body>
</html>
