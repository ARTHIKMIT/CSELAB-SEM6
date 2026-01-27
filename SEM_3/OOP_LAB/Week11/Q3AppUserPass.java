// Q3
import javafx.scene.control.*;
import javafx.application.*;
import javafx.scene.*;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.stage.*;
import javafx.geometry.*;
import javafx.event.*;

public class Q3AppUserPass extends Application {
	public void start(Stage s){
		//Setting the title to my app
		s.setTitle("JavaFX Welcome");

		GridPane root = new GridPane();
		root.setAlignment(Pos.CENTER);
		root.setHgap(10);
		root.setVgap(10);
		//padding property manages the space around the edges of the grid pane. 
		//insets are in the order of top, right, bottom, and left.
		root.setPadding(new Insets(25, 25, 25, 25));

		//Making a Label
		Label l1 = new Label();
		l1.setText("User Name : ");
		l1.setTextFill(Color.BLACK);
		root.add(l1, 0, 1);

		TextField username = new TextField();
		username.setPromptText("Name");
		root.add(username, 1, 1);

		Label l2 = new Label();
		l2.setText("Password : ");
		l2.setTextFill(Color.BLACK);
		root.add(l2, 0, 2);

		PasswordField password = new PasswordField();
		password.setPromptText("Password");
		root.add(password, 1, 2);

		Button b1 = new Button("Sign in");
		root.add(b1, 1, 4);
		Label response = new Label();
		root.add(response, 1, 5);		

		b1.setOnAction(new EventHandler<ActionEvent>() {
			public void handle(ActionEvent e) {
				if (username.getText() != null)
					response.setText("Welcome " + username.getText() + " !");
				else response.setText("Enter Valid Details!");
			}
		});

		//Creating a scene
		Scene myScene = new Scene(root, 500, 350);
		s.setScene(myScene);
		s.show();
	}
	public static void main(String[] args){
		launch(args);
	}
}