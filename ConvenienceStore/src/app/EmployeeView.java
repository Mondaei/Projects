package app;

import fromMCO1.*;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.VBox;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;

public class EmployeeView {

    public EmployeeView() {
    }

    // --- 1. LOGIN DIALOG ---
    public Dialog<EmployeeModel> createLoginDialog() {
        Dialog<EmployeeModel> dialog = new Dialog<>();
        dialog.setTitle("Employee Login");
        dialog.setHeaderText("Enter Employee Information");

        ButtonType loginButtonType = new ButtonType("Continue", ButtonBar.ButtonData.OK_DONE);
        dialog.getDialogPane().getButtonTypes().addAll(loginButtonType, ButtonType.CANCEL);

        GridPane grid = new GridPane();
        grid.setHgap(10);
        grid.setVgap(10);
        grid.setPadding(new Insets(20));

        TextField nameField = new TextField();
        nameField.setPromptText("Employee Name");
        TextField idField = new TextField();
        idField.setPromptText("Employee ID");

        grid.add(new Label("Name:"), 0, 0);
        grid.add(nameField, 1, 0);
        grid.add(new Label("ID:"), 0, 1);
        grid.add(idField, 1, 1);

        dialog.getDialogPane().setContent(grid);

        dialog.setResultConverter(dialogButton -> {
            if (dialogButton == loginButtonType) {
                return new EmployeeModel(nameField.getText(), idField.getText());
            }
            return null;
        });

        return dialog;
    }

    // --- 2. MENU SCENE (UPDATED WITH DELETE ALL) ---
    // --- 2. MENU SCENE (UPDATED WITH DELETE SINGLE AND DELETE ALL) ---
    public Scene createEmployeeMenuScene(EmployeeModel employee,
                                         EventHandler<ActionEvent> onViewProducts,
                                         EventHandler<ActionEvent> onAddProduct,
                                         EventHandler<ActionEvent> onRestock,
                                         EventHandler<ActionEvent> onUpdate,
                                         EventHandler<ActionEvent> onLowStock,
                                         EventHandler<ActionEvent> onDeleteProduct,  // NEW: Delete single
                                         EventHandler<ActionEvent> onDeleteAll,
                                         EventHandler<ActionEvent> onBack) {

        BorderPane root = new BorderPane();
        root.setPadding(new Insets(20));
        root.setStyle("-fx-background-color: #ecf0f1;");

        // Top: Employee info
        VBox topBox = new VBox(5);
        topBox.setAlignment(Pos.CENTER);
        Label welcomeLabel = new Label("Employee: " + employee.getName());
        welcomeLabel.setFont(Font.font("System", FontWeight.BOLD, 20));
        Label idLabel = new Label("ID: " + employee.getEmployeeId());
        topBox.getChildren().addAll(welcomeLabel, idLabel);
        root.setTop(topBox);

        // Center: Menu buttons
        VBox centerBox = new VBox(15);
        centerBox.setAlignment(Pos.CENTER);
        centerBox.setPadding(new Insets(30));

        Button viewProductsBtn = createMenuButton("View All Products");
        Button addProductBtn = createMenuButton("Add New Product");
        Button restockBtn = createMenuButton("Restock Product");
        Button updateProductBtn = createMenuButton("Update Product Info");
        Button lowStockBtn = createMenuButton("View Low Stock Items");
        Button deleteProductBtn = createMenuButton("🗑 Delete Product");  // NEW BUTTON
        Button deleteAllBtn = createMenuButton("⚠ Delete All Products");
        Button backBtn = createMenuButton("Back to Main Menu");

        // Special styling for delete buttons
        deleteProductBtn.setStyle("-fx-background-color: #e67e22; -fx-text-fill: white; -fx-font-size: 14px; -fx-font-weight: bold; -fx-min-width: 250px; -fx-min-height: 40px;");  // ORANGE
        deleteAllBtn.setStyle("-fx-background-color: #e74c3c; -fx-text-fill: white; -fx-font-size: 14px; -fx-font-weight: bold; -fx-min-width: 250px; -fx-min-height: 40px;");  // RED

        // Grey styling for back button
        backBtn.setStyle(backBtn.getStyle().replace("#3498db", "#95a5a6"));

        // Assign Actions
        viewProductsBtn.setOnAction(onViewProducts);
        addProductBtn.setOnAction(onAddProduct);
        restockBtn.setOnAction(onRestock);
        updateProductBtn.setOnAction(onUpdate);
        lowStockBtn.setOnAction(onLowStock);
        deleteProductBtn.setOnAction(onDeleteProduct);  // NEW ACTION
        deleteAllBtn.setOnAction(onDeleteAll);
        backBtn.setOnAction(onBack);

        centerBox.getChildren().addAll(
                viewProductsBtn,
                addProductBtn,
                restockBtn,
                updateProductBtn,
                lowStockBtn,
                deleteProductBtn,  // ADDED
                deleteAllBtn,
                backBtn
        );

        root.setCenter(centerBox);

        return new Scene(root, 600, 750);  // Increased height for new button
    }

    // Helper method for consistent button styling
    private Button createMenuButton(String text) {
        Button btn = new Button(text);
        btn.setPrefWidth(250);
        btn.setPrefHeight(40);
        btn.setStyle("-fx-background-color: #3498db; -fx-text-fill: white; -fx-font-size: 14px; -fx-font-weight: bold;");
        return btn;
    }
}