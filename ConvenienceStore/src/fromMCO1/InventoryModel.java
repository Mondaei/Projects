package fromMCO1;
import java.io.*;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;


/*
 * @param prod - The product to be added to the inventory
 * @param name - The name of the product to restock
 * @param quantity - The quantity to add to the current stock
 * @return - in findProductByName, if the product if found, null otherwise
 * 
 * @author Keila Franchoise Leigh O. Geslani
 * version 4
 * 
 */

public class InventoryModel
{
    private List<ProductModel> products;
    private static final String INVENTORY_FILE = "inventory.txt";
    private static final int LOW_STOCK_THRESHOLD = 10;
    
    public InventoryModel()
    {
        this.products = new ArrayList<>();
    }

    // Add this method to InventoryModel.java

    /**
     * Delete all products from inventory
     * WARNING: This action cannot be undone!
     */
    public void deleteAllProducts() {
        int count = products.size();
        products.clear();
        System.out.println("All products deleted! (" + count + " items removed)");
    }

    /**
     * Get products by category
     * @param category The category to filter by
     * @return List of products in that category
     */
    public List<ProductModel> getProductsByCategory(String category) {
        List<ProductModel> filtered = new ArrayList<>();
        for (ProductModel product : products) {
            if (product.getCategory().equalsIgnoreCase(category)) {
                filtered.add(product);
            }
        }
        return filtered;
    }

    /**
     * Delete a single product from inventory
     * @param product The product to delete
     * @return true if deleted, false if not found
     */
    public boolean deleteProduct(ProductModel product) {
        if (products.remove(product)) {
            System.out.println("Product deleted: " + product.getName());
            return true;
        } else {
            System.out.println("Product not found: " + product.getName());
            return false;
        }
    }

    /**
     * Delete a product by name
     * @param productName The name of the product to delete
     * @return true if deleted, false if not found
     */
    public boolean deleteProductByName(String productName) {
        ProductModel product = findProductByName(productName);
        if (product != null) {
            return deleteProduct(product);
        }
        return false;
    }

    public void addProduct(ProductModel prod)
    {
        ProductModel existing = findProductByName(prod.getName());
        if (existing != null) 
        {
            System.out.println("Product already exists in inventory!");
            System.out.println("Use restock to add more quantity.");
            return;
        }
        
        products.add(prod);
        System.out.println("Product added successfully: " + prod.getName());
    }
    
    public void updateProductInfo(ProductModel prod)
    {
        ProductModel existing = findProductByName(prod.getName());
        
        if (existing != null) 
        {
            existing.setBrand(prod.getBrand());
            existing.setCategory(prod.getCategory());
            existing.setPrice(prod.getPrice());
            existing.setExpirationDate(prod.getExpirationDate());
            
            System.out.println("Product updated successfully: " + prod.getName());
        } else 
        {
            System.out.println("Product not found: " + prod.getName());
        }
    }
    
    public void restockProduct(String name, int quantity) 
    {
        ProductModel prod = findProductByName(name);
        
        if (prod != null) 
        {
            int oldStock = prod.getQuantityInStock();
            prod.restock(quantity);
            System.out.println(" Restocked: " + name);
            System.out.println("  Old stock: " + oldStock);
            System.out.println("  Added: " + quantity);
            System.out.println("  New stock: " + prod.getQuantityInStock());
            System.out.print("Press Enter to return to menu...");
        } else 
        {
            System.out.println(" Product not found: " + name);
        }
    }
    
    public ProductModel findProductByName(String name)
    {
        for (ProductModel prod : products)
        {
            if (prod.getName().equalsIgnoreCase(name.trim())) 
            {
                return prod;
            }
        }
        return null;
    }
    
    public void reduceStockAfterPurchase(ProductModel prod, int quantity)
    {
        ProductModel existing = findProductByName(prod.getName());
        
        if (existing != null) 
        {
            if (existing.getQuantityInStock() >= quantity) 
            {
                existing.reduceStock(quantity);
                System.out.println("Stock reduced: " + prod.getName() + " (-" + quantity + ")");
            } else 
            {
                System.out.println("Insufficient stock for: " + prod.getName());
            }
        } else 
        {
            System.out.println("Product not found in inventory");
        }
    }
    
    public List<ProductModel> getLowStockItems()
    {
        List<ProductModel> lowStockProducts = new ArrayList<>();
        
        for (ProductModel prod : products)
        {
            if (prod.getQuantityInStock() < LOW_STOCK_THRESHOLD) 
            {
                lowStockProducts.add(prod);
            }
        }
        
        return lowStockProducts;
    }
    
