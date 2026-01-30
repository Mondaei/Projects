package app;

import fromMCO1.ProductModel;
import fromMCO1.ShoppingCartModel;
import javafx.geometry.Insets;
import javafx.scene.control.*;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.VBox;
import javafx.util.Pair;
import javafx.util.StringConverter;
import java.util.List;
import java.util.Optional;
import java.util.function.Consumer;

public class ProductView {

    // ==========================================
    // SECTION 1: PRODUCT LIST TABLE WITH CATEGORY FILTER
    // ==========================================

    // EMPLOYEE VIEW: Shows all products with category filter
    public Dialog<Void> createProductDialog(List<ProductModel> productList) {
        return createProductDialogInternal(productList, null);
    }

    // CUSTOMER VIEW: Shows available stock with category filter
    public Dialog<Void> createProductDialogWithCart(List<ProductModel> productList, ShoppingCartModel cart) {
        return createProductDialogInternal(productList, cart);
    }

    // INTERNAL: Unified method with category filter
    private Dialog<Void> createProductDialogInternal(List<ProductModel> productList, ShoppingCartModel cart) {
        Dialog<Void> dialog = new Dialog<>();
        dialog.setTitle("Products");
        dialog.setHeaderText("Select Category to View Products");

        VBox content = new VBox(15);
        content.setPadding(new Insets(20));

        // Category Selection
        Label categoryLabel = new Label("Select Category:");
        categoryLabel.setStyle("-fx-font-weight: bold; -fx-font-size: 14px;");

        ComboBox<String> categoryCombo = new ComboBox<>();
        categoryCombo.getItems().addAll(CategoryHelper.getCategories());
        categoryCombo.getItems().add(0, "All Categories"); // Add "All" option
        categoryCombo.setValue("All Categories");
        categoryCombo.setPrefWidth(300);

        // Product Table (initially shows all)
        TableView<ProductModel> table = createProductTable(productList, cart);

        // Update table when category changes
        categoryCombo.setOnAction(e -> {
            String selectedCategory = categoryCombo.getValue();

            if ("All Categories".equals(selectedCategory)) {
                // Show all products
                table.getItems().clear();
                table.getItems().addAll(productList);
            } else {
                // Filter by category
                List<ProductModel> filtered = productList.stream()
                        .filter(p -> p.getCategory().equalsIgnoreCase(selectedCategory))
                        .collect(java.util.stream.Collectors.toList());

                table.getItems().clear();
                table.getItems().addAll(filtered);
            }
        });

        // Product count label
        Label countLabel = new Label("Total Products: " + productList.size());
        countLabel.setStyle("-fx-font-style: italic;");

        // Update count when category changes
        categoryCombo.setOnAction(e -> {
            String selectedCategory = categoryCombo.getValue();

            if ("All Categories".equals(selectedCategory)) {
                table.getItems().clear();
                table.getItems().addAll(productList);
                countLabel.setText("Total Products: " + productList.size());
            } else {
                List<ProductModel> filtered = productList.stream()
                        .filter(p -> p.getCategory().equalsIgnoreCase(selectedCategory))
                        .collect(java.util.stream.Collectors.toList());

                table.getItems().clear();
                table.getItems().addAll(filtered);
                countLabel.setText(selectedCategory + ": " + filtered.size() + " product(s)");
            }
        });

        content.getChildren().addAll(categoryLabel, categoryCombo, table, countLabel);

        dialog.getDialogPane().setContent(content);
        dialog.getDialogPane().getButtonTypes().add(ButtonType.CLOSE);
        dialog.getDialogPane().setPrefSize(750, 600);

        return dialog;
    }

