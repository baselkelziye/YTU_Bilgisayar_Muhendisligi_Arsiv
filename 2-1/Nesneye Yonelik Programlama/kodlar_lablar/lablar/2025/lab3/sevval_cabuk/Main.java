package sevval_cabuk;

public class Main {
    public static void main(String[] args) {

        FoodDeliveryPlatform platform = new FoodDeliveryPlatform();

        platform.addProduct(new Food("F101", "Cheeseburger", 30, "Burger King"));
        platform.addProduct(new Food("F102", "Margherita Pizza", 25, "Dominos"));
        platform.addProduct(new Food("F103", "Chicken Wrap", 20 , "Popeyes"));
        platform.addProduct(new Drink("D201", "Ice Tea", 8, "Medium"));
        platform.addProduct(new Drink("D202", "Cola", 12, "Large"));

        System.out.println("PRODUCTS:");
        platform.listProducts();
        
        System.out.println("\nProducts between 10$ and 20$:");
        platform.searchByPriceRange(10, 20);
        
        
        System.out.println("--------------------------------------------------------------------------");;

        Customer c1 = new Customer("C001", "Alice Johnson");

        try {
            c1.addToCart(platform.getProduct("F102"));
            c1.addToCart(platform.getProduct("D201"));
            c1.addToCart(platform.getProduct("D202"));
            c1.addToCart(platform.getProduct("F102")); // duplicate test
        } catch (ItemAlreadyInCartException e) {
            System.out.println("ERROR: " + e.getMessage());
        }

        System.out.println("\nCart Items:");
        c1.showCartDetails();
        
        c1.removeFromCart("D201");
        
        System.out.println("\nCart Items:");
        c1.showCartDetails();
        c1.payment();
        
        System.out.println("--------------------------------------------------------------------------");
        c1.showCartDetails();
        
        System.out.println("--------------------------------------------------------------------------");;
        
        try {
        	c1.addToCart(platform.getProduct("F101"));
			c1.addToCart(platform.getProduct("D201"));
		} catch (ItemAlreadyInCartException e) {
			e.printStackTrace();
		}
        
        System.out.println("\nCart Items:");
        c1.showCartDetails();
        c1.payment();
       
      
        
    }
}

