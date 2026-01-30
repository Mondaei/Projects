package app;

import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.VBox;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;

public class ConvenienceStoreView {

    /**
     * Creates the Main Menu Scene.
     * @param onCustomerAction Action to run when "Customer Mode" is clicked.
     * @param onEmployeeAction Action to run when "Employee Mode" is clicked.
     * @param onExitAction Action to run when "Exit" is clicked.
     * @return The constructed Scene.
     */
    public Scene createContent(Runnable onCustomerAction, Runnable onEmployeeAction, Runnable onExitAction) {
        VBox root = new VBox(20);
        root.setAlignment(Pos.CENTER);
        root.setPadding(new Insets(50));
        root.setStyle("-fx-background-color: #f0f0f0;");

        Label titleLabel = new Label("CONVENIENCE STORE SYSTEM");
        titleLabel.setFont(Font.font("System", FontWeight.BOLD, 28));
        titleLabel.setStyle("-fx-text-fill: #2c3e50;");

        Button customerBtn = createStyledButton("Customer Mode", "#3498db");
        Button employeeBtn = createStyledButton("Employee Mode", "#3498db");
        Button exitBtn = createStyledButton("Save & Exit", "#e74c3c");

        // Bind Actions
        customerBtn.setOnAction(e -> onCustomerAction.run());
        employeeBtn.setOnAction(e -> onEmployeeAction.run());
        exitBtn.setOnAction(e -> onExitAction.run());

        root.getChildren().addAll(titleLabel, customerBtn, employeeBtn, exitBtn);

        return new Scene(root);
    }

    private Button createStyledButton(String text, String colorHex) {
        Button btn = new Button(text);
        btn.setStyle("-fx-font-size: 16px; -fx-min-width: 250px; -fx-min-height: 50px; " +
                "-fx-background-color: " + colorHex + "; -fx-text-fill: white; " +
                "-fx-background-radius: 5; -fx-cursor: hand;");
        return btn;
    }
}