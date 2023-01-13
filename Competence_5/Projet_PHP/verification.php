<!-- Fichier qui sert a vérifier si la connexion peut etre établis ou non -->

<?php
require 'fonction.php';
session_start();

// si les champs ne sont pas vides
if(isset($_POST['username']) && isset($_POST['password'])) {
    // connexion à la base de données
    $db = Db::getInstance();

    // on applique les deux fonctions mysqli_real_escape_string et htmlspecialchars
    // pour éliminer toute attaque de type injection SQL et XSS
    $username = mysqli_real_escape_string($db,htmlspecialchars($_POST['username'])); 
    $password = mysqli_real_escape_string($db,htmlspecialchars($_POST['password']));
 
    if($username !== "" && $password !== "") {
        // Permet de récupérer le mdp 
        $requete = "SELECT * FROM utilisateur where email = '".$username."'";
        $exec_requete = mysqli_query($db,$requete);
        $reponse = mysqli_fetch_array($exec_requete);
        $passwordHash = $reponse['mot_de_passe'];

        // vérification si le mot de passe mis correspond bien au mdp hacher enregistrer dans la BDD
        if (password_verify($password, $passwordHash)){
            $_SESSION['username'] = $username;
            header('Location: principale.php');
                return;
        }
        header('Location: login.php');
    }
}
mysqli_close($db); // fermer la connexion
?>