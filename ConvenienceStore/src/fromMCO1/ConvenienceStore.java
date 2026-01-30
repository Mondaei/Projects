package fromMCO1;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/*
 * Manages the convenience store operations including customer purchases,
 * employee inventory management, and sales reporting.
 * @param customer The customer whose cart will receive the product
 * @param employee The employee performing the operation
 * 
 * @author Keila Franchoise Leigh Geslani
 * Version 3
 */
public class ConvenienceStore 
{
    private InventoryModel inventory;
    private List<TransactionModel> salesHistory;
    private Scanner scanner;
    
    public ConvenienceStore() 
    {
        this.inventory = new InventoryModel();
        this.salesHistory = new ArrayList<>();
        this.scanner = new Scanner(System.in);
    }
    
    public static void main(String[] args) 
    {
        ConvenienceStore store = new ConvenienceStore();
        store.loadData();
        store.showMainMenu();
    }
    
    public void showMainMenu() 
    {
        while (true) 
        {
            System.out.println("\n╔════════════════════════════════════════╗");
            System.out.println("║    CONVENIENCE STORE SYSTEM            ║");
            System.out.println("╠════════════════════════════════════════╣");
            System.out.println("║  1. Customer Mode                      ║");
            System.out.println("║  2. Employee Mode                      ║");
            System.out.println("║  3. Save & Exit                        ║");
            System.out.println("╚════════════════════════════════════════╝");
            System.out.print("Select option: ");
            
            try 
            {
                int choice = scanner.nextInt();
                scanner.nextLine(); 
                
                switch (choice) {
                    case 1:
                        customer();
                        break;
                    case 2:
                        employee();
                        break;
                    case 3:
                        saveData();
                        System.out.println("Thank you! Goodbye!");
                        return;
                    default:
                        System.out.println("Invalid option. Try again.");
                }
            } catch (Exception e) 
            {
                System.out.println("Invalid input. Please enter a number.");
                scanner.nextLine();
            }
        }
    }
    
    public void customer() 
    {
        System.out.print("Enter customer name: ");
        String name = scanner.nextLine();
        
        System.out.print("Are you a senior citizen? (y/n): ");
        boolean isSenior = scanner.nextLine().trim().equalsIgnoreCase("y");
        
        CustomerModel customer = new CustomerModel(name, isSenior);
        
        while (true) 
        {
            System.out.println("\n╔════════════════════════════════════════╗");
            System.out.println("║         CUSTOMER MENU                  ║");
            System.out.println("╠════════════════════════════════════════╣");
            System.out.println("║  1. View Products                      ║");
            System.out.println("║  2. Add Product to Cart                ║");
            System.out.println("║  3. View Cart                          ║");
            System.out.println("║  4. Remove from Cart                   ║");
            System.out.println("║  5. View Total Cost                    ║");
            System.out.println("║  6. Proceed to Checkout                ║");
            System.out.println("║  7. View Membership Points             ║");
            System.out.println("║  8. Back to Main Menu                  ║");
            System.out.println("╚════════════════════════════════════════╝");
            System.out.print("Select option: ");
            
            try 
            {
                int choice = scanner.nextInt();
                scanner.nextLine();
                
                switch (choice) 
                {
                    case 1:
                        inventory.displayAllProducts();
                        break;
                    case 2:
                        addProductToCart(customer);
                        break;
                    case 3:
                        customer.getShoppingCart().displayCart();
                        break;
                    case 4:
                        removeProductFromCart(customer);
                        break;
                    case 5:
                        customer.viewTotalCost();
                        break;
                    case 6:
                        performCheckout(customer);
                        return; 
                    case 7:
                        customer.getMembership().displayPoints();
                        break;
                    case 8:
                        return;
                    default:
                        System.out.println("Invalid option.");
                }
            } catch (Exception e) 
            {
                System.out.println("Invalid input.");
                scanner.nextLine();
            }
        }
    }
    