    private TableView<ProductModel> createProductTable(List<ProductModel> productList, ShoppingCartModel cart) {
        TableView<ProductModel> table = new TableView<>();

        TableColumn<ProductModel, String> nameCol = new TableColumn<>("Product Name");
        nameCol.setCellValueFactory(data -> new javafx.beans.property.SimpleStringProperty(data.getValue().getName()));
        nameCol.setPrefWidth(180);

        TableColumn<ProductModel, String> brandCol = new TableColumn<>("Brand");
        brandCol.setCellValueFactory(data -> new javafx.beans.property.SimpleStringProperty(data.getValue().getBrand()));
        brandCol.setPrefWidth(120);

        TableColumn<ProductModel, String> categoryCol = new TableColumn<>("Category");
        categoryCol.setCellValueFactory(data -> new javafx.beans.property.SimpleStringProperty(data.getValue().getCategory()));
        categoryCol.setPrefWidth(150);

        TableColumn<ProductModel, String> priceCol = new TableColumn<>("Price");
        priceCol.setCellValueFactory(data -> new javafx.beans.property.SimpleStringProperty(String.format("₱%.2f", data.getValue().getPrice())));
        priceCol.setPrefWidth(100);

        // UPDATED STOCK COLUMN - Shows available stock if cart is provided
        TableColumn<ProductModel, String> stockCol = new TableColumn<>("Stock");
        stockCol.setCellValueFactory(data -> {
            ProductModel product = data.getValue();
            int totalStock = product.getQuantityInStock();

            if (cart != null) {
                // Customer view - show available stock
                int inCart = cart.getQuantity(product);
                int available = Math.max(0, totalStock - inCart);

                String display = String.valueOf(available);

                if (inCart > 0) {
                    display += String.format(" (%d in cart)", inCart);
                }

                if (available < 10 && available > 0) {
                    display += " (LOW)";
                } else if (available == 0) {
                    display = "0 (ALL IN CART)";
                }

                return new javafx.beans.property.SimpleStringProperty(display);
            } else {
                // Employee view - show total stock
                String display = String.valueOf(totalStock);
                if (totalStock < 10) display += " (LOW)";
                return new javafx.beans.property.SimpleStringProperty(display);
            }
        });
        stockCol.setPrefWidth(150);

        table.getColumns().addAll(nameCol, brandCol, categoryCol, priceCol, stockCol);
        table.getItems().addAll(productList);

        return table;
    }

    // ==========================================
    // SECTION 2: ACTION DIALOGS
    // ==========================================

