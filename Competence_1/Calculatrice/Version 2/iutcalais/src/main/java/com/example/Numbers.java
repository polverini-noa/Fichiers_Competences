package com.example;

import javafx.scene.control.Button;
import javafx.scene.layout.HBox;


public class Numbers {
    public Numbers(HBox hbox){
        // Boucle pour aller de 0 à 9
        for (int i = 0; i < 10; i++) {
            var local_i = i;  // rédéfinition de i car sinon on ne peut pas l'utiliser à la ligne en dessous
            var button = new Button(String.valueOf(i));  // création du bouton 

            // création de l'évènement sur les boutons pour que quand on clique sa ajoute la valeur du bouton au calcul
            button.setOnAction(e -> { 
                var text = Res.resultat.getText(); // récupération du contenu du text
                text = text + String.valueOf(local_i);  // ajout au text la valeur du bouton qui a été cliqué
                Res.resultat.setText(text);  // redéfinis la valeur du text par la nouvelle valeur
            });
            
            hbox.getChildren().add(button); // ajout le bouton à la Hbox principal
        }
    }
}