package app;

import fromMCO1.*;
import javafx.stage.Stage;
import javafx.scene.Scene;

public class EmployeeController {

    private final EmployeeView view;
    private final Stage primaryStage;
    private final ConvenienceStoreModel store; // ADD THIS FIELD
    private final InventoryModel inventory;

    // CHANGE CONSTRUCTOR: Accept 'ConvenienceStore' instead of 'InventoryModel'
    public EmployeeController(Stage primaryStage, ConvenienceStoreModel store) {
        this.primaryStage = primaryStage;
        this.store = store; // Save the store so we can go back safely
        this.inventory = store.getInventory(); // Extract inventory for internal use
        this.view = new EmployeeView();
    }

    // Entry point
    public void showEmployeeLogin() {
        view.createLoginDialog().showAndWait().ifPresent(this::showEmployeeMenu);
    }

    // Logic to switch to the menu
    private void showEmployeeMenu(EmployeeModel employee) {
        Scene menuScene = view.createEmployeeMenuScene(
                employee,
                e -> showProductsDialog(),
                e -> showAddProductDialog(employee),
                e -> showRestockDialog(employee),
                e -> showUpdateProductDialog(employee),
                e -> showLowStockDialog(),
                e -> handleDeleteProduct(),
                e -> handleDeleteAllProducts(),
                e -> navigateBackToMain()
        );

        primaryStage.setScene(menuScene);
    }

    private void handleDeleteProduct() {
        new ProductController(inventory).handleDeleteProduct();
    }

    private void handleDeleteAllProducts() {
        new ProductController(inventory).handleDeleteAllProducts();
    }

    // --- Action Handlers ---

    private void showProductsDialog() {
        new ProductController(inventory).showProductsDialog();
    }

    private void showLowStockDialog() {
        // Assuming you have an InventoryController or similar
        new InventoryController(inventory).showLowStockDialog();
        // If you renamed it to InventoryController, use that instead.
    }

    private void navigateBackToMain() {
        new ConvenienceStoreController(primaryStage, store).show();
    }

    private void showAddProductDialog(EmployeeModel employee) {
        new ProductController(inventory).handleAddProduct(employee);
    }

    private void showRestockDialog(EmployeeModel employee) {
        new ProductController(inventory).handleRestock(employee);
    }

    private void showUpdateProductDialog(EmployeeModel employee) {
        new ProductController(inventory).handleUpdateProduct(employee);
    }
}
