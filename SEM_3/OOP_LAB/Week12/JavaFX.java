package com;

import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.*;
import javafx.scene.layout.FlowPane;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

public class JavaFX extends Application {
    @Override
    public void start(Stage primaryStage) {
        FlowPane flowPane = new FlowPane(10, 10);

        Label label = new Label("Rectangle Size:");
        TextField widthField = new TextField("100");
        TextField heightField = new TextField("60");

        Canvas canvas = new Canvas(300, 200);
        GraphicsContext gc = canvas.getGraphicsContext2D();
        gc.setStroke(Color.BLACK);
        gc.setLineWidth(2);

        // fill the rectangle
        ToggleButton fillToggle = new ToggleButton("Fill");

        // Color Selection
        ObservableList<String> colors = FXCollections.observableArrayList("Red", "Blue", "Green");
        ComboBox<String> colorComboBox = new ComboBox<>(colors);
        colorComboBox.setValue("Red");

        // RadioButton for Rectangle Orientation
        ToggleGroup orientationGroup = new ToggleGroup();
        RadioButton horizontalButton = new RadioButton("Horizontal");
        RadioButton verticalButton = new RadioButton("Vertical");
        horizontalButton.setToggleGroup(orientationGroup);
        verticalButton.setToggleGroup(orientationGroup);
        horizontalButton.setSelected(true);

        // ObservableList for ListView (Actions Log)
        ObservableList<String> actions = FXCollections.observableArrayList("Actions:");
        ListView<String> actionList = new ListView<>(actions);

        Button drawButton = new Button("Draw");
        drawButton.setOnAction(e -> {
            // Clear canvas
            gc.clearRect(0, 0, canvas.getWidth(), canvas.getHeight());

            double width = Double.parseDouble(widthField.getText());
            double height = Double.parseDouble(heightField.getText());

            if (verticalButton.isSelected()) {
                double temp = width;
                width = height;
                height = temp;
            }

            // Get selected color
            Color color = switch (colorComboBox.getValue()) {
                case "Red" -> Color.RED;
                case "Blue" -> Color.BLUE;
                case "Green" -> Color.GREEN;
                default -> Color.BLACK;
            };
            gc.setStroke(color);
            gc.setFill(color);

            // Draw and optionally fill rectangle
            if (fillToggle.isSelected()) {
                gc.fillRect(50, 50, width, height);
            } else {
                gc.strokeRect(50, 50, width, height);
            }

            actions.add("Drew rectangle: " + (fillToggle.isSelected() ? "Filled" : "Outlined"));
        });

        flowPane.getChildren().addAll(
                label, widthField, heightField,
                canvas,
                fillToggle,
                colorComboBox,
                horizontalButton, verticalButton,
                drawButton,
                actionList
        );

        Scene scene = new Scene(flowPane, 800, 500);
        primaryStage.setScene(scene);
        primaryStage.setTitle("JavaFX in a nutshell");
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
