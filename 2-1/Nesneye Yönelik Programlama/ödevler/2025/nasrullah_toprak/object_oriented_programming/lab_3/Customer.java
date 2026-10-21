package nasrullahtoprak;

import java.util.ArrayList;

public class Customer{
    private String id;
    private String name;
    private ArrayList<Seliable> cart;

    public Customer(String id, String name){
        this.id=id;
        this.name=name;
        cart = new ArrayList<Seliable>();
    }

    public void addToCart(Seliable item) throws ItemAlreadyInCartException {
        if(cart.contains(item)){
            throw new ItemAlreadyInCartException("This item is already found in your cart : " + item.getName());
        }
        cart.add(item);
        System.out.println("Added to cart: " + item.getName());
    }

    public void removeFromCart(String itemId){
        for(Seliable S: cart){
            if(S.getId().equalsIgnoreCase(itemId)){
                cart.remove(S);
                System.out.println("Removed from cart: " + S.getName());
                return;
            }
        }
        System.out.println("Can't found such item with this id:" + itemId);
    }

    public void showCartDetails(){
        if(cart.isEmpty()){
            System.out.println("Cart is empty");
            return;
        }
        for(Seliable S: cart){
            System.out.println(S.getName() + ":" + S.getPrice() +"$");
        }
    }

    public void payment(){
        double total = 0;
        for(Seliable s: cart){
            total += s.getPrice();
        }
        System.out.println("Total payment: " + total +"$");
        cart.clear();
    }
}
