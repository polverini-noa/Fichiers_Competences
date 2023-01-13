<!-- Fichier principal qui affiche à l'écran la page du site une fois que l'utilisateur est connecté, d'ailleurs cette page affiche une phrase
en plus si le role de l'utilisateur vaut 1 (admin) dans la base de données  -->

<html>
    <head>
        <meta charset="utf-8">
        <link rel="stylesheet" href="style.css" media="screen" type="text/css" />
        <title>Accueil</title>
    </head>

    <body class="background">
        <div id="content">
            <a href='principale.php?deconnexion=true'>
                <span>Déconnexion</span>
            </a>

            <?php
                $db = new PDO('mysql:host=localhost;dbname=bdd;charset=utf8', 'root', '');

                session_start();
                $sqlQuery = "SELECT * FROM utilisateur WHERE email LIKE '".$_SESSION['username']."'";
                $gensStatement = $db->prepare($sqlQuery);
                $gensStatement ->execute();
                $gens = $gensStatement ->fetchAll();
                
                foreach ($gens as $personne) {
                    $role = $personne['role'];
                    $email= $personne['email'];
                    $nom_prenom = $personne['nom_prenom'];
            
                    // Si dans la BDD, le role est de 1 alors on affiche ce titre.
                    if($role == 1){
                        ?><h1>Bienvenue, tu dispose des roles admin !</h1>
                    <?php
                    }
                    ?>

                    <?php echo "<br>Bonjour $nom_prenom <br> Votre mail : $email";
                }
                
                if(isset($_GET['deconnexion'])) { 
                    if($_GET['deconnexion']==true) { 
                        session_unset();
                        header("location:login.php");
                    }
                }
                
                else if($_SESSION['username'] !== "") {
                    $user = $_SESSION['username'];
                    // afficher un message
                    echo "<br>Bonjour $user, vous êtes connectés";
                }
                    ?>
        </div>
    </body>
</html>