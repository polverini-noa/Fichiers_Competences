package com.example;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.geometry.Pos;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

/**
 * JavaFX App
 */
public class App extends Application {

    @Override
    public void start(Stage stage) {

        var stack = new VBox();
        stack.setScaleX(1);
        stack.setAlignment(Pos.CENTER);
        var scene = new Scene(stack, 144, 200);
        
    
        var FlowPane = new VBox();
        new Opérateurs(FlowPane);
        stack.getChildren().add(FlowPane);

        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }

}