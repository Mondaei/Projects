package app;

import fromMCO1.*;
import javafx.scene.control.Alert;
import javafx.stage.Stage;
import java.util.ArrayList;
import java.util.List;

public class ShoppingCartController {

    private final ShoppingCartView view;
    private final CustomerModel customer;
    private final InventoryModel inventory;
    private final Stage primaryStage;

    public ShoppingCartController(Stage stage, CustomerModel customer, InventoryModel inventory) {
        this.primaryStage = stage;
        this.customer = customer;
        this.inventory = inventory;
        this.view = new ShoppingCartView();
    }

    // --- 1. ADD TO CART (WITH CART CONTEXT) ---
    public void showAddToCart() {
        List<ProductModel> products = inventory.getProducts();
        ShoppingCartModel cart = customer.getShoppingCart();

        // Pass cart to view for real-time availability calculation
        view.createAddToCartDialog(products, cart).showAndWait().ifPresent(pair -> {
            // Add to cart
            customer.addToCart(pair.getKey(), pair.getValue());

            // Show success with updated info
            int newQuantity = cart.getQuantity(pair.getKey());
            view.showAlert(Alert.AlertType.INFORMATION, "Success",
                    String.format("Added to cart!\n\n%s\nQuantity in cart: %d\nRemaining stock: %d",
                            pair.getKey().getName(),
                            newQuantity,
                            pair.getKey().getQuantityInStock() - newQuantity));
        });
    }

    // --- 2. VIEW CART ---
    public void showCart() {
        ShoppingCartModel cart = customer.getShoppingCart();
        view.showCartDialog(cart.getItems(), customer.viewTotalCost());
    }

    // --- 3. REMOVE FROM CART ---
    public void showRemoveFromCart() {
        ShoppingCartModel cart = customer.getShoppingCart();

        if (cart.isEmpty()) {
            view.showAlert(Alert.AlertType.WARNING, "Empty Cart", "Your cart is empty!");
            return;
        }

        // Convert cart products to list
        List<ProductModel> cartProducts = new ArrayList<>(cart.getItems().keySet());

        view.createRemoveDialog(cartProducts).showAndWait().ifPresent(product -> {
            int removedQty = cart.getQuantity(product);
            cart.removeItem(product);

            view.showAlert(Alert.AlertType.INFORMATION, "Success",
                    String.format("Removed from cart!\n\n%s (Qty: %d)\nStock restored: %d available",
                            product.getName(),
                            removedQty,
                            product.getQuantityInStock()));
        });
    }

    // --- 4. CHECKOUT LOGIC ---
    public void performCheckout() {
        ShoppingCartModel cart = customer.getShoppingCart();

        if (cart.isEmpty()) {
            view.showAlert(Alert.AlertType.WARNING, "Empty Cart", "Cannot checkout with empty cart!");
            return;
        }

        // Validate stock availability before checkout
        for (var entry : cart.getItems().entrySet()) {
            ProductModel product = entry.getKey();
            int cartQty = entry.getValue();

            if (cartQty > product.getQuantityInStock()) {
                view.showAlert(Alert.AlertType.ERROR, "Stock Issue",
                        String.format("Insufficient stock for %s\nIn cart: %d | Available: %d\n\nPlease adjust your cart.",
                                product.getName(), cartQty, product.getQuantityInStock()));
                return;
            }
        }

        // Create Transaction
        TransactionModel transaction = new TransactionModel(customer, cart);

        // 1. Apply Senior Discount
        if (customer.isSenior()) {
            transaction.applySeniorDiscount();
        }

        // 2. Ask Membership Discount
        if (view.askConfirmation("Membership Discount", "Apply membership discount?")) {
            transaction.applyMembershipDiscount();
        }

        // 3. Ask Points Redemption
        if (view.askConfirmation("Redeem Points", "Redeem membership points?")) {
            double pointsValue = customer.getMembership().redeemPoints(transaction.getTotalAmount());
            transaction.calculateTotal();
        }

        // 4. Process Payment
        processPayment(transaction, cart);
    }

    private void processPayment(TransactionModel transaction, ShoppingCartModel cart) {
        view.showPaymentDialog(transaction.getTotalAmount()).ifPresent(amountStr -> {
            try {
                double amountPaid = Double.parseDouble(amountStr);

                if (transaction.processPayment(amountPaid)) {
                    completeTransaction(transaction, cart);
                } else {
                    view.showAlert(Alert.AlertType.ERROR, "Error", "Insufficient payment!");
                }
            } catch (NumberFormatException e) {
                view.showAlert(Alert.AlertType.ERROR, "Invalid Input", "Please enter a valid amount!");
            }
        });
    }

    private void completeTransaction(TransactionModel transaction, ShoppingCartModel cart) {
        // 1. Reduce Stock in Inventory
        cart.getItems().forEach((product, qty) -> {
            inventory.reduceStockAfterPurchase(product, qty);
        });

        // 2. Show Receipt
        String receiptText = generateReceiptString(transaction);
        view.showReceipt(receiptText);

        // 3. Clear Cart
        cart.clearCart();

        // 4. Success message
        view.showAlert(Alert.AlertType.INFORMATION, "Success",
                "Transaction completed successfully!\nThank you for shopping!");
    }

    private String generateReceiptString(TransactionModel t) {
        return String.format(
                "Customer: %s\nDate: %s\n\nSubtotal: ₱%.2f\nVAT (12%%): ₱%.2f\n" +
                        "Discount: ₱%.2f\nTOTAL: ₱%.2f\n\nAmount Paid: ₱%.2f\nChange: ₱%.2f\n\n" +
                        "Thank you for shopping!",
                t.getCustomer().getName(), t.getFormattedTimestamp(), t.getSubtotal(),
                t.getVat(), t.getDiscount(), t.getTotalAmount(),
                t.getAmountPaid(), t.getChange()
        );
    }
}