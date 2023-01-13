package com.example;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.geometry.Pos;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

/**
 * JavaFX App
 */
public class App extends Application {

    @Override
    public void start(Stage stage) {
        // définition des caractéristiques de l'application
        var stack = new VBox();
        stack.setScaleX(1);
        stack.setAlignment(Pos.CENTER);  // permet de centrer la box
        var scene = new Scene(stack, 250, 300);
        
        // Hbox correspondant aux bouttons des chiffres
        var hbox = new HBox();
        hbox.setAlignment(Pos.CENTER);  // permet de centrer la box
        new Numbers(hbox);
        stack.getChildren().add(hbox);

        // Vbox correspondant aux boutons des opérateurs
        var vbox = new VBox();
        new Operateurs(vbox);
        stack.getChildren().add(vbox);

        // Vbox2 correspondant aux résultats (bouton calculer et clear + afficher le résultat)
        var vbox2 = new VBox();
        new Res(vbox2);
        stack.getChildren().add(vbox2);

        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }

}