// Q1
import javafx.scene.control.*;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

public class Q1App extends Application {
	public void start(Stage s){
		//Setting the title to my app
		s.setTitle("This is the First JavaFX Application ;) ");

		//Making a Label
		Label l1 = new Label();
		l1.setText("Welcome to JavaFX programming");
		l1.setTextFill(Color.MAGENTA);

		//Root Node with vertical and horizontal gaps of 10
		FlowPane root = new FlowPane(10, 10);
		root.getChildren().add(l1);

		//Creating a scene
		Scene myScene = new Scene(root, 500, 200);
		s.setScene(myScene);
		s.show();
	}
	public static void main(String[] args){
		launch(args);
	}
}