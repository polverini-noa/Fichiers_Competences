<!-- Fichier qui sert à afficher à la page que le mot de passe à bien été changer. -->

<html>
    <head>
        <meta charset="utf-8">
        <link rel="stylesheet" href="style.css" media="screen" type="text/css" />
        <title>Envoie Mail Validé</title>
    </head>
 <body>
    <div class="container" id="container_login">
        <form action="mail.php" id="form1" method="POST">
            <h2 id="">Votre mot de passe a été changé ! &#10003;</h2>
            <a href="login.php" id="mdp_forgot">Retour à la connexion</a>
        </form>
    </div>
 </body>
</html>