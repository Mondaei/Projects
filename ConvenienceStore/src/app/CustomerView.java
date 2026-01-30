package app;

import fromMCO1.CustomerModel;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.VBox;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;

public class CustomerView {

    public CustomerView() {
    }

    // --- 1. Login Dialog ---
    public Dialog<CustomerModel> createLoginDialog() {
        Dialog<CustomerModel> dialog = new Dialog<>();
        dialog.setTitle("Customer Login");
        dialog.setHeaderText("Enter Customer Information");

        ButtonType loginButtonType = new ButtonType("Continue", ButtonBar.ButtonData.OK_DONE);
        dialog.getDialogPane().getButtonTypes().addAll(loginButtonType, ButtonType.CANCEL);

        GridPane grid = new GridPane();
        grid.setHgap(10);
        grid.setVgap(10);
        grid.setPadding(new Insets(20));

        TextField nameField = new TextField();
        nameField.setPromptText("Customer Name");
        CheckBox seniorCheck = new CheckBox("I am a senior citizen");

        grid.add(new Label("Name:"), 0, 0);
        grid.add(nameField, 1, 0);
        grid.add(seniorCheck, 1, 1);

        dialog.getDialogPane().setContent(grid);

        // Convert the result to a CustomerModel when the login button is clicked.
        dialog.setResultConverter(dialogButton -> {
            if (dialogButton == loginButtonType) {
                return new CustomerModel(nameField.getText(), seniorCheck.isSelected());
            }
            return null;
        });

        return dialog;
    }

    // --- 2. Menu Scene (Updated for MVC) ---
    // Instead of doing logic here, we ask for the actions to be passed in.
    public Scene createCustomerMenuScene(CustomerModel customer,
                                         EventHandler<ActionEvent> onViewProducts,
                                         EventHandler<ActionEvent> onAddToCart,
                                         EventHandler<ActionEvent> onViewCart,
                                         EventHandler<ActionEvent> onRemove,
                                         EventHandler<ActionEvent> onViewTotal,
                                         EventHandler<ActionEvent> onCheckout,
                                         EventHandler<ActionEvent> onViewPoints,
                                         EventHandler<ActionEvent> onBack) {

        BorderPane root = new BorderPane();
        root.setPadding(new Insets(20));
        root.setStyle("-fx-background-color: #ecf0f1;");

        // Top: Customer info
        VBox topBox = new VBox(10);
        topBox.setAlignment(Pos.CENTER);
        Label welcomeLabel = new Label("Welcome, " + customer.getName() + "!");
        welcomeLabel.setFont(Font.font("System", FontWeight.BOLD, 20));

        topBox.getChildren().add(welcomeLabel);
        if (customer.isSenior()) {
            Label seniorLabel = new Label("Senior Citizen Discount Active");
            seniorLabel.setStyle("-fx-text-fill: #27ae60; -fx-font-weight: bold;");
            topBox.getChildren().add(seniorLabel);
        }
        root.setTop(topBox);

        // Center: Menu buttons
        VBox centerBox = new VBox(15);
        centerBox.setAlignment(Pos.CENTER);
        centerBox.setPadding(new Insets(30));

        Button viewProductsBtn = createMenuButton("View Products");
        Button addToCartBtn = createMenuButton("Add Product to Cart");
        Button viewCartBtn = createMenuButton("View Cart");
        Button removeFromCartBtn = createMenuButton("Remove from Cart");
        Button viewTotalBtn = createMenuButton("View Total Cost");
        Button checkoutBtn = createMenuButton("Proceed to Checkout");
        Button viewPointsBtn = createMenuButton("View Membership Points");
        Button backBtn = createMenuButton("Back to Main Menu");

        // Styling specific buttons
        checkoutBtn.setStyle(checkoutBtn.getStyle().replace("#3498db", "#27ae60")); // Green
        backBtn.setStyle(backBtn.getStyle().replace("#3498db", "#95a5a6"));    // Grey

        // --- Bind Actions (Delegation) ---
        // The Controller tells us what these buttons do via the parameters
        viewProductsBtn.setOnAction(onViewProducts);
        addToCartBtn.setOnAction(onAddToCart);
        viewCartBtn.setOnAction(onViewCart);
        removeFromCartBtn.setOnAction(onRemove);
        viewTotalBtn.setOnAction(onViewTotal);
        checkoutBtn.setOnAction(onCheckout);
        viewPointsBtn.setOnAction(onViewPoints);
        backBtn.setOnAction(onBack);

        centerBox.getChildren().addAll(viewProductsBtn, addToCartBtn, viewCartBtn,
                removeFromCartBtn, viewTotalBtn, checkoutBtn,
                viewPointsBtn, backBtn);
        root.setCenter(centerBox);

        return new Scene(root, 600, 700);
    }

    private Button createMenuButton(String text) {
        Button btn = new Button(text);
        btn.setStyle("-fx-font-size: 14px; -fx-min-width: 300px; -fx-min-height: 40px; " +
                "-fx-background-color: #3498db; -fx-text-fill: white; " +
                "-fx-background-radius: 5; -fx-cursor: hand;");
        return btn;
    }

    // Helper to show alerts from the Controller
    public void showAlert(Alert.AlertType type, String title, String message) {
        Alert alert = new Alert(type);
        alert.setTitle(title);
        alert.setHeaderText(null);
        alert.setContentText(message);
        alert.showAndWait();
    }
}
