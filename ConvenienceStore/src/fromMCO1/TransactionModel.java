package fromMCO1;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

/*
 * @param customer - The customer making the transaction
 * @param cart - The shopping cart containing items to purchase
 * @param discount - The discount amount to apply to the transaction
 * @param amountPaid - The amount of money paid by the customer
 * @return - in processPayment, true if payment is sufficient, false otherwise
 */

public class TransactionModel
{
    private CustomerModel customer;
    private ShoppingCartModel cart;
    private double totalAmount;
    private double vat;
    private double discount;
    private double amountPaid;
    private double change;
    private LocalDateTime timestamp;
    
    private static final double VAT_RATE = 0.12; 
    private static final double SENIOR_DISCOUNT = 0.20; 
    private static final double MEMBERSHIP_DISCOUNT = 0.05; 
    
    public TransactionModel(CustomerModel customer, ShoppingCartModel cart)
    {
        this.customer = customer;
        this.cart = cart;
        this.timestamp = LocalDateTime.now();
        this.discount = 0;
        this.amountPaid = 0;
        this.change = 0;
        calculateTotal();
    }
    
    public CustomerModel getCustomer()
    { 
        return customer; 
    }
    
    public ShoppingCartModel getCart()
    { 
        return cart; 
    }
    
    public double getTotalAmount() 
    { 
        return totalAmount; 
    }
    
    public double getVat() 
    { 
        return vat; 
    }
    
    public double getDiscount() 
    { 
        return discount; 
    }
    
    public double getAmountPaid() 
    { 
        return amountPaid; 
    }
    
    public double getChange() 
    { 
        return change; 
    }
    
    public LocalDateTime getTimestamp() 
    { 
        return timestamp; 
    }
    
    public void setDiscount(double discount) 
    {
        this.discount = discount;
        calculateTotal();
    }
    
    public void calculateTotal() 
    {
        double subtotal = cart.calculateSubtotal();
        
        vat = subtotal * VAT_RATE;
        
        totalAmount = subtotal + vat - discount;
        
        if (totalAmount < 0) 
        {
            totalAmount = 0;
        }
    }
    
    public void applyMembershipDiscount() 
    {
        if (customer.getMembership().getPoints() <= 0) 
        {
            System.out.println("No membership points available for discount.");
            return;
        }
        
        double subtotal = cart.calculateSubtotal();
        double memberDiscount = subtotal * MEMBERSHIP_DISCOUNT;
        discount += memberDiscount;
        
        System.out.println("Membership discount applied: " + String.format("%.2f", memberDiscount));
        calculateTotal();
    }
    
    public void applySeniorDiscount() 
    {
        if (!customer.isSenior()) 
        {
            System.out.println("Customer is not a senior citizen.");
            return;
        }
        
        double subtotal = cart.calculateSubtotal();
        double seniorDiscount = subtotal * SENIOR_DISCOUNT;
        discount += seniorDiscount;
        
        vat = 0;
        
        System.out.println("Senior citizen discount applied: " + String.format("%.2f", seniorDiscount));
        System.out.println("VAT exemption applied");
        calculateTotal();
    }
    
    public boolean processPayment(double amountPaid) 
    {
        this.amountPaid = amountPaid;
        
        if (amountPaid < totalAmount) {
            System.out.println("\nINSUFFICIENT PAYMENT!");
            System.out.println("╔════════════════════════════════════════╗");
            System.out.printf("║ Amount Due:  %-24.2f ║%n", totalAmount);
            System.out.printf("║ Amount Paid: %-24.2f ║%n", amountPaid);
            System.out.printf("║ Short by:    %-24.2f ║%n", totalAmount - amountPaid);
            System.out.println("╚════════════════════════════════════════╝");
            return false;
        }
        
        change = amountPaid - totalAmount;
        
        customer.getMembership().addPoints(totalAmount);
        
        System.out.println("\n╔════════════════════════════════════════╗");
        System.out.println("║         PAYMENT SUCCESSFUL!            ║");
        System.out.println("╠════════════════════════════════════════╣");
        System.out.printf("║ Total:   %-28.2f ║%n", totalAmount);
        System.out.printf("║ Paid:    %-28.2f ║%n", amountPaid);
        System.out.printf("║ Change:  %-28.2f ║%n", change);
        System.out.println("╚════════════════════════════════════════╝");
        
        return true;
    }
    
    public ReceiptModel generateReceipt()
    {
        return new ReceiptModel(this);
    }
    
    public void displaySummary() 
    {
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
        
        System.out.println("\n╔════════════════════════════════════════════════════════╗");
        System.out.println("║              TRANSACTION SUMMARY                       ║");
        System.out.println("╠════════════════════════════════════════════════════════╣");
        System.out.println("║ Customer: " + String.format("%-42s", customer.getName()) + "║");
        System.out.println("║ Date: " + String.format("%-47s", timestamp.format(formatter)) + "║");
        
        if (customer.isSenior()) 
        {
            System.out.println("║ Senior Citizen: YES                                    ║");
        }
        
        System.out.println("╠════════════════════════════════════════════════════════╣");
        System.out.printf("║ Subtotal:        %-37.2f ║%n", cart.calculateSubtotal());
        System.out.printf("║ VAT (12%%):       %-37.2f ║%n", vat);
        
        if (discount > 0) 
        {
            System.out.printf("║ Discount:       -%-37.2f ║%n", discount);
        }
        
        System.out.println("╠════════════════════════════════════════════════════════╣");
        System.out.printf("║ TOTAL AMOUNT:    %-37.2f ║%n", totalAmount);
        
        if (amountPaid > 0) 
        {
            System.out.printf("║ Amount Paid:     %-37.2f ║%n", amountPaid);
            System.out.printf("║ Change:          %-37.2f ║%n", change);
        }
        
        System.out.println("╚════════════════════════════════════════════════════════╝");
    }
    
    public double getSubtotal() 
    {
        return cart.calculateSubtotal();
    }
    
    public boolean isComplete() 
    {
        return amountPaid >= totalAmount && amountPaid > 0;
    }
    
    public String getFormattedTimestamp() 
    {
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
        return timestamp.format(formatter);
    }
    
    public void displayPaymentBreakdown() 
    {
        System.out.println("\n╔════════════════════════════════════════╗");
        System.out.println("║       PAYMENT BREAKDOWN                ║");
        System.out.println("╠════════════════════════════════════════╣");
        System.out.printf("║ Items Total:     %-20.2f ║%n", cart.calculateSubtotal());
        System.out.printf("║ VAT (12%%):       %-20.2f ║%n", vat);
        System.out.printf("║ Subtotal:        %-20.2f ║%n", cart.calculateSubtotal() + vat);
        
        if (discount > 0) 
        {
            System.out.printf("║ Discount:       -%-20.2f ║%n", discount);
        }
        
        System.out.println("╠════════════════════════════════════════╣");
        System.out.printf("║ AMOUNT DUE:      %-20.2f ║%n", totalAmount);
        System.out.println("╚════════════════════════════════════════╝");
    }
}