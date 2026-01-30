package app;

import fromMCO1.ConvenienceStoreModel;
import fromMCO1.CustomerModel;
import fromMCO1.InventoryModel;
import javafx.scene.control.Alert;
import javafx.stage.Stage;

public class CustomerController {

    private final Stage primaryStage;
    private final ConvenienceStoreModel store;
    private final InventoryModel inventory;
    private final CustomerView view;

    public CustomerController(Stage primaryStage, ConvenienceStoreModel store) {
        this.primaryStage = primaryStage;
        this.store = store;
        this.inventory = store.getInventory();
        this.view = new CustomerView();
    }

    // 1. Entry Point: Shows Login Dialog
    public void handleCustomerLogin() {
        view.createLoginDialog().showAndWait().ifPresent(this::showCustomerMenu);
    }

    // 2. Logic: Creates the Menu Scene by mapping Actions to Buttons
    private void showCustomerMenu(CustomerModel customer) {
        primaryStage.setScene(view.createCustomerMenuScene(
                customer,
                e -> showProducts(customer),
                e -> showAddToCart(customer),
                e -> showCart(customer),
                e -> showRemoveFromCart(customer),
                e -> showTotalCost(customer),
                e -> performCheckout(customer),
                e -> showPoints(customer),
                e -> goBackToMainMenu(customer)  // ← Pass customer here
        ));
    }

    // --- Sub-Controller Delegation ---

    private void showProducts(CustomerModel customer) {
        new ProductController(inventory).showProductsDialogWithCart(customer.getShoppingCart());
    }

    private void showAddToCart(CustomerModel customer) {
        new ShoppingCartController(primaryStage, customer, inventory).showAddToCart();
    }

    private void showCart(CustomerModel customer) {
        new ShoppingCartController(primaryStage, customer, inventory).showCart();
    }

    private void showRemoveFromCart(CustomerModel customer) {
        new ShoppingCartController(primaryStage, customer, inventory).showRemoveFromCart();
    }

    private void performCheckout(CustomerModel customer) {
        new ShoppingCartController(primaryStage, customer, inventory).performCheckout();
    }

    private void showTotalCost(CustomerModel customer) {
        view.showAlert(Alert.AlertType.INFORMATION, "Total Cost",
                String.format("Subtotal: ₱%.2f", customer.viewTotalCost()));
    }

    private void showPoints(CustomerModel customer) {
        view.showAlert(Alert.AlertType.INFORMATION, "Membership Points",
                "Current Points: " + customer.getMembership().getPoints() + " points");
    }

    private void goBackToMainMenu(CustomerModel customer) {
        // SAVE CUSTOMER DATA BEFORE EXITING
        customer.saveCustomerData();

        // Show confirmation
        view.showAlert(Alert.AlertType.INFORMATION, "Goodbye",
                "Thank you for shopping, " + customer.getName() + "!\n" +
                        "Your points have been saved: " + customer.getMembership().getPoints() + " points");

        // Return to main menu
        new ConvenienceStoreController(primaryStage, this.store).show();
    }
}