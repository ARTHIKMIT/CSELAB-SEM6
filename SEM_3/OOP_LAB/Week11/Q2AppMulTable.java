// Q2
import javafx.scene.control.*;
import javafx.application.*;
import javafx.scene.*;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import javafx.geometry.Pos;

public class Q2AppMulTable extends Application {
	public void start(Stage s){
		//Setting the title to my app
		s.setTitle("Multiplacation Table. ");

		//Making a Label
		Label l1 = new Label();
		l1.setText("Enter an integer : ");
		l1.setTextFill(Color.BLUE);

		TextField box = new TextField();
		box.setPromptText("Number");

		Button b1 = new Button("Generate Table");
		Label response = new Label();

		FlowPane root = new FlowPane(50, 10);
		root.getChildren().addAll(l1, box, b1, response);
		root.setAlignment(Pos.CENTER);

		//FlowPane BottomBox = new FlowPane(10, 10);
		//BottomBox.getChildren().addAll(response);
		//BottomBox.setAlignment(Pos.BOTTOM_CENTER);

		//Root Node with vertical and horizontal gaps of 10
		//FlowPane root = new FlowPane(10, 10);
		//root.setAlignment(Pos.CENTER);

		b1.setOnAction(e -> {
			try {
				int num = Integer.parseInt(box.getText());
				String res = "";
				for (int i = 1; i <=10; i++)
					res += i + "x" + num + " = " + i*num + "\n";
				response.setText(res);
			}
			catch (NumberFormatException exc){
				response.setText("Enter a Valid integer");
			}
		});

		//root.getChildren().addAll(l1, box, b1, response); //addAll(a, b, c)
		//root.getChildren().addAll(TopBox, BottomBox);
		//Creating a scene
		Scene myScene = new Scene(root, 500, 350);
		s.setScene(myScene);
		s.show();
	}
	public static void main(String[] args){
		launch(args);
	}
}