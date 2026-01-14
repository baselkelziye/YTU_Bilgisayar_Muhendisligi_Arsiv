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
        if (health < 0) {
            health = 0;
        }
    }

    public void reborn() {
        if (isAlive()) {
            System.out.println("Zaten yaşıyo la");
        }
        else {
            this.health = maxHealth;
            System.out.println("Hoşgeldin genç adam");
        }
    }

    public void heal(int amount) {
        this.health += amount;
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