    // --- ADD PRODUCT (WITH CATEGORY DROPDOWN) ---
    public void showAddProductDialog(Consumer<ProductModel> onAddAction) {
        Dialog<Void> dialog = new Dialog<>();
        dialog.setTitle("Add New Product");
        dialog.setHeaderText("Enter Product Information");

        GridPane grid = new GridPane();
        grid.setHgap(10);
        grid.setVgap(10);
        grid.setPadding(new Insets(20));

        // Row 0: Name
        TextField nameField = new TextField();
        nameField.setPromptText("Enter product name");
        grid.add(new Label("Name:"), 0, 0);
        grid.add(nameField, 1, 0);

        // Row 1: Brand
        TextField brandField = new TextField();
        brandField.setPromptText("Enter brand name");
        grid.add(new Label("Brand:"), 0, 1);
        grid.add(brandField, 1, 1);

        // Row 2: Category Dropdown
        ComboBox<String> categoryCombo = new ComboBox<>();
        categoryCombo.getItems().addAll(CategoryHelper.getCategories());
        categoryCombo.setPromptText("Select Category");
        categoryCombo.setPrefWidth(200);
        grid.add(new Label("Category:"), 0, 2);
        grid.add(categoryCombo, 1, 2);

        // Row 3: Price
        TextField priceField = new TextField();
        priceField.setPromptText("0.00");
        grid.add(new Label("Price:"), 0, 3);
        grid.add(priceField, 1, 3);

        // Row 4: Quantity
        Spinner<Integer> quantitySpinner = new Spinner<>(0, 10000, 0);
        quantitySpinner.setEditable(true);
        grid.add(new Label("Quantity:"), 0, 4);
        grid.add(quantitySpinner, 1, 4);

        // Row 5: Expiration
        DatePicker expirationPicker = new DatePicker();
        grid.add(new Label("Expiration:"), 0, 5);
        grid.add(expirationPicker, 1, 5);

        // Row 6: Add Button
        Button addBtn = new Button("Add Product");
        addBtn.setStyle("-fx-background-color: #27ae60; -fx-text-fill: white; -fx-font-size: 14px; -fx-padding: 8 20;");

        addBtn.setOnAction(e -> {
            try {
                // Validation
                if (nameField.getText().trim().isEmpty()) {
                    showAlert(Alert.AlertType.WARNING, "Missing Information", "Please enter product name.");
                    return;
                }
                if (brandField.getText().trim().isEmpty()) {
                    showAlert(Alert.AlertType.WARNING, "Missing Information", "Please enter brand name.");
                    return;
                }
                if (categoryCombo.getValue() == null) {
                    showAlert(Alert.AlertType.WARNING, "Missing Information", "Please select a category.");
                    return;
                }
                if (expirationPicker.getValue() == null) {
                    showAlert(Alert.AlertType.WARNING, "Missing Information", "Please select expiration date.");
                    return;
                }

                ProductModel product = new ProductModel(
                        nameField.getText().trim(),
                        brandField.getText().trim(),
                        categoryCombo.getValue(),
                        Double.parseDouble(priceField.getText()),
                        quantitySpinner.getValue(),
                        expirationPicker.getValue()
                );
                onAddAction.accept(product);
                dialog.close();
            } catch (NumberFormatException ex) {
                showAlert(Alert.AlertType.ERROR, "Invalid Input", "Please enter a valid price.");
            } catch (Exception ex) {
                showAlert(Alert.AlertType.ERROR, "Error", "Invalid input! Please check all fields.");
            }
        });

        grid.add(addBtn, 1, 6);

        dialog.getDialogPane().setContent(grid);
        dialog.getDialogPane().getButtonTypes().add(ButtonType.CANCEL);
        dialog.getDialogPane().setPrefWidth(450);
        dialog.showAndWait();
    }

    // Add this method to ProductView.java (in SECTION 2: ACTION DIALOGS)

