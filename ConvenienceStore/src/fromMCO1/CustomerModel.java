package fromMCO1;

import java.io.*;
import java.util.HashMap;
import java.util.Map;

/**
 * Customer in the convenience store system.
 * Manages shopping cart, membership, and customer information.
 *
 * @author Adriane Joaquin Marcelino
 * @version 4 (Added persistence)
 */
public class CustomerModel {
    private ShoppingCartModel shoppingCart;
    private MembershipCardModel membership;
    private String name;
    private boolean isSenior;

    private static final String CUSTOMER_DATA_FILE = "customers.txt";

    public CustomerModel(String name, boolean isSenior) {
        this.name = name;
        this.isSenior = isSenior;
        this.shoppingCart = new ShoppingCartModel();
        this.membership = new MembershipCardModel();

        loadCustomerData();
    }

    public ShoppingCartModel getShoppingCart() { return shoppingCart; }
    public MembershipCardModel getMembership() { return membership; }
    public String getName() { return name; }
    public boolean isSenior() { return isSenior; }

    public void addToCart(ProductModel prod, int quantity) {
        shoppingCart.addItem(prod, quantity);
    }

    public void removeFromCart(ProductModel prod) {
        shoppingCart.removeItem(prod);
    }

    public Double viewTotalCost() {
        return shoppingCart.calculateSubtotal();
    }

    // ============================================
    // PERSISTENCE METHODS
    // ============================================

    /**
     * Load customer data from file if exists
     */
    private void loadCustomerData() {
        Map<String, CustomerData> customers = loadAllCustomers();

        // Create a unique key (name + senior status)
        String key = createCustomerKey();

        if (customers.containsKey(key)) {
            CustomerData data = customers.get(key);
            this.membership.setPoints(data.points);
            System.out.println("Welcome back, " + name + "! Points loaded: " + data.points);
        } else {
            System.out.println("New customer: " + name);
        }
    }

    /**
     * Save customer data when exiting
     */
    public void saveCustomerData() {
        Map<String, CustomerData> customers = loadAllCustomers();

        // Update or add this customer's data
        String key = createCustomerKey();
        customers.put(key, new CustomerData(name, isSenior, membership.getPoints()));

        // Save all customers to file
        saveAllCustomers(customers);
        System.out.println("Customer data saved for: " + name + " (Points: " + membership.getPoints() + ")");
    }

    /**
     * Create unique key for this customer
     */
    private String createCustomerKey() {
        return name.toLowerCase().trim() + "|" + isSenior;
    }

    /**
     * Load all customers from file
     */
    private static Map<String, CustomerData> loadAllCustomers() {
        Map<String, CustomerData> customers = new HashMap<>();
        File file = new File(CUSTOMER_DATA_FILE);

        if (!file.exists()) {
            return customers;
        }

        try (BufferedReader br = new BufferedReader(new FileReader(file))) {
            String line;
            while ((line = br.readLine()) != null) {
                line = line.trim();
                if (line.isEmpty()) continue;

                // Format: name|isSenior|points
                String[] parts = line.split("\\|");
                if (parts.length == 3) {
                    String name = parts[0];
                    boolean isSenior = Boolean.parseBoolean(parts[1]);
                    int points = Integer.parseInt(parts[2]);

                    String key = name.toLowerCase().trim() + "|" + isSenior;
                    customers.put(key, new CustomerData(name, isSenior, points));
                }
            }
        } catch (IOException e) {
            System.out.println("Error loading customer data: " + e.getMessage());
        }

        return customers;
    }

    /**
     * Save all customers to file
     */
    private static void saveAllCustomers(Map<String, CustomerData> customers) {
        try (PrintWriter pw = new PrintWriter(new FileWriter(CUSTOMER_DATA_FILE))) {
            for (CustomerData data : customers.values()) {
                // Format: name|isSenior|points
                pw.println(data.name + "|" + data.isSenior + "|" + data.points);
            }
        } catch (IOException e) {
            System.out.println("Error saving customer data: " + e.getMessage());
        }
    }

    /**
     * Inner class to hold customer data
     */
    private static class CustomerData {
        String name;
        boolean isSenior;
        int points;

        CustomerData(String name, boolean isSenior, int points) {
            this.name = name;
            this.isSenior = isSenior;
            this.points = points;
        }
    }
}