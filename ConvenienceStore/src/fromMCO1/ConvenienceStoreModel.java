package fromMCO1;

/**
 * Represents the Convenience Store System (Model).
 * This class acts as the primary data container for the application,
 * holding the Inventory and Store details.
 */
public class ConvenienceStoreModel {

    private final String storeName;
    private final InventoryModel inventory;

    public ConvenienceStoreModel(String storeName) {
        this.storeName = storeName;
        this.inventory = new InventoryModel();
    }

    public String getStoreName() {
        return storeName;
    }

    public InventoryModel getInventory() {
        return inventory;
    }

    // Delegate methods for data persistence
    public void initializeSystem() {
        inventory.loadInventoryFromFile();
    }

    public void shutdownSystem() {
        inventory.saveInventoryToFile();
    }
}
