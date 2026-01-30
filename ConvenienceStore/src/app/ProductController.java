package app;

import fromMCO1.*;
import javafx.scene.control.Alert;
import javafx.scene.control.ButtonType;
import javafx.scene.control.Dialog;
import java.util.List;
import java.util.Optional;

public class ProductController {

    private final ProductView view;
    private final InventoryModel inventory;

    public ProductController(InventoryModel inventory) {
        this.inventory = inventory;
        this.view = new ProductView();
    }

    // --- 1. MAIN DISPLAY LOGIC (EMPLOYEE) ---
    public void showProductsDialog() {
        List<ProductModel> products = inventory.getProducts();
        Dialog<Void> dialog = view.createProductDialog(products);
        dialog.showAndWait();
    }

    // --- NEW: FOR CUSTOMERS (with cart context) ---
    public void showProductsDialogWithCart(ShoppingCartModel cart) {
        List<ProductModel> products = inventory.getProducts();
        Dialog<Void> dialog = view.createProductDialogWithCart(products, cart);
        dialog.showAndWait();
    }

    // --- 2. ADD PRODUCT LOGIC ---
    public void handleAddProduct(EmployeeModel employee) {
        view.showAddProductDialog(newProduct -> {
            try {
                employee.addProduct(inventory, newProduct);
                view.showAlert(Alert.AlertType.INFORMATION, "Success", "Product added successfully!");
            } catch (Exception e) {
                view.showAlert(Alert.AlertType.ERROR, "Error", "Could not add product. " + e.getMessage());
            }
        });
    }

    // --- 3. RESTOCK LOGIC ---
    public void handleRestock(EmployeeModel employee) {
        view.showRestockDialog(inventory.getProducts(), pair -> {
            ProductModel product = pair.getKey();
            int quantity = pair.getValue();

            try {
                employee.restock(inventory, product.getName(), quantity);
                view.showAlert(Alert.AlertType.INFORMATION, "Success", "Product restocked successfully!");
            } catch (Exception e) {
                view.showAlert(Alert.AlertType.ERROR, "Error", "Could not restock product. " + e.getMessage());
            }
        });
    }

    // --- 4. UPDATE PRODUCT LOGIC ---
    public void handleUpdateProduct(EmployeeModel employee) {
        view.showUpdateProductDialog(inventory.getProducts(), updatedProduct -> {
            try {
                employee.updateProduct(inventory, updatedProduct);
                view.showAlert(Alert.AlertType.INFORMATION, "Success", "Product updated successfully!");
            } catch (Exception e) {
                view.showAlert(Alert.AlertType.ERROR, "Error", "Could not update product. " + e.getMessage());
            }
        });
    }

    // --- NEW: DELETE ALL PRODUCTS ---
    public void handleDeleteAllProducts() {
        if (inventory.getProducts().isEmpty()) {
            view.showAlert(Alert.AlertType.WARNING, "No Products", "Inventory is already empty!");
            return;
        }

        // Confirmation Dialog with WARNING
        Alert confirmAlert = new Alert(Alert.AlertType.WARNING);
        confirmAlert.setTitle("⚠ DELETE ALL PRODUCTS");
        confirmAlert.setHeaderText("This will permanently delete ALL products!");
        confirmAlert.setContentText(
                "Current inventory: " + inventory.getProducts().size() + " products\n\n" +
                        "This action CANNOT be undone!\n" +
                        "Are you absolutely sure?"
        );

        ButtonType deleteButton = new ButtonType("DELETE ALL");
        ButtonType cancelButton = new ButtonType("Cancel", ButtonType.CANCEL.getButtonData());

        confirmAlert.getButtonTypes().setAll(deleteButton, cancelButton);

        Optional<ButtonType> result = confirmAlert.showAndWait();

        if (result.isPresent() && result.get() == deleteButton) {
            // Second confirmation for safety
            Alert finalConfirm = new Alert(Alert.AlertType.CONFIRMATION);
            finalConfirm.setTitle("Final Confirmation");
            finalConfirm.setHeaderText("Last chance to cancel!");
            finalConfirm.setContentText("Delete all " + inventory.getProducts().size() + " products?");

            Optional<ButtonType> finalResult = finalConfirm.showAndWait();

            if (finalResult.isPresent() && finalResult.get() == ButtonType.OK) {
                int deletedCount = inventory.getProducts().size();
                inventory.deleteAllProducts();
                view.showAlert(Alert.AlertType.INFORMATION, "Success",
                        "All products deleted!\n" + deletedCount + " items removed from inventory.");
            } else {
                view.showAlert(Alert.AlertType.INFORMATION, "Cancelled", "Delete operation cancelled.");
            }
        }
    }

    // Add this method to ProductController.java

    // --- NEW: DELETE SINGLE PRODUCT ---
    public void handleDeleteProduct() {
        if (inventory.getProducts().isEmpty()) {
            view.showAlert(Alert.AlertType.WARNING, "No Products", "Inventory is empty!");
            return;
        }

        view.showDeleteProductDialog(inventory.getProducts(), product -> {
            try {
                boolean success = inventory.deleteProduct(product);

                if (success) {
                    view.showAlert(Alert.AlertType.INFORMATION, "Success",
                            "Product deleted successfully!\n\n" +
                                    "Deleted: " + product.getName() + "\n" +
                                    "Remaining products: " + inventory.getProducts().size());
                } else {
                    view.showAlert(Alert.AlertType.ERROR, "Error",
                            "Failed to delete product.");
                }
            } catch (Exception e) {
                view.showAlert(Alert.AlertType.ERROR, "Error",
                        "Could not delete product: " + e.getMessage());
            }
        });
    }
}