    public void loadInventoryFromFile() 
    {
        File file = new File(INVENTORY_FILE);
        
        if (!file.exists()) 
        {
            System.out.println("No inventory file found. Starting with empty inventory.");
            System.out.println("Creating sample products...");
            createSampleProducts();
            return;
        }
        
        try (BufferedReader br = new BufferedReader(new FileReader(INVENTORY_FILE))) 
        {
            String line;
            products.clear();
            int count = 0;
            
            while ((line = br.readLine()) != null) 
            {
                line = line.trim();
                if (line.isEmpty()) 
                {
                    continue;
                }
                
                String[] parts = line.split(",");
                
                if (parts.length == 6) 
                {
                    try 
                    {
                        String name = parts[0].trim();
                        String brand = parts[1].trim();
                        String category = parts[2].trim();
                        Double price = Double.parseDouble(parts[3].trim());
                        int quantity = Integer.parseInt(parts[4].trim());
                        LocalDate expDate = LocalDate.parse(parts[5].trim());
                        
                        ProductModel prod = new ProductModel(name, brand, category, price, quantity, expDate);
                        products.add(prod);
                        count++;
                    } catch (Exception e) 
                    {
                        System.out.println("Skipping invalid line: " + line);
                    }
                } else 
                {
                    System.out.println("Invalid format, skipping: " + line);
                }
            }
            
            System.out.println("Inventory loaded successfully!");
            System.out.println("  Total products: " + count);
            
        } catch (IOException e) 
        {
            System.out.println("Error loading inventory: " + e.getMessage());
        }
    }
    
    public void saveInventoryToFile() 
    {
        try (PrintWriter pw = new PrintWriter(new FileWriter(INVENTORY_FILE))) 
        {
            for (ProductModel prod : products)
            {
                pw.println(prod.getName() + "," + 
                          prod.getBrand() + "," + 
                          prod.getCategory() + "," + 
                          prod.getPrice() + "," + 
                          prod.getQuantityInStock() + "," + 
                          prod.getExpirationDate());
            }
            
            System.out.println("Inventory saved successfully!");
            System.out.println("  File: " + INVENTORY_FILE);
            System.out.println("  Products saved: " + products.size());
            
        } catch (IOException e) 
        {
            System.out.println("Error saving inventory: " + e.getMessage());
        }
    }
    
    public List<ProductModel> getProducts()
    {
        return products;
    }
    
    /*temporary products holder to be fixed */
    public void displayAllProducts() 
    {
        if (products.isEmpty()) 
        {
            System.out.println("No products in inventory.");
            return;
        }
        
        System.out.println("\n╔════════════════════════════════════════════════════════════════════════════╗");
        System.out.println("║                          INVENTORY LIST                                    ║");
        System.out.println("╠════╦══════════════════════════╦═══════════════╦══════════╦═════════════════╣");
        System.out.printf("║ %-2s ║ %-24s ║ %-13s ║ %-8s ║ %-15s ║%n", 
            "#", "Product Name", "Brand", "Price", "Stock");
        System.out.println("╠════╬══════════════════════════╬═══════════════╬══════════╬═════════════════╣");
        
        for (int i = 0; i < products.size(); i++) {
            ProductModel p = products.get(i);
            
            String name = p.getName().length() > 24 ? 
                         p.getName().substring(0, 21) + "..." : p.getName();
            String brand = p.getBrand().length() > 13 ? 
                          p.getBrand().substring(0, 10) + "..." : p.getBrand();
            
            String stockDisplay = String.format("%d", p.getQuantityInStock());
            if (p.getQuantityInStock() < LOW_STOCK_THRESHOLD) {
                stockDisplay = stockDisplay + " LOW";
            }
            
            System.out.printf("║ %-2d ║ %-24s ║ %-13s ║ %-7.2f ║ %-15s ║%n", 
                (i + 1), name, brand, p.getPrice(), stockDisplay);
        }
        
        System.out.println("╚════╩══════════════════════════╩═══════════════╩══════════╩═════════════════╝");
        System.out.println("Total products: " + products.size());
        
        List<ProductModel> lowStock = getLowStockItems();
        if (!lowStock.isEmpty()) {
            System.out.println(lowStock.size() + " product(s) have low stock!");
        }
    }
    
    /*temporary products holder to be fixed */
    private void createSampleProducts() 
    {
        products.add(new ProductModel("Coke 1.5L", "Coca-Cola", "Beverages", 65.0, 50, LocalDate.of(2026, 12, 31)));
        products.add(new ProductModel("Lucky Me Pancit Canton", "Lucky Me", "Instant Noodles", 15.0, 100, LocalDate.of(2025, 12, 31)));
        products.add(new ProductModel("Argentina Corned Beef", "Argentina", "Canned Goods", 45.0, 30, LocalDate.of(2026, 6, 30)));
        products.add(new ProductModel("Eden Cheese", "Eden", "Dairy", 95.0, 8, LocalDate.of(2025, 11, 15)));
        products.add(new ProductModel("Nescafe 3in1", "Nescafe", "Coffee", 8.0, 80, LocalDate.of(2026, 3, 31)));
        products.add(new ProductModel("Skyflakes Crackers", "Skyflakes", "Snacks", 32.0, 5, LocalDate.of(2025, 12, 1)));
        products.add(new ProductModel("Alaska Evap Milk", "Alaska", "Dairy", 28.0, 60, LocalDate.of(2026, 1, 31)));
        products.add(new ProductModel("Spam Classic", "Spam", "Canned Goods", 185.0, 15, LocalDate.of(2027, 3, 15)));
        
        System.out.println("Sample products created: " + products.size());
    }
    
    public void displayProductDetails() 
    {
        if (products.isEmpty()) 
        {
            System.out.println("No products in inventory.");
            return;
        }
        
        System.out.println("\n========== DETAILED PRODUCT INFORMATION ==========");
        for (int i = 0; i < products.size(); i++) 
        {
            System.out.println("\n[Product #" + (i + 1) + "]");
            products.get(i).displayInfo();
        }
    }
}
