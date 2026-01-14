package Uyg2;

public class TestGame {

    public static void main(String[] args) {

        Warrior knight = new Warrior("Leon", 160, 75);
        Mage sorcerer = new Mage("Elira", 100, 28, 20);
        Warrior enemy = new Warrior("Kara Muhafız", 140, 25);

        System.out.println("-- Tur 1 --");
        knight.attack(enemy);
        enemy.attack(knight);

        System.out.println("\n-- Tur 2 -- (Güçlendirilmiş saldırı ve büyü saldırısı)");
        knight.attack(enemy, 2); 
        sorcerer.attack(enemy);
        enemy.attack(sorcerer);

        System.out.println("\n-- Tur 3 -- (Destek ve savunma)");
        sorcerer.healAlly(knight);
        sorcerer.healAlly(sorcerer, 15);

        System.out.println("\n-- Tur 4 -- ");
        knight.attack(enemy);
        sorcerer.attack(enemy);

        if (!enemy.isAlive()) {
            System.out.println("\nKara Muhafız yenildi.");
        }

        System.out.println("Leon sağlık: " + knight.getHealth());
        System.out.println("Elira sağlık: " + sorcerer.getHealth());
        System.out.println("Kara Muhafız sağlık: " + enemy.getHealth());

        sorcerer.healAlly(knight);

        enemy.reborn();

        System.out.println("\nKara Muhafız tekrar saldırıyor.");
        enemy.attack(knight);

        System.out.println("\nLeon son saldırısını gerçekleştirir.");
        knight.attack(enemy, 5);

        if (!enemy.isAlive()) {
            System.out.println("\nKara Muhafız ölü.");
        }

    }
}
