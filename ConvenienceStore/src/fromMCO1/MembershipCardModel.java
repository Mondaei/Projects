package fromMCO1;
/*
 * This is for the membership card.
 * @param points - The number of points to set for the membership card
 * @param totalAmount - The total purchase amount used to calculate earned points
 * @return - in redeemPoints, if the new total amount after applying the point discount
 *
 * @author Adriane Joaquin Marcelino
 * version 5
 */

public class MembershipCardModel {
    private int points;

    public MembershipCardModel() {
        this.points = 0;
    }

    public int getPoints() { return points; }
    public void setPoints(int points) { this.points = points; }

    public void addPoints(double totalAmount) {
        int earnedPoints = (int)(totalAmount / 50);
        points += earnedPoints;
        System.out.println("You earned " + earnedPoints + " points");
        System.out.println("Total Points: " + points + " points");
    }

    public double redeemPoints(double totalAmount) {
        double discount = points / 10.0;
        totalAmount -= discount;
        System.out.println("Redeemed ₱" + discount + " using points!");
        points = 0; // reset after redeem
        return totalAmount;
    }

    public void displayPoints() {
        System.out.println("Current Points: " + points + " points");
    }
}