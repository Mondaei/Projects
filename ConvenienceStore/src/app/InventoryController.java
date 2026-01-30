package app;

import fromMCO1.*;
import java.util.List;

public class InventoryController {

    private final InventoryModel inventory;
    private final InventoryView view;

    public InventoryController(InventoryModel inventory) {
        this.inventory = inventory;
        this.view = new InventoryView();
    }

    public void showLowStockDialog() {
        // 1. Get Data (Business Logic)
        List<ProductModel> lowStockItems = inventory.getLowStockItems();

        // 2. Pass Data to View
        view.showLowStockAlert(lowStockItems);
    }
}
