package com.example;

import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.control.ToggleButton;
import javafx.scene.layout.FlowPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.text.Text;


public class Opérateurs {

    public Opérateurs(VBox hbox){

        var ligne1 = new FlowPane();
        var button_div = new ToggleButton("/");
        var button_mult = new ToggleButton("X");
        button_div.setMinWidth(70);
        button_mult.setMinWidth(70);
        ligne1.getChildren().add(button_div);
        ligne1.getChildren().add(button_mult);
        hbox.getChildren().add(ligne1);

        var ligne2 = new FlowPane();
        var button_plus = new ToggleButton("+");
        var button_moins = new ToggleButton("-");
        button_plus.setMinWidth(70);
        button_moins.setMinWidth(70);
        ligne2.getChildren().add(button_plus);
        ligne2.getChildren().add(button_moins);
        hbox.getChildren().add(ligne2);

        var ligne3 = new HBox();
        var text1 = new TextField();
        var text2 = new TextField();
        text1.setMaxWidth(70);
        text2.setMaxWidth(70);
        ligne3.getChildren().add(text1);
        ligne3.getChildren().add(text2);
        hbox.getChildren().add(ligne3);

        var ligne4 = new FlowPane();
        var button_calculer = new Button("Calculer");
        var button_effacer = new Button("Effacer");
        button_calculer.setMinWidth(70);
        button_effacer.setMinWidth(70);
        ligne4.getChildren().add(button_calculer);
        ligne4.getChildren().add(button_effacer);
        hbox.getChildren().add(ligne4);


        var ligne_resultat = new VBox();
        var res = new Text();
        res.setText("");
        ligne_resultat.getChildren().add(res);
        hbox.getChildren().add(ligne_resultat);
        
        button_calculer.setOnAction(e -> {
            if (button_plus.isSelected()) {
                Integer resultat = Integer.parseInt(text1.getText())+Integer.parseInt(text2.getText());
                res.setText(String.valueOf("Résultat : " + resultat));
            }
            else if (button_moins.isSelected()) {
                Integer resultat = Integer.parseInt(text1.getText())-Integer.parseInt(text2.getText());
                res.setText(String.valueOf("Résultat : " +resultat));
            }
            else if (button_div.isSelected()) {
                Integer resultat = Integer.parseInt(text1.getText())/Integer.parseInt(text2.getText());
                res.setText(String.valueOf("Résultat : " +resultat));
            }
            else if (button_mult.isSelected()) {
                Integer resultat = Integer.parseInt(text1.getText())*Integer.parseInt(text2.getText());
                res.setText(String.valueOf("Résultat : " +resultat));
            }
        });

        button_effacer.setOnAction(e -> {
            res.setText("");
        });
    }
}
