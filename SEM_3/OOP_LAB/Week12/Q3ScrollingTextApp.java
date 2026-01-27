//Q3
import javafx.application.Application;
import javafx.application.Platform;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.RadioButton;
import javafx.scene.control.ToggleGroup;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class Q3ScrollingTextApp extends Application {
    private Label messageLabel;
    private boolean scrolling = false;

    @Override
    public void start(Stage primaryStage) {
        messageLabel = new Label("Scrolling Message");
        messageLabel.setStyle("-fx-font-size: 16px;");

        RadioButton leftToRight = new RadioButton("Left to Right");
        RadioButton rightToLeft = new RadioButton("Right to Left");
        ToggleGroup directionGroup = new ToggleGroup();
        leftToRight.setToggleGroup(directionGroup);
        rightToLeft.setToggleGroup(directionGroup);

        Button startButton = new Button("Start Scrolling");
        startButton.setOnAction(e -> {
            if (directionGroup.getSelectedToggle() != null) {
                startScrolling(leftToRight.isSelected());
            }
        });

        Button stopButton = new Button("Stop Scrolling");
        stopButton.setOnAction(e -> stopScrolling());

        VBox layout = new VBox(10, messageLabel, leftToRight, rightToLeft, startButton, stopButton);
        layout.setAlignment(Pos.CENTER);

        Scene scene = new Scene(layout, 400, 200);
        primaryStage.setTitle("Scrolling Text App");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    private void startScrolling(boolean leftToRight) {
        if (scrolling) return;
        scrolling = true;

        new Thread(() -> {
            while (scrolling) {
                Platform.runLater(() -> scrollMessage(leftToRight));
                try {
                    Thread.sleep(100);
                } catch (InterruptedException ex) {
                    ex.printStackTrace();
                }
            }
        }).start();
    }

    private void scrollMessage(boolean leftToRight) {
        String text = messageLabel.getText();
        if (leftToRight) {
            text = text.substring(1) + text.charAt(0);
        } else {
            text = text.charAt(text.length() - 1) + text.substring(0, text.length() - 1);
        }
        messageLabel.setText(text);
    }

    public void stopScrolling() {
        scrolling = false;
    }

    @Override
    public void stop() {
        stopScrolling();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
