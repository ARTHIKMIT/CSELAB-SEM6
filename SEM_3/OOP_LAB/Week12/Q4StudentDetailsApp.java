//Q4

import javafx.application.Application;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class Q4StudentDetailsApp extends Application {

    private ListView<Student> studentListView;
    private Label nameLabel, idLabel, courseLabel, gradeLabel;

    @Override
    public void start(Stage primaryStage) {
        ObservableList<Student> studentList = FXCollections.observableArrayList(
            new Student(101, "John Doe", "Computer Science", "A"),
            new Student(102, "Jane Smith", "Computer Science", "B+"),
            new Student(103, "Bob Johnson", "Computer Science", "C"),
            new Student(104, "Sara Lee", "Computer Science", "A-")
        );

        studentListView = new ListView<>(studentList);
        studentListView.setCellFactory(listView -> new StudentListCell());
        studentListView.getSelectionModel().selectedItemProperty().addListener(
            (observable, oldValue, newValue) -> displayStudentDetails(newValue)
        );

        nameLabel = new Label();
        idLabel = new Label();
        courseLabel = new Label();
        gradeLabel = new Label();

        VBox detailsBox = new VBox(10, nameLabel, idLabel, courseLabel, gradeLabel);
        detailsBox.setPadding(new Insets(20));

        BorderPane root = new BorderPane();
        root.setLeft(studentListView);
        root.setCenter(detailsBox);

        Scene scene = new Scene(root, 600, 400);
        primaryStage.setScene(scene);
        primaryStage.setTitle("Student Details");
        primaryStage.show();
    }

    private void displayStudentDetails(Student student) {
        nameLabel.setText("Name: " + student.name);
        idLabel.setText("ID: " + student.id);
        courseLabel.setText("Course: " + student.course);
        gradeLabel.setText("Grade: " + student.grade);
    }

    public static void main(String[] args) {
        launch(args);
    }
}

class Student {
    public int id;
    public String name;
    public String course;
    public String grade;

    public Student(int id, String name, String course, String grade) {
        this.id = id;
        this.name = name;
        this.course = course;
        this.grade = grade;
    }
}

class StudentListCell extends javafx.scene.control.ListCell<Student> {
    @Override
    protected void updateItem(Student student, boolean empty) {
        super.updateItem(student, empty);
        if (empty || student == null) {
            setText(null);
        } else {
            setText(student.id + " - " + student.name);
        }
    }
}
