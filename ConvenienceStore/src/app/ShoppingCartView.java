package app;

import fromMCO1.*;
import javafx.beans.property.SimpleStringProperty;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.*;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.util.Pair;
import javafx.util.StringConverter;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.stream.Collectors;

public class ShoppingCartView {

    // --- HELPER METHOD: Calculate Available Stock ---
    /**
     * Calculates how many more units can be added to cart
     * Formula: Available = Total Stock - Already in Cart
     */
    private int getAvailableStock(ProductModel product, ShoppingCartModel cart) {
        int totalStock = product.getQuantityInStock();
        int inCart = cart.getQuantity(product);
        return Math.max(0, totalStock - inCart);
    }

    // --- ADD TO CART DIALOG (WITH SPINNER AND TEXTFIELD) ---
    public Dialog<Pair<ProductModel, Integer>> createAddToCartDialog(List<ProductModel> availableProducts, ShoppingCartModel cart) {
        Dialog<Pair<ProductModel, Integer>> dialog = new Dialog<>();
        dialog.setTitle("Add to Cart");
        dialog.setHeaderText("Select a product to add");

        VBox content = new VBox(15);
        content.setPadding(new Insets(20));

        // FILTER: Only show products with available stock (not fully in cart)
        List<ProductModel> productsWithStock = availableProducts.stream()
                .filter(p -> getAvailableStock(p, cart) > 0)
                .collect(Collectors.toList());

        ComboBox<ProductModel> productCombo = new ComboBox<>();
        productCombo.getItems().addAll(productsWithStock);

        // Display product with dynamic stock info
        productCombo.setConverter(new StringConverter<ProductModel>() {
            @Override
            public String toString(ProductModel product) {
                if (product == null) return null;

                int inCart = cart.getQuantity(product);
                int available = getAvailableStock(product, cart);

                if (inCart > 0) {
                    return String.format("%s (In Cart: %d | Available: %d)",
                            product.getName(), inCart, available);
                } else {
                    return String.format("%s (Available: %d)",
                            product.getName(), available);
                }
            }

            @Override
            public ProductModel fromString(String string) {
                return null;
            }
        });

        productCombo.setPromptText("Select Product");
        productCombo.setPrefWidth(400);

        // Stock Information Panel
        VBox stockInfoBox = new VBox(5);
        stockInfoBox.setStyle("-fx-background-color: #f8f9fa; -fx-padding: 10; -fx-border-color: #dee2e6; -fx-border-radius: 5;");
        stockInfoBox.setVisible(false);

        Label totalStockLabel = new Label();
        Label inCartLabel = new Label();
        Label canAddLabel = new Label();
        canAddLabel.setStyle("-fx-font-weight: bold; -fx-text-fill: #28a745;");

        stockInfoBox.getChildren().addAll(totalStockLabel, inCartLabel, canAddLabel);

        // QUANTITY CONTROLS: Both Spinner and TextField
        HBox quantityBox = new HBox(15);
        quantityBox.setAlignment(Pos.CENTER_LEFT);

        // Spinner for increment/decrement
        Spinner<Integer> quantitySpinner = new Spinner<>(1, 100, 1);
        quantitySpinner.setPrefWidth(120);
        quantitySpinner.setDisable(true);
        quantitySpinner.setStyle("-fx-font-size: 14px;");

        // TextField for manual input
        TextField quantityField = new TextField();
        quantityField.setPromptText("or type qty");
        quantityField.setPrefWidth(120);
        quantityField.setDisable(true);
        quantityField.setStyle("-fx-font-size: 14px; -fx-padding: 8;");

        // Synchronize spinner and textfield
        quantitySpinner.valueProperty().addListener((obs, oldVal, newVal) -> {
            quantityField.setText(String.valueOf(newVal));
        });

        quantityField.textProperty().addListener((obs, oldVal, newVal) -> {
            try {
                if (!newVal.isEmpty() && productCombo.getValue() != null) {
                    int value = Integer.parseInt(newVal);
                    int available = getAvailableStock(productCombo.getValue(), cart);

                    if (value > 0 && value <= available) {
                        quantitySpinner.getValueFactory().setValue(value);
                    }
                }
            } catch (NumberFormatException e) {
                // Ignore invalid input, keep old value
            }
        });

        VBox spinnerBox = new VBox(5);
        spinnerBox.getChildren().addAll(new Label("Use Spinner:"), quantitySpinner);

        VBox textFieldBox = new VBox(5);
        textFieldBox.getChildren().addAll(new Label("Or Type Quantity:"), quantityField);

        quantityBox.getChildren().addAll(spinnerBox, textFieldBox);

        Label stockWarningLabel = new Label();
        stockWarningLabel.setStyle("-fx-text-fill: #e74c3c; -fx-font-weight: bold;");
        stockWarningLabel.setVisible(false);

        // Update UI when product is selected
        productCombo.setOnAction(e -> {
            ProductModel selected = productCombo.getValue();
            if (selected != null) {
                int totalStock = selected.getQuantityInStock();
                int inCart = cart.getQuantity(selected);
                int available = getAvailableStock(selected, cart);

                // Update stock info panel
                totalStockLabel.setText("Total Stock: " + totalStock);
                inCartLabel.setText("In Your Cart: " + inCart);
                canAddLabel.setText("Can Add: " + available + " more");
                stockInfoBox.setVisible(true);

                if (available > 0) {
                    // Enable quantity controls
                    quantitySpinner.setDisable(false);
                    quantityField.setDisable(false);

                    // Reset to default value
                    SpinnerValueFactory<Integer> valueFactory =
                            new SpinnerValueFactory.IntegerSpinnerValueFactory(1, available, 1);
                    quantitySpinner.setValueFactory(valueFactory);
                    quantityField.setText("1");

                    stockWarningLabel.setVisible(false);

                    // Show warning if low stock
                    if (available < 10) {
                        stockWarningLabel.setText("⚠ Only " + available + " more available!");
                        stockWarningLabel.setStyle("-fx-text-fill: #f39c12; -fx-font-weight: bold;");
                        stockWarningLabel.setVisible(true);
                    }
                } else {
                    // Disable quantity controls
                    quantitySpinner.setDisable(true);
                    quantityField.setDisable(true);
                    quantityField.setText("");
                    stockWarningLabel.setText("✖ No more stock available! (All units in cart)");
                    stockWarningLabel.setStyle("-fx-text-fill: #e74c3c; -fx-font-weight: bold;");
                    stockWarningLabel.setVisible(true);
                }
            } else {
                quantitySpinner.setDisable(true);
                quantityField.setDisable(true);
                quantityField.setText("");
                stockInfoBox.setVisible(false);
                stockWarningLabel.setVisible(false);
            }
        });

        // Show message if no products available
        if (productsWithStock.isEmpty()) {
            Label noStockLabel = new Label("No products available!\nAll stock is either sold out or already in your cart.");
            noStockLabel.setStyle("-fx-text-fill: #e74c3c; -fx-font-size: 14px; -fx-font-weight: bold;");
            content.getChildren().add(noStockLabel);
        } else {
            content.getChildren().addAll(
                    new Label("Product:"), productCombo,
                    stockInfoBox,
                    new Label("Quantity:"), quantityBox,
                    stockWarningLabel
            );
        }

        dialog.getDialogPane().setContent(content);

        ButtonType addButtonType = new ButtonType("Add to Cart", ButtonBar.ButtonData.OK_DONE);
        dialog.getDialogPane().getButtonTypes().addAll(addButtonType, ButtonType.CANCEL);

        // Disable Add button if no stock available
        if (productsWithStock.isEmpty()) {
            dialog.getDialogPane().lookupButton(addButtonType).setDisable(true);
        }

        dialog.setResultConverter(button -> {
            if (button == addButtonType && productCombo.getValue() != null) {
                ProductModel selected = productCombo.getValue();
                int requestedQty = quantitySpinner.getValue();
                int available = getAvailableStock(selected, cart);

                // Final validation
                if (requestedQty > available) {
                    showAlert(Alert.AlertType.ERROR, "Insufficient Stock",
                            "Cannot add " + requestedQty + " units. Only " +
                                    available + " more available.");
                    return null;
                }

                if (requestedQty <= 0) {
                    showAlert(Alert.AlertType.WARNING, "Invalid Quantity", "Quantity must be greater than 0.");
                    return null;
                }

                return new Pair<>(selected, requestedQty);
            }
            return null;
        });

        dialog.getDialogPane().setPrefSize(700, 400);
        return dialog;
    }

