<!-- Fichier qui sert à vérifier si on peut créer le compte ou pas -->

<?php
session_start();
require "fonction.php";

if(isset($_POST['name_surname']) && isset($_POST['username'])&& isset($_POST['password'])) {
   // connexion à la base de données
   $db = Db::getInstance();

   // on applique les deux fonctions mysqli_real_escape_string et htmlspecialchars
   // pour éliminer toute attaque de type injection SQL et XSS
   $name_surname = mysqli_real_escape_string($db,htmlspecialchars($_POST['name_surname'])); 
   $username = mysqli_real_escape_string($db,htmlspecialchars($_POST['username'])); 
   $password = mysqli_real_escape_string($db,htmlspecialchars($_POST['password']));
 
   // si le bouton créer le compte est enclenché alors
   if (isset($_POST['Envoyer'])) {
      // récupération des données nécéssaires
      $name_surname = $_POST['name_surname'];
      $username = $_POST['username'];
      $pswd = $_POST['password'];
      $password = password_hash($pswd, PASSWORD_BCRYPT);
      $token = Db::creer_token(20);

      // insert dans la BDD le nouvel utilisateur
      $requete = "INSERT INTO utilisateur values('$name_surname','$username','$password', '$token', 0)";
      $result = $db->prepare($requete)->execute();
   }

   if( $name_surname !== "" && $username !== "" && $password !== "") {
      $requete = "SELECT count(*) FROM utilisateur where nom_prenom= '".$name_surname."' and email = '".$username."' and mot_de_passe = '".$password."' ";
      $exec_requete = mysqli_query($db,$requete);
      $reponse = mysqli_fetch_array($exec_requete);
      $count = $reponse['count(*)'];
      if($count!=0) {
         $_SESSION['username'] = $username;
         header('Location: principale.php');
      }
      else {
         header('Location: createaccount.php');
      }
   }
}
mysqli_close($db); // fermer la connexion
?>

