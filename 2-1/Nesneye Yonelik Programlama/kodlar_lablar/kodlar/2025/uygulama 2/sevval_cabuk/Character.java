package Uyg2;

public abstract class Character {
	
    private String name;
    private int health;
    private int maxHealth;
    
    public Character(String name, int health) {
        this.name = name;
        this.health = health;
        this.maxHealth = health;
    }
    
 
    
    public abstract void attack(Character target);
    public abstract void defend(int damage);
    
    public boolean isAlive() {
        return health > 0;
    }
    
    public void reduceHealth(int damage) {
        this.health -= damage;
        if (health < 0) health = 0;
    }
    
    public void reborn() {
        if (isAlive()) {
            System.out.println(name + " zaten hayatta.");
        } else {
            System.out.println(name + " yeniden doğuyor...");
            this.health = maxHealth;
        }
    }
    
    public void heal(int amount) {
        if (amount <= 0) return;
        this.health += amount;
        if (health > maxHealth) {
            health = maxHealth;
        }
        System.out.println(name + " " + amount + " iyileşti. (Sağlık: " + health + "/" + maxHealth + ")");
    }
    
    public String getName() {
        return name;
    }

    public int getHealth() {
        return health;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setHealth(int health) {
        this.health = health;
    }

}
