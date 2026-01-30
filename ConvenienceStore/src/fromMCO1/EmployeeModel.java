package fromMCO1;
/*
 * Employee in the system. It handles the inventory management operations including adding products,
 * restocking, and updating product information.
 * 
 * @param name - The name of the employee
 * @param employeeId - The unique employee identification number
 * @param inventory - The inventory system to add the product to
 * @param prod - The product to be added to the inventory
 * @param productName - The name of the product to restock
 * @param quantity - The quantity to add to the product stock
 * 
 * @author Keila Franchoise Leigh O. Geslani
 * @version 3
 */

public class EmployeeModel
{
    private String name;
    private String employeeId;
    
    public EmployeeModel(String name, String employeeId)
    {
        this.name = name;
        this.employeeId = employeeId;
    }
    
    public String getName() 
    {
        return name;
    }
    
    public String getEmployeeId() 
    {
        return employeeId;
    }
    
    public void addProduct(InventoryModel inventory, ProductModel prod)
    {
        System.out.println("[Employee " + name + "] Adding product to inventory...");
        inventory.addProduct(prod);
    }
    
    public void restock(InventoryModel inventory, String productName, int quantity)
    {
        System.out.println("[Employee " + name + "] Restocking product: " + productName);
        inventory.restockProduct(productName, quantity);
    }
    
    public void updateProduct(InventoryModel inventory, ProductModel prod)
    {
        System.out.println("[Employee " + name + "] Updating product information...");
        inventory.updateProductInfo(prod);
    }
}