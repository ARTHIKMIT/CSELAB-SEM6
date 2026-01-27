//Q2

import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.canvas.*;
import javafx.scene.control.*;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class Q2ResumeApp extends Application {

    @Override
    public void start(Stage s) {
        TextField nameField = new TextField();
        nameField.setPromptText("Enter your name");

        TextField emailField = new TextField();
        emailField.setPromptText("Enter your email");

        TextField phoneField = new TextField();
        phoneField.setPromptText("Enter your phone number");

        CheckBox englishCheckbox = new CheckBox("English");
        CheckBox frenchCheckbox = new CheckBox("French");
        CheckBox germanCheckbox = new CheckBox("German");
        CheckBox spanishCheckbox = new CheckBox("Spanish");

        Button submitButton = new Button("Submit");

        Canvas canvas = new Canvas(400, 300);
        GraphicsContext gc = canvas.getGraphicsContext2D();

        submitButton.setOnAction(e -> {
            String name = nameField.getText();
            String email = emailField.getText();
            String phone = phoneField.getText();

            StringBuilder languages = new StringBuilder();
            if (englishCheckbox.isSelected()) languages.append("English ");
            if (frenchCheckbox.isSelected()) languages.append("French ");
            if (germanCheckbox.isSelected()) languages.append("German ");
            if (spanishCheckbox.isSelected()) languages.append("Spanish ");

            // Clear canvas and display resume details
            gc.clearRect(0, 0, canvas.getWidth(), canvas.getHeight());
            gc.fillText("Resume", 50, 30);
            gc.fillText("Name: " + name, 50, 60);
            gc.fillText("Email: " + email, 50, 90);
            gc.fillText("Phone: " + phone, 50, 120);
            gc.fillText("Languages: " + languages.toString(), 50, 150);
        });

        VBox layout = new VBox(10,
                new Label("Create Your Resume"),
                nameField, emailField, phoneField,
                new Label("Languages You Can Speak:"),
                englishCheckbox, frenchCheckbox, germanCheckbox, spanishCheckbox,
                submitButton, canvas
        );
        layout.setAlignment(Pos.CENTER);

        Scene scene = new Scene(layout, 400, 500);
        s.setScene(scene);
        s.setTitle("Resume Creator");
        s.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
