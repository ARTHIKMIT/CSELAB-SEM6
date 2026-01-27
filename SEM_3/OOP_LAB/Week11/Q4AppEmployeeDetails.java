// Q4

import javafx.scene.control.*;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import javafx.geometry.*;
import javafx.event.*;

class Employee {
	String name, designation;
	int empID, basicPay;
	double DA, HRA, PF, LIC, netSalary;
	Employee(int bpay, String n, String d, int id){
		name = n;
		designation = d;
		basicPay = bpay;
		empID = id;
	}
	void compute(){
		DA = 0.4 * basicPay;
		HRA = 0.15 * basicPay;
		PF = 0.12 * basicPay;
		LIC = 0;
		netSalary = basicPay + DA + HRA - PF - LIC;
	}
}


public class Q4AppEmployeeDetails extends Application {
	public void start(Stage s){
		//Setting the title to my app
		s.setTitle("Employee Details ;) ");

		GridPane root = new GridPane();
		root.setAlignment(Pos.CENTER);
		root.setHgap(10);
		root.setVgap(10);
		//padding property manages the space around the edges of the grid pane. 
		//insets are in the order of top, right, bottom, and left.
		root.setPadding(new Insets(25, 25, 25, 25));

		//Making Labels
		Label eIdL = new Label("E ID: ");
		///Col, Row
		root.add(eIdL, 0, 1);

		TextField eIdF = new TextField();
		eIdF.setPromptText("000");
		root.add(eIdF, 1, 1);

		Label nameL = new Label("Name : ");
		root.add(nameL, 0, 2);

		TextField nameF = new TextField();
		nameF.setPromptText("Gitaansh");
		root.add(nameF, 1, 2);

		Label designationL = new Label("Designation : ");
		root.add(designationL, 0, 3);

		TextField designationF = new TextField();
		designationF.setPromptText("Software Engineer");
		root.add(designationF, 1, 3);

		Label basicPayL = new Label("Basic Pay : ");
		root.add(basicPayL, 0, 4);

		TextField basicPayF = new TextField();
		basicPayF.setPromptText("Salary");
		root.add(basicPayF, 1, 4);

		Button compute = new Button("Compute");
		root.add(compute, 2, 4);

		Label netSalary = new Label();
		root.add(netSalary, 0, 8);	

		compute.setOnAction(e -> {
			try {
				int bpay = Integer.parseInt(basicPayF.getText());
				int id = Integer.parseInt(eIdF.getText());
				String name = nameF.getText();
				String designation = designationF.getText();
				Employee emp = new Employee(bpay, name, designation, id);
				emp.compute();
				
				Label eIdDisplayL = new Label("E ID : "+emp.empID);
				root.add(eIdDisplayL, 0, 5);	
				
				Label nameDisplayL = new Label("Name : "+emp.name);
				root.add(nameDisplayL, 0, 6);	

				Label designationDisplayL = new Label("Designation : "+emp.designation);
				root.add(designationDisplayL, 0, 7);	

				netSalary.setText("Net Salary : "+emp.netSalary);
			}
			catch (NumberFormatException exc){
				netSalary.setText("Enter a Valid integer");
			}
		});

		//Creating a scene
		Scene myScene = new Scene(root, 550, 550);
		s.setScene(myScene);
		s.show();
	}
	public static void main(String[] args){
		launch(args);
	}
}
