<!-- Fichier qui contiens les fonctions nécéssaires -->

<?php
  class Db {
    private static $db;

    public static function getInstance() {
      if (self::$db === null) {
        // connexion à la base de données
        $db_username = 'root';
        $db_password = '';
        $db_name = 'bdd';
        $db_host = 'localhost';
        self::$db = mysqli_connect($db_host, $db_username, $db_password, $db_name) or die('could not connect to database');
      }
      return self::$db;
    }

    // fonction pour créer aléatoirement le token
    public static function creer_token($length = 20) {
      $chars = '0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ';
      $string = '';
      for ($i = 0; $i < $length; $i++) {
        $string .= $chars[rand(0, strlen($chars) - 1)];
      }
      return $string;
    }
  }
?>