package fromMCO1;
import java.time.LocalDate;
import java.util.Scanner;

/*
 * @param name - The name of the product
 * @param brand - The brand of the product
 * @param category - The category the product belongs to
 * @param price - The price of the product
 * @param quantityInStock - The initial quantity available in stock
 * @param expirationDate - The expiration date of the product
 * @param quantity - The quantity to add and substract to the current stock
 * 
 * 
 * @author Adriane Joaquin Marcelino
 * version 4
 */

public class ProductModel {
    private String name;
    private String brand;
    private String category;
    private Double price;
    private int quantityInStock;
    private LocalDate expirationDate;
    
    public ProductModel(String name, String brand, String category, Double price, int quantityInStock, LocalDate expirationDate) {
        this.name = name;
        this.brand = brand;
        this.category = category;
        this.price = price;
        this.quantityInStock = quantityInStock;
        this.expirationDate = expirationDate;
    }
    
    public String getName() { return name; }
    public String getBrand() { return brand; }
    public String getCategory() { return category; }
    public Double getPrice() { return price; }
    public int getQuantityInStock() { return quantityInStock; }
    public LocalDate getExpirationDate() { return expirationDate; }
    
    public void setName(String name) { this.name = name; }
    public void setBrand(String brand) { this.brand = brand; }
    public void setCategory(String category) { this.category = category; }
    public void setPrice(Double price) { this.price = price; }
    public void setQuantityInStock(int quantityInStock) { this.quantityInStock = quantityInStock; }
    public void setExpirationDate(LocalDate expirationDate) { this.expirationDate = expirationDate; }
    
    public void displayInfo()
    {
        boolean running = true;
        Scanner scanner = new Scanner(System.in);
        int choice = scanner.nextInt();
        while(running == true)
            System.out.println("=========================");
            System.out.println("===     Categories    ===");
            System.out.println("=========================");
            System.out.println("1. Food");
            System.out.println("2. Beverages");
            System.out.println("3. Toiletries");
            System.out.println("4. Cleaning");
            System.out.println("5. Medication");
            System.out.println("6. Exit");
            System.out.println("=========================");
        switch(choice) {
            case 1:
            System.out.println("=========================");
            System.out.println("===       Food        ===");
            System.out.println("=========================");
            System.out.println("1. Noodles");
            System.out.println("2. Canned Goods");
            System.out.println("3. Dairy");
            System.out.println("4. Chips");
            System.out.println("5. Snacks");
            System.out.println("6. Exit");
            System.out.println("=========================");               
                break;
            case 2:
            System.out.println("=========================");
            System.out.println("===     Beverages     ===");
            System.out.println("=========================");
            System.out.println("1. Coffee");
            System.out.println("2. Coke");
            System.out.println("3. Water");
            System.out.println("4. Milk");
            System.out.println("5. Juice");
            System.out.println("6. Exit");
            System.out.println("=========================");            
                break;
            case 3:
            System.out.println("=========================");
            System.out.println("===     Toiletries    ===");
            System.out.println("=========================");
            System.out.println("1. Tooth Brush");
            System.out.println("2. Tooth Paste");
            System.out.println("3. Body Wash");
            System.out.println("4. Shampoo");
            System.out.println("5. Deodorant");
            System.out.println("6. Alcohol");
            System.out.println("7. Exit");
            System.out.println("=========================");          
                break;
            case 4:
            System.out.println("=========================");
            System.out.println("===     Cleaning      ===");
            System.out.println("=========================");
            System.out.println("1. Paper Towel");
            System.out.println("2. Garbage Bag");
            System.out.println("3. Dishwasing Liquid");
            System.out.println("4. Sponge");
            System.out.println("5. Mop");
            System.out.println("6. Broom");
            System.out.println("7. Exit");
            System.out.println("=========================");                          
                break;
            case 5:
            System.out.println("=========================");
            System.out.println("===     Medication    ===");
            System.out.println("=========================");
            System.out.println("1. Paracetamol");
            System.out.println("2. Neozep");
            System.out.println("3. Cetirizine");
            System.out.println("4. Keramil-S");
            System.out.println("5. Betadine");
            System.out.println("6. Scott");
            System.out.println("7. Exit");
            System.out.println("========================="); 
                break;
            case 6:
                running = false;
                break;
            default:
                System.out.println("Invalid choice please try again.");
        }       
    }
    public Boolean isExpired() 
    { 
        LocalDate today = LocalDate.now();
        if (today != expirationDate){
            return false; 
        } else {
            return true;
        }
    }
    public void reduceStock(int quantity) 
    {
        this.quantityInStock -= quantity;
    }
    public void restock(int quantity) 
    {       
       this.quantityInStock += quantity;
   }
}