    private void addProductToCart(CustomerModel customer)
    {
        inventory.displayAllProducts();
        System.out.print("\nEnter product name: ");
        String productName = scanner.nextLine();
        
        ProductModel prod = inventory.findProductByName(productName);
        if (prod == null) {
            System.out.println("Product not found!");
            return;
        }
        
        System.out.print("Enter quantity: ");
        int quantity = scanner.nextInt();
        scanner.nextLine();
        
        customer.addToCart(prod, quantity);
    }
    
    private void removeProductFromCart(CustomerModel customer)
    {
        customer.getShoppingCart().displayCart();
        System.out.print("\nEnter product name to remove: ");
        String productName = scanner.nextLine();
        
        ProductModel prod = inventory.findProductByName(productName);
        if (prod != null) 
        {
            customer.removeFromCart(prod);
        } else 
        {
            System.out.println("Product not found!");
        }
    }
    
    public void performCheckout(CustomerModel customer)
    {
        if (customer.getShoppingCart().isEmpty()) 
        {
            System.out.println("Cart is empty! Cannot checkout.");
            return;
        }
        
        customer.getShoppingCart().displayCart();
        
        TransactionModel transaction = new TransactionModel(customer, customer.getShoppingCart());
        
        if (customer.isSenior()) {
            transaction.applySeniorDiscount();
        }
        
        System.out.print("\nApply membership discount? (y/n): ");
        if (scanner.nextLine().trim().equalsIgnoreCase("y")) {
            transaction.applyMembershipDiscount();
        }
        
        System.out.print("\nRedeem membership points? (y/n): ");
        if (scanner.nextLine().trim().equalsIgnoreCase("y")) {
            double redemption = customer.getMembership().redeemPoints(transaction.getTotalAmount());
            transaction.calculateTotal();
        }
        
        System.out.println("\nTotal Amount: ₱" + String.format("%.2f", transaction.getTotalAmount()));
        System.out.print("Enter amount paid: ₱");
        
        try {
            double amountPaid = scanner.nextDouble();
            scanner.nextLine();
            
            if (transaction.processPayment(amountPaid))
            {
                for (var entry : customer.getShoppingCart().getItems().entrySet()) 
                {
                    inventory.reduceStockAfterPurchase(entry.getKey(), entry.getValue());
                }
                
                ReceiptModel receipt = transaction.generateReceipt();
                receipt.displayReceipt();
                receipt.saveReceiptToFile();
                
                salesHistory.add(transaction);
                
                customer.getShoppingCart().clearCart();
            }
        } catch (Exception e) 
        {
            System.out.println("Invalid amount entered.");
            scanner.nextLine();
        }
    }
    
    public void employee() 
    {
        System.out.print("Enter employee name: ");
        String name = scanner.nextLine();
        System.out.print("Enter employee ID: ");
        String id = scanner.nextLine();
        
        EmployeeModel employee = new EmployeeModel(name, id);
        
        while (true) 
        {
            System.out.println("\n╔════════════════════════════════════════╗");
            System.out.println("║         EMPLOYEE MENU                  ║");
            System.out.println("╠════════════════════════════════════════╣");
            System.out.println("║  1. View All Products                  ║");
            System.out.println("║  2. Add New Product                    ║");
            System.out.println("║  3. Restock Product                    ║");
            System.out.println("║  4. Update Product Info                ║");
            System.out.println("║  5. View Low Stock Items               ║");
            System.out.println("║  6. View Sales Report                  ║");
            System.out.println("║  7. Back to Main Menu                  ║");
            System.out.println("╚════════════════════════════════════════╝");
            System.out.print("Select option: ");
            
            try 
            {
                int choice = scanner.nextInt();
                scanner.nextLine();
                
                switch (choice) {
                    case 1:
                        inventory.displayAllProducts();
                        break;
                    case 2:
                        addNewProduct(employee);
                        break;
                    case 3:
                        restockProduct(employee);
                        break;
                    case 4:
                        updateProductInfo(employee);
                        break;
                    case 5:
                        displayLowStockItems();
                        break;
                    case 6:
                        displaySalesReport();
                        break;
                    case 7:
                        return;
                    default:
                        System.out.println("Invalid option.");
                }
            } catch (Exception e) 
            {
                System.out.println("Invalid input.");
                scanner.nextLine();
            }
        }
    }
    
