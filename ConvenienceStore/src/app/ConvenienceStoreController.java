package app;

import fromMCO1.ConvenienceStoreModel;
import javafx.scene.control.Alert;
import javafx.stage.Stage;

public class ConvenienceStoreController {

    private final Stage primaryStage;
    private final ConvenienceStoreModel store;
    private final ConvenienceStoreView view;

    public ConvenienceStoreController(Stage primaryStage, ConvenienceStoreModel store) {
        this.primaryStage = primaryStage;
        this.store = store;
        this.view = new ConvenienceStoreView();
    }

    public void show() {
        // Pass the logic methods as runnables to the view
        primaryStage.setScene(view.createContent(
                this::handleCustomerMode,
                this::handleEmployeeMode,
                this::handleExit
        ));
        primaryStage.show();
    }

    private void handleCustomerMode() {
        new CustomerController(primaryStage, store).handleCustomerLogin();
    }

    private void handleEmployeeMode() {
        new EmployeeController(primaryStage, store).showEmployeeLogin();
    }

    private void handleExit() {
        // Use the store's shutdown method to save data
        store.shutdownSystem();

        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle("Exit");
        alert.setHeaderText(null);
        alert.setContentText("Data saved successfully. Goodbye!");
        alert.showAndWait();

        primaryStage.close();
    }
}
