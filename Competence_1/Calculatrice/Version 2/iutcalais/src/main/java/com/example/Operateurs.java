package com.example;

import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.layout.FlowPane;
import javafx.scene.layout.VBox;


public class Operateurs {
    // passage des boutons en static car on en aura besoin dans d'autre classe
    public static Button button_plus ;
    public static Button button_moins ;
    public static Button button_div ;
    public static Button button_mult ;

    public Operateurs(VBox hbox){
        // ligne correspond à une FlowPane regroupant tous les opérateurs de calculs
        var ligne = new FlowPane();

        // redéfinition des boutons
        button_div = new Button("/");
        button_mult = new Button("X");
        button_plus = new Button("+");
        button_moins = new Button("-");

        // Défintion de leur taille 
        button_div.setMaxWidth(20);
        button_mult.setMaxWidth(20);
        button_plus.setMinWidth(22);
        button_moins.setMaxWidth(20);

        // ajout des 4 boutons au FlowPane
        ligne.getChildren().add(button_div);
        ligne.getChildren().add(button_mult);
        ligne.getChildren().add(button_plus);
        ligne.getChildren().add(button_moins);

        // Centrage de la FlowPane
        ligne.setAlignment(Pos.CENTER);

        // Ajout à la Hbox principal
        hbox.getChildren().add(ligne);
    }
}