    // --- VIEW CART DIALOG ---
    public void showCartDialog(Map<ProductModel, Integer> cartItems, double totalCost) {
        Dialog<Void> dialog = new Dialog<>();
        dialog.setTitle("Shopping Cart");
        dialog.setHeaderText("Your Cart");

        VBox content = new VBox(10);
        content.setPadding(new Insets(20));

        if (cartItems.isEmpty()) {
            Label emptyLabel = new Label("Cart is empty");
            emptyLabel.setStyle("-fx-font-size: 14px;");
            content.getChildren().add(emptyLabel);
        } else {
            TableView<Map.Entry<ProductModel, Integer>> table = createCartTable(cartItems);

            Label subtotalLabel = new Label(String.format("Subtotal: ₱%.2f", totalCost));
            subtotalLabel.setFont(Font.font("System", FontWeight.BOLD, 16));

            content.getChildren().addAll(table, subtotalLabel);
        }

        dialog.getDialogPane().setContent(content);
        dialog.getDialogPane().getButtonTypes().add(ButtonType.CLOSE);
        dialog.getDialogPane().setPrefSize(600, 400);
        dialog.showAndWait();
    }

    private TableView<Map.Entry<ProductModel, Integer>> createCartTable(Map<ProductModel, Integer> cartItems) {
        TableView<Map.Entry<ProductModel, Integer>> table = new TableView<>();

        TableColumn<Map.Entry<ProductModel, Integer>, String> nameCol = new TableColumn<>("Product");
        nameCol.setCellValueFactory(data -> new SimpleStringProperty(data.getValue().getKey().getName()));
        nameCol.setPrefWidth(200);

        TableColumn<Map.Entry<ProductModel, Integer>, String> qtyCol = new TableColumn<>("Quantity");
        qtyCol.setCellValueFactory(data -> new SimpleStringProperty(String.valueOf(data.getValue().getValue())));
        qtyCol.setPrefWidth(100);

        TableColumn<Map.Entry<ProductModel, Integer>, String> priceCol = new TableColumn<>("Price");
        priceCol.setCellValueFactory(data -> new SimpleStringProperty(String.format("₱%.2f", data.getValue().getKey().getPrice())));
        priceCol.setPrefWidth(100);

        TableColumn<Map.Entry<ProductModel, Integer>, String> totalCol = new TableColumn<>("Total");
        totalCol.setCellValueFactory(data -> {
            double lineTotal = data.getValue().getKey().getPrice() * data.getValue().getValue();
            return new SimpleStringProperty(String.format("₱%.2f", lineTotal));
        });
        totalCol.setPrefWidth(100);

        table.getColumns().addAll(nameCol, qtyCol, priceCol, totalCol);
        table.getItems().addAll(cartItems.entrySet());

        return table;
    }

