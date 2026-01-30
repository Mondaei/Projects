package fromMCO1;

import java.util.HashMap;
import java.util.Map;

/**
 * Represents a shopping cart in the convenience store system.
 * Manages items added by customers and calculates totals.
 *
 * @param prod - The product to add or remove from the shopping cart
 * @param quantity - The quantity of the product to add
 *
 * @author Keila Franchoise Leigh O. Geslani
 * @version 5
 */
public class ShoppingCartModel {
    private Map<ProductModel, Integer> items;

    /**
     * Constructor - Initializes empty shopping cart
     */
    public ShoppingCartModel() {
        items = new HashMap<>();
    }

    /**
     * Get all items in the cart
     * @return Map of products and their quantities
     */
    public Map<ProductModel, Integer> getItems() {
        return items;
    }

    /**
     * Add item to cart with stock validation
     * @param prod - The product to add
     * @param quantity - The quantity to add
     */
    public void addItem(ProductModel prod, int quantity) {
        // Validation 1: Check if product is expired
        if (prod.isExpired()) {
            System.out.println("Cannot add expired product!");
            return;
        }

        // Validation 2: Check if sufficient stock available
        if (quantity > prod.getQuantityInStock()) {
            System.out.println("Insufficient stock!");
            System.out.println("Requested: " + quantity + ", Available: " + prod.getQuantityInStock());
            return;
        }

        // Validation 3: Check if adding more would exceed stock
        if (items.containsKey(prod)) {
            int currentInCart = items.get(prod);
            int totalRequested = currentInCart + quantity;

            if (totalRequested > prod.getQuantityInStock()) {
                System.out.println("Cannot add " + quantity + " more units!");
                System.out.println("Already in cart: " + currentInCart);
                System.out.println("Available stock: " + prod.getQuantityInStock());
                System.out.println("Maximum you can add: " + (prod.getQuantityInStock() - currentInCart));
                return;
            }

            // Update quantity
            items.put(prod, totalRequested);
            System.out.println("Updated cart: " + prod.getName() + " (Total: " + totalRequested + ")");
        } else {
            // Add new item
            items.put(prod, quantity);
            System.out.println("Added to cart: " + prod.getName() + " x" + quantity);
        }
    }

    /**
     * Remove item completely from cart
     * @param prod - The product to remove
     */
    public void removeItem(ProductModel prod) {
        if (items.containsKey(prod)) {
            items.remove(prod);
            System.out.println("Removed from cart: " + prod.getName());
        } else {
            System.out.println("Product not found in cart!");
        }
    }

    /**
     * Calculate subtotal (before tax and discounts)
     * @return Total price of all items in cart
     */
    public Double calculateSubtotal() {
        double subtotal = 0.0;
        for (Map.Entry<ProductModel, Integer> entry : items.entrySet()) {
            ProductModel product = entry.getKey();
            int quantity = entry.getValue();
            subtotal += product.getPrice() * quantity;
        }
        return subtotal;
    }

    /**
     * Display cart contents in console
     */
    public void displayCart() {
        if (items.isEmpty()) {
            System.out.println("\n===== SHOPPING CART =====");
            System.out.println("Cart is empty.");
            System.out.println("=========================\n");
            return;
        }

        System.out.println("\n╔════════════════════════════════════════════════════════╗");
        System.out.println("║                   SHOPPING CART                        ║");
        System.out.println("╠════════════════════════════════════════════════════════╣");

        for (Map.Entry<ProductModel, Integer> entry : items.entrySet()) {
            ProductModel p = entry.getKey();
            int qty = entry.getValue();
            double lineTotal = p.getPrice() * qty;

            System.out.printf("║ %-30s x%-3d  ₱%8.2f ║%n",
                    p.getName(), qty, lineTotal);
        }

        System.out.println("╠════════════════════════════════════════════════════════╣");
        System.out.printf("║ SUBTOTAL:                              ₱%8.2f ║%n",
                calculateSubtotal());
        System.out.println("╚════════════════════════════════════════════════════════╝\n");
    }

    /**
     * Clear all items from cart
     */
    public void clearCart() {
        items.clear();
        System.out.println("Cart cleared.");
    }

    /**
     * Check if cart is empty
     * @return true if cart has no items, false otherwise
     */
    public boolean isEmpty() {
        return items.isEmpty();
    }

    /**
     * Get total number of items in cart (counting quantities)
     * @return Total item count
     */
    public int getTotalItemCount() {
        int total = 0;
        for (int quantity : items.values()) {
            total += quantity;
        }
        return total;
    }

    /**
     * Get number of unique products in cart
     * @return Number of different products
     */
    public int getUniqueProductCount() {
        return items.size();
    }

    /**
     * Check if a specific product is in the cart
     * @param prod - The product to check
     * @return true if product is in cart, false otherwise
     */
    public boolean contains(ProductModel prod) {
        return items.containsKey(prod);
    }

    /**
     * Get quantity of a specific product in cart
     * @param prod - The product to check
     * @return Quantity in cart, or 0 if not in cart
     */
    public int getQuantity(ProductModel prod) {
        return items.getOrDefault(prod, 0);
    }

    /**
     * Update quantity of existing item in cart
     * @param prod - The product to update
     * @param newQuantity - The new quantity
     * @return true if successful, false if validation fails
     */
    public boolean updateQuantity(ProductModel prod, int newQuantity) {
        if (!items.containsKey(prod)) {
            System.out.println("Product not in cart!");
            return false;
        }

        if (newQuantity <= 0) {
            removeItem(prod);
            return true;
        }

        if (newQuantity > prod.getQuantityInStock()) {
            System.out.println("Cannot update to " + newQuantity + " units!");
            System.out.println("Available stock: " + prod.getQuantityInStock());
            return false;
        }

        items.put(prod, newQuantity);
        System.out.println("Updated " + prod.getName() + " quantity to: " + newQuantity);
        return true;
    }

    /**
     * Get formatted cart summary for display
     * @return String representation of cart
     */
    @Override
    public String toString() {
        if (items.isEmpty()) {
            return "Empty Cart";
        }

        StringBuilder sb = new StringBuilder();
        sb.append("Shopping Cart:\n");
        for (Map.Entry<ProductModel, Integer> entry : items.entrySet()) {
            sb.append(String.format("  %s x%d - ₱%.2f%n",
                    entry.getKey().getName(),
                    entry.getValue(),
                    entry.getKey().getPrice() * entry.getValue()));
        }
        sb.append(String.format("Subtotal: ₱%.2f", calculateSubtotal()));
        return sb.toString();
    }
}