    // --- DELETE SINGLE PRODUCT ---
    public void showDeleteProductDialog(List<ProductModel> products, Consumer<ProductModel> onDeleteAction) {
        Dialog<Void> dialog = new Dialog<>();
        dialog.setTitle("Delete Product");
        dialog.setHeaderText("⚠ Select product to DELETE");

        VBox content = new VBox(15);
        content.setPadding(new Insets(20));

        // Warning label
        Label warningLabel = new Label("⚠ Warning: This action cannot be undone!");
        warningLabel.setStyle("-fx-text-fill: #e74c3c; -fx-font-weight: bold; -fx-font-size: 14px;");

        // Product selection dropdown
        ComboBox<ProductModel> productCombo = new ComboBox<>();
        productCombo.getItems().addAll(products);

        productCombo.setConverter(new StringConverter<ProductModel>() {
            @Override
            public String toString(ProductModel product) {
                if (product == null) return null;
                return String.format("%s - %s (Stock: %d)",
                        product.getName(),
                        product.getCategory(),
                        product.getQuantityInStock());
            }

            @Override
            public ProductModel fromString(String string) {
                return null;
            }
        });

        productCombo.setPromptText("Select Product to Delete");
        productCombo.setPrefWidth(400);

        // Product details panel (shows when product is selected)
        VBox detailsBox = new VBox(5);
        detailsBox.setStyle("-fx-background-color: #f8f9fa; -fx-padding: 10; -fx-border-color: #dee2e6; -fx-border-radius: 5;");
        detailsBox.setVisible(false);

        Label nameLabel = new Label();
        Label brandLabel = new Label();
        Label categoryLabel = new Label();
        Label priceLabel = new Label();
        Label stockLabel = new Label();

        detailsBox.getChildren().addAll(nameLabel, brandLabel, categoryLabel, priceLabel, stockLabel);

        // Update details when product is selected
        productCombo.setOnAction(e -> {
            ProductModel selected = productCombo.getValue();
            if (selected != null) {
                nameLabel.setText("Product: " + selected.getName());
                brandLabel.setText("Brand: " + selected.getBrand());
                categoryLabel.setText("Category: " + selected.getCategory());
                priceLabel.setText("Price: ₱" + String.format("%.2f", selected.getPrice()));
                stockLabel.setText("Stock: " + selected.getQuantityInStock() + " units");
                detailsBox.setVisible(true);
            } else {
                detailsBox.setVisible(false);
            }
        });

        // Delete button
        Button deleteBtn = new Button("🗑 DELETE PRODUCT");
        deleteBtn.setStyle("-fx-background-color: #e74c3c; -fx-text-fill: white; -fx-font-size: 14px; -fx-font-weight: bold; -fx-padding: 10 20;");

        deleteBtn.setOnAction(e -> {
            ProductModel selected = productCombo.getValue();
            if (selected != null) {
                // Confirmation dialog
                Alert confirm = new Alert(Alert.AlertType.CONFIRMATION);
                confirm.setTitle("Confirm Delete");
                confirm.setHeaderText("Delete this product?");
                confirm.setContentText(
                        "Product: " + selected.getName() + "\n" +
                                "Brand: " + selected.getBrand() + "\n" +
                                "Stock: " + selected.getQuantityInStock() + " units\n\n" +
                                "This action cannot be undone!"
                );

                Optional<ButtonType> result = confirm.showAndWait();
                if (result.isPresent() && result.get() == ButtonType.OK) {
                    onDeleteAction.accept(selected);
                    dialog.close();
                }
            } else {
                showAlert(Alert.AlertType.WARNING, "No Selection", "Please select a product to delete.");
            }
        });

        content.getChildren().addAll(
                warningLabel,
                new Label("Select Product:"),
                productCombo,
                detailsBox,
                deleteBtn
        );

        dialog.getDialogPane().setContent(content);
        dialog.getDialogPane().getButtonTypes().add(ButtonType.CANCEL);
        dialog.getDialogPane().setPrefWidth(500);
        dialog.showAndWait();
    }

    // --- RESTOCK ---
    public void showRestockDialog(List<ProductModel> products, Consumer<Pair<ProductModel, Integer>> onRestockAction) {
        Dialog<Void> dialog = new Dialog<>();
        dialog.setTitle("Restock Product");
        dialog.setHeaderText("Select product and quantity");

        VBox content = new VBox(15);
        content.setPadding(new Insets(20));

        ComboBox<ProductModel> productCombo = new ComboBox<>();
        productCombo.getItems().addAll(products);

        productCombo.setConverter(new StringConverter<ProductModel>() {
            @Override
            public String toString(ProductModel product) {
                if (product == null) return null;
                return product.getName() + " (Stock: " + product.getQuantityInStock() + ")";
            }

            @Override
            public ProductModel fromString(String string) {
                return null;
            }
        });

        productCombo.setPromptText("Select Product");
        productCombo.setPrefWidth(350);

        Spinner<Integer> quantitySpinner = new Spinner<>(1, 10000, 10);
        quantitySpinner.setPrefWidth(150);
        quantitySpinner.setEditable(true);

        Button restockBtn = new Button("Restock");
        restockBtn.setStyle("-fx-background-color: #27ae60; -fx-text-fill: white; -fx-font-size: 14px;");

        restockBtn.setOnAction(e -> {
            ProductModel selected = productCombo.getValue();
            if (selected != null) {
                onRestockAction.accept(new Pair<>(selected, quantitySpinner.getValue()));
                dialog.close();
            } else {
                showAlert(Alert.AlertType.WARNING, "Selection Required", "Please select a product.");
            }
        });

        content.getChildren().addAll(
                new Label("Product:"), productCombo,
                new Label("Quantity to Add:"), quantitySpinner,
                restockBtn
        );

        dialog.getDialogPane().setContent(content);
        dialog.getDialogPane().getButtonTypes().add(ButtonType.CANCEL);
        dialog.showAndWait();
    }

