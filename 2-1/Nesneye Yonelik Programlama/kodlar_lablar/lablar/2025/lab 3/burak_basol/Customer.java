import java.util.ArrayList;

public class Customer {
    private String id;
    private String name;
    private ArrayList<Sellable> cart;

    public Customer(String id, String name) {
        this.id = id;
        this.name = name;
        this.cart = new ArrayList<>();
    }

    public void addToCart(Sellable sellable) throws ItemAlreadyInCartException {
        for (Sellable item : cart) {
            if (item.getId().equals(sellable.getId())) {
                throw new ItemAlreadyInCartException("This item is already in your cart: " + item.getName());
            }
        }

        cart.add(sellable);
        System.out.println("Added to cart: " + sellable.getName());
    }

    public void removeFromCart(String itemId){
        for (Sellable item : cart) {
            if (item.getId().equals(itemId)) {
                System.out.println("Removed from cart: " + item.getName());
                cart.remove(item);
            }
        }
    }

    public void showCartDetails() {
        if(cart.isEmpty()) {
            System.out.println("Cart is empty");
        }
        else {
            for (Sellable item : cart) {
                System.out.println(item.getName() + " : " + item.getPrice());
            }
        }
    }

    public void payment() {
        double total = 0;
        for (Sellable item : cart) {
            total += item.getPrice();
        }

        System.out.println("Total payment: " + total);

        cart.clear();
    }
}
