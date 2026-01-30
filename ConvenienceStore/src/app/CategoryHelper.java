package app;

import java.util.*;

/**
 * Helper class for managing product categories
 * @author Keila Geslani
 * @version 3.0
 */
public class CategoryHelper {

    // Five main categories
    private static final List<String> CATEGORIES = Arrays.asList(
            "Food",
            "Beverages",
            "Toiletries",
            "Cleaning Products",
            "Medications"
    );

    /**
     * Get all categories
     */
    public static List<String> getCategories() {
        return new ArrayList<>(CATEGORIES);
    }

    /**
     * Check if category is valid
     */
    public static boolean isValidCategory(String category) {
        return CATEGORIES.contains(category);
    }
}