    // --- UPDATE PRODUCT ---
    public void showUpdateProductDialog(List<ProductModel> products, Consumer<ProductModel> onUpdateAction) {
        Dialog<Void> dialog = new Dialog<>();
        dialog.setTitle("Update Product");
        dialog.setHeaderText("Select and update product information");

        VBox content = new VBox(15);
        content.setPadding(new Insets(20));

        ComboBox<ProductModel> productCombo = new ComboBox<>();
        productCombo.getItems().addAll(products);

        productCombo.setConverter(new StringConverter<ProductModel>() {
            @Override
            public String toString(ProductModel product) {
                if (product == null) return null;
                return product.getName() + " - " + product.getCategory();
            }

            @Override
            public ProductModel fromString(String string) {
                return null;
            }
        });

        productCombo.setPromptText("Select Product to Update");
        productCombo.setPrefWidth(350);

        GridPane grid = new GridPane();
        grid.setHgap(10);
        grid.setVgap(10);
        grid.setVisible(false);

        TextField brandField = new TextField();

        ComboBox<String> categoryCombo = new ComboBox<>();
        categoryCombo.getItems().addAll(CategoryHelper.getCategories());
        categoryCombo.setPrefWidth(200);

        TextField priceField = new TextField();
        DatePicker expirationPicker = new DatePicker();

        grid.add(new Label("Brand:"), 0, 0);
        grid.add(brandField, 1, 0);
        grid.add(new Label("Category:"), 0, 1);
        grid.add(categoryCombo, 1, 1);
        grid.add(new Label("Price:"), 0, 2);
        grid.add(priceField, 1, 2);
        grid.add(new Label("Expiration:"), 0, 3);
        grid.add(expirationPicker, 1, 3);

        productCombo.setOnAction(e -> {
            ProductModel selected = productCombo.getValue();
            if (selected != null) {
                brandField.setText(selected.getBrand());
                categoryCombo.setValue(selected.getCategory());
                priceField.setText(String.valueOf(selected.getPrice()));
                expirationPicker.setValue(selected.getExpirationDate());
                grid.setVisible(true);
            }
        });

        Button updateBtn = new Button("Update Product");
        updateBtn.setStyle("-fx-background-color: #f39c12; -fx-text-fill: white; -fx-font-size: 14px;");

        updateBtn.setOnAction(e -> {
            ProductModel selected = productCombo.getValue();
            if (selected != null) {
                try {
                    if (categoryCombo.getValue() == null) {
                        showAlert(Alert.AlertType.WARNING, "Missing Information", "Please select a category.");
                        return;
                    }

                    ProductModel updated = new ProductModel(
                            selected.getName(),
                            brandField.getText(),
                            categoryCombo.getValue(),
                            Double.parseDouble(priceField.getText()),
                            selected.getQuantityInStock(),
                            expirationPicker.getValue()
                    );
                    onUpdateAction.accept(updated);
                    dialog.close();
                } catch (Exception ex) {
                    showAlert(Alert.AlertType.ERROR, "Error", "Invalid input! Please check all fields.");
                }
            }
        });

        content.getChildren().addAll(
                new Label("Select Product:"),
                productCombo,
                grid,
                updateBtn
        );

        dialog.getDialogPane().setContent(content);
        dialog.getDialogPane().getButtonTypes().add(ButtonType.CANCEL);
        dialog.getDialogPane().setPrefWidth(450);
        dialog.showAndWait();
    }

    // ==========================================
    // SECTION 3: HELPERS
    // ==========================================

    public void showAlert(Alert.AlertType type, String title, String message) {
        Alert alert = new Alert(type);
        alert.setTitle(title);
        alert.setContentText(message);
        alert.showAndWait();
    }
}