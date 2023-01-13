<!-- Fichier qui sert à créer un nouveau compte -->

<html>
    <head>
        <meta charset="utf-8">
        <!-- importer le fichier de style -->
        <link rel="stylesheet" href="style.css" media="screen" type="text/css" />
        <title>Créer un compte</title>
    </head>
    <body>
        <div class="container" id="container_create_account">
            <!-- zone de création de compte -->
            <form action="verificationcreateaccount.php" method="POST">
                <!-- Titre -->
                <h1>Inscription</h1>

                <!-- Champ pour le nom et le prénom -->
                <label><b>Nom et Prénom</b></label>
                <input type="text" placeholder="Entrez votre nom et prénom" name="name_surname" required>

                <!-- champ pour rentrer l'adresse email -->
                <label><b>E-Mail</b></label>
                <input type="email" placeholder="Entrez votre email" name="username" required>

                <!-- champ pour rentrer le mot de passe -->
                <label><b>Mot de passe</b></label>
                <input type="password" placeholder="Entrez votre mot de passe" name="password" required>

                <!-- Bouton envoyer -->
                <input type="submit" id='submit' value='Envoyer' name="Envoyer" >

                <!-- Bouton pour revenir a la page connexion -->
                <h2>Tu as déjà un compte?</h2>
                <a href="login.php" class="bouton">Connecte-toi</a>
            </form>
        </div>
    </body>
</html>
