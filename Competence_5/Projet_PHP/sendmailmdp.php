<!-- Fichier qui demande le mail ou il faut envoyer le mail pour recevoir le lien de changement de mot de passe -->
<html>
    <head>
        <meta charset="utf-8">
        <link rel="stylesheet" href="style.css" media="screen" type="text/css" />
        <title>Se connecter - Amazon</title>
    </head>
    <body>
        <div class="container" id="container_login">
            <form action="mail.php" id="form1" method="POST">
                <!-- titre -->
                <label><h1>Envoyer un mail de confirmation</h1></label>
                
                <!-- zone pour mettre son mail -->
                <label><b>Email</b></label>
                <input type="email" placeholder="Entrer l'email" name="email" required>

                <!-- bouton pour envoyer le mail -->
                <input type="submit" id='submit' value='Envoyer' >

                <!-- bouton retour a la connexion -->
                <a href="login.php" id="mdp_forgot">Retour à la connexion</a>
            </form>
        </div>
    </body>
</html>