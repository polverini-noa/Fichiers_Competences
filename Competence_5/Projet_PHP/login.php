<!-- Fichier qui sert à afficher la page pour se connecter -->

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
            <form action="verification.php" method="POST">
                <!-- Titre -->
                <h1>Connexion</h1>
                
                <!-- champ pour l'email -->
                <label><b>Email</b></label>
                <input type="email" placeholder="Entrer l'email" name="username" required>

                <!-- champ pour le mot de passe -->
                <label><b>Mot de passe</b></label>
                <input type="password" placeholder="Entrer le mot de passe" name="password" required>

                <!-- bouton qui redirige vers une page pour recuperer le mdp -->
                <a href="sendmailmdp.php" id="mdp_forgot">Mot de passe oublié ?</a>

                <!-- bouton pour se connecter -->
                <input type="submit" id='submit' value='Se connecter' >

                <!-- bouton pour se créer un compte si l'utilisateur n'en a pas -->
                <a href="createaccount.php?creercompte=true" class="bouton" id="button_new_account">Créer un compte</a> 
            </form>
        </div>
    </body>
</html>