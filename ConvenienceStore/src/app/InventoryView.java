package app;

import fromMCO1.*;
import javafx.scene.control.Alert;
import javafx.scene.control.TextArea;
import java.util.List;

public class InventoryView {

    public void showLowStockAlert(List<ProductModel> lowStockItems) {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle("Low Stock Items");
        alert.setHeaderText("Products with stock below 10");

        if (lowStockItems.isEmpty()) {
            alert.setContentText("No low stock items found.");
        } else {
            // Presentation Logic: Formatting the data into a readable string
            StringBuilder content = new StringBuilder();
            for (ProductModel p : lowStockItems) {
                content.append(String.format("%s - Stock: %d\n",
                        p.getName(), p.getQuantityInStock()));
            }

            TextArea textArea = new TextArea(content.toString());
            textArea.setEditable(false);
            textArea.setWrapText(true);
            textArea.setPrefRowCount(10);

            alert.getDialogPane().setContent(textArea);
        }

        alert.showAndWait();
    }
}