    private void addNewProduct(EmployeeModel employee) {
        System.out.print("Product name: ");
        String name = scanner.nextLine();
        System.out.print("Brand: ");
        String brand = scanner.nextLine();
        System.out.print("Category: ");
        String category = scanner.nextLine();
        System.out.print("Price: ");
        double price = scanner.nextDouble();
        System.out.print("Quantity: ");
        int quantity = scanner.nextInt();
        scanner.nextLine();
        System.out.print("Expiration date (YYYY-MM-DD): ");
        String dateStr = scanner.nextLine();
        
        LocalDate expDate = LocalDate.parse(dateStr);
        ProductModel prod = new ProductModel(name, brand, category, price, quantity, expDate);
        employee.addProduct(inventory, prod);
    }
    
    private void restockProduct(EmployeeModel employee)
    {
        inventory.displayAllProducts();
        System.out.print("Enter product name to restock: ");
        String name = scanner.nextLine();
        System.out.print("Enter quantity to add: ");
        int quantity = scanner.nextInt();
        scanner.nextLine();
        
        employee.restock(inventory, name, quantity);
    }
    
    private void updateProductInfo(EmployeeModel employee)
    {
        inventory.displayAllProducts();
        System.out.print("Enter product name to update: ");
        String name = scanner.nextLine();
        
        ProductModel existing = inventory.findProductByName(name);
        if (existing == null) 
        {
            System.out.println("Product not found!");
            return;
        }
        
        System.out.print("New brand (current: " + existing.getBrand() + "): ");
        String brand = scanner.nextLine();
        System.out.print("New category (current: " + existing.getCategory() + "): ");
        String category = scanner.nextLine();
        System.out.print("New price (current: " + existing.getPrice() + "): ");
        double price = scanner.nextDouble();
        scanner.nextLine();
        System.out.print("New expiration (current: " + existing.getExpirationDate() + "): ");
        String dateStr = scanner.nextLine();
        
        LocalDate expDate = LocalDate.parse(dateStr);
        ProductModel updated = new ProductModel(name, brand, category, price, existing.getQuantityInStock(), expDate);
        employee.updateProduct(inventory, updated);
    }
    
    private void displayLowStockItems() 
    {
        List<ProductModel> lowStock = inventory.getLowStockItems();
        if (lowStock.isEmpty()) 
        {
            System.out.println("No low stock items.");
            return;
        }
        
        System.out.println("\n===== LOW STOCK ALERT =====");
        for (ProductModel p : lowStock)
        {
            System.out.println(p.getName() + " - Stock: " + p.getQuantityInStock());
        }
    }
    
    public void displaySalesReport() 
    {
        if (salesHistory.isEmpty()) 
        {
            System.out.println("No sales recorded yet.");
            return;
        }
        
        System.out.println("\n╔════════════════════════════════════════════════════════╗");
        System.out.println("║                    SALES REPORT                        ║");
        System.out.println("╠════════════════════════════════════════════════════════╣");
        
        double totalSales = 0;
        int totalTransactions = salesHistory.size();
        
        for (int i = 0; i < salesHistory.size(); i++) 
        {
            TransactionModel t = salesHistory.get(i);
            totalSales += t.getTotalAmount();
            System.out.printf("║ #%-3d | %-20s | %-10.2f | %s ║%n", 
                (i + 1), 
                t.getCustomer().getName(), 
                t.getTotalAmount(),
                t.getTimestamp().toLocalDate());
        }
        
        System.out.println("╠════════════════════════════════════════════════════════╣");
        System.out.printf("║ Total Transactions: %-35d ║%n", totalTransactions);
        System.out.printf("║ Total Sales: ₱%-41.2f ║%n", totalSales);
        System.out.printf("║ Average Sale: ₱%-40.2f ║%n", totalSales / totalTransactions);
        System.out.println("╚════════════════════════════════════════════════════════╝");
    }
    
    public void saveData() 
    {
        inventory.saveInventoryToFile();
        System.out.println("All data saved successfully.");
    }
    
    public void loadData() 
    {
        inventory.loadInventoryFromFile();
        System.out.println("Data loaded successfully.");
    }
}