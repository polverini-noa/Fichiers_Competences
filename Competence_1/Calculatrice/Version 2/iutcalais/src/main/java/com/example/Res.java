package com.example;

import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.text.Text;

public class Res extends VBox {
    public static TextField resultat;
    public static Float valeur1;
    public static String choix_operateur;
    public static Float calcul;

    public Res(VBox vbox2){   
        // Valeur pour afficher le résultat 
        var afficher_res = new Text();

        // 
        resultat = new TextField();
        resultat.setText("");

        // création des boutons calculer et effacer
        var hbox = new HBox();
        var button_calculer = new Button("Calculer");
        var button_clear = new Button("Effacer");

        // ajout de ces boutons dans la hbox 
        hbox.getChildren().add(button_calculer);
        hbox.getChildren().add(button_clear);
        hbox.setAlignment(Pos.CENTER);

        // ajout dans la vbox principal les éléments nécéssaires
        vbox2.getChildren().add(resultat);
        vbox2.getChildren().add(afficher_res);
        vbox2.getChildren().add(hbox);

        // Vérifie si le bouton plus est activé sur bouton plus : 
        Operateurs.button_plus.setOnAction(e -> {
            valeur1 = Float.parseFloat(resultat.getText()); // récupère la valeur du premier nombre pour le calcul
            choix_operateur = "plus";  // définis le choix comme plus pour savoir par la suite quel type de calcul nous devons faire
            Res.resultat.setText(""); // efface le text pour pouvoir rentrer la valeur 2 du calcul
        });
        // Ou bouton moins
        Operateurs.button_moins.setOnAction(e -> {
            valeur1 = Float.parseFloat(resultat.getText());
            choix_operateur = "moins";
            Res.resultat.setText("");
        });
        // Ou bouton muiltiplié
        Operateurs.button_mult.setOnAction(e -> {
            valeur1 = Float.parseFloat(resultat.getText());
            choix_operateur = "mult";
            Res.resultat.setText("");
        });
        // Ou bouton division
        Operateurs.button_div.setOnAction(e -> {
            valeur1 = Float.parseFloat(resultat.getText());
            choix_operateur = "div";
            Res.resultat.setText("");
        });

        // Calcul le résultat en fonction du type de calcul demander
        button_calculer.setOnAction(e -> {
            if (choix_operateur == "plus"){
                calcul = valeur1 + Float.parseFloat(resultat.getText());
            }
            if (choix_operateur == "moins"){
                calcul = valeur1 - Float.parseFloat(resultat.getText());
            }
            if (choix_operateur == "div"){
                calcul = valeur1 / Float.parseFloat(resultat.getText());
            }
            if (choix_operateur == "mult"){
                calcul = valeur1 * Float.parseFloat(resultat.getText());
            }
            afficher_res.setText("Résultat : " + String.valueOf(calcul)); 
        });

        // Efface le résultat et la valeur dans le text de calcul pour ne plus rien avoir d'afficher et pouvoir recommencer un calcul
        button_clear.setOnAction(e -> {
            Res.resultat.setText("");
            afficher_res.setText("");
        });
    }
}