    // --- REMOVE DIALOG ---
    public Dialog<ProductModel> createRemoveDialog(List<ProductModel> cartProducts) {
        Dialog<ProductModel> dialog = new Dialog<>();
        dialog.setTitle("Remove from Cart");
        dialog.setHeaderText("Select product to remove");

        VBox content = new VBox(15);
        content.setPadding(new Insets(20));

        ComboBox<ProductModel> productCombo = new ComboBox<>();
        productCombo.getItems().addAll(cartProducts);

        productCombo.setConverter(new StringConverter<ProductModel>() {
            @Override
            public String toString(ProductModel product) {
                if (product == null) return null;
                return product.getName();
            }

            @Override
            public ProductModel fromString(String string) {
                return null;
            }
        });

        productCombo.setPromptText("Select Product");
        productCombo.setPrefWidth(300);

        content.getChildren().addAll(new Label("Product:"), productCombo);
        dialog.getDialogPane().setContent(content);

        ButtonType removeBtnType = new ButtonType("Remove", ButtonBar.ButtonData.OK_DONE);
        dialog.getDialogPane().getButtonTypes().addAll(removeBtnType, ButtonType.CANCEL);

        dialog.setResultConverter(btn -> {
            if (btn == removeBtnType) return productCombo.getValue();
            return null;
        });

        return dialog;
    }

    // --- HELPERS ---
    public boolean askConfirmation(String title, String message) {
        Alert alert = new Alert(Alert.AlertType.CONFIRMATION);
        alert.setTitle(title);
        alert.setContentText(message);
        return alert.showAndWait().orElse(ButtonType.CANCEL) == ButtonType.OK;
    }

    public Optional<String> showPaymentDialog(double totalAmount) {
        TextInputDialog dialog = new TextInputDialog();
        dialog.setTitle("Payment");
        dialog.setHeaderText(String.format("Total Amount: ₱%.2f", totalAmount));
        dialog.setContentText("Enter amount paid:");
        return dialog.showAndWait();
    }

    public void showReceipt(String receiptText) {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle("Receipt");
        alert.setHeaderText("Transaction Complete!");
        TextArea textArea = new TextArea(receiptText);
        textArea.setEditable(false);
        textArea.setWrapText(true);
        textArea.setPrefRowCount(15);
        alert.getDialogPane().setContent(textArea);
        alert.showAndWait();
    }

    public void showAlert(Alert.AlertType type, String title, String message) {
        Alert alert = new Alert(type);
        alert.setTitle(title);
        alert.setContentText(message);
        alert.showAndWait();
    }
}