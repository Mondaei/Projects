package app;

import fromMCO1.ConvenienceStoreModel;
import javafx.application.Application;
import javafx.stage.Stage;

/**
 * Main Entry Point for the Convenience Store System.
 * This class serves as the "Run" file for the entire application.
 * It initializes the core System Model and launches the Main Menu.
 *
 * @author Keila Franchoise Leigh Geslani
 * @version 7 (Renamed to Main for clarity)
 */
public class Main extends Application {

    @Override
    public void start(Stage primaryStage) {
        // 1. Initialize the System Model (The "Whole" Application Data)
        // This object holds your inventory, store name, and logic.
        ConvenienceStoreModel store = new ConvenienceStoreModel("De La Salle Convenience Store");
        store.initializeSystem(); // Loads inventory from file

        // 2. Configure the Main Window (The Stage)
        primaryStage.setTitle(store.getStoreName() + " System");
        primaryStage.setWidth(600);
        primaryStage.setHeight(500);

        // 3. Hand over control to the Main Menu Controller
        // The controller will determine what screens to show (Customer vs Employee)
        ConvenienceStoreController menuController = new ConvenienceStoreController(primaryStage, store);
        menuController.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
