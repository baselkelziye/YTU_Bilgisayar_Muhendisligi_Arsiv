

public class Main {
    public static void main(String[] args) {
        Movie m1 = new Movie("Inception", "Christopher Nolan", 148, "Bilim Kurgu");
        Movie m2 = new Movie("Interstellar", "Christopher Nolan", 169, "Bilim Kurgu");
        Movie m3 = new Movie("The Dark Knight", "Christopher Nolan", 152, "Aksiyon");
        Movie m4 = new Movie("Memento", "Christopher Nolan", 113, "Gerilim");

        Cinema cinema = new Cinema("DreamCity", 5);

        cinema.addSession(new Session(m1, 1, "13:00", false));
        cinema.addSession(new Session(m2, 2, "16:00", true));
        cinema.addSession(new Session(m3, 3, "19:30", false));
        cinema.addSession(new Session(m4, 4, "22:00", true));

        cinema.printAllSessions();

        System.out.println();
        cinema.findByTitle("Interstellar");

        System.out.println();
        System.out.println("Ortalama film süresi: " + cinema.getAverageDuration() + " dk");

        Movie longest = cinema.getLongestMovie();
        Movie shortest = cinema.getShortestMovie();
        System.out.println("En uzun film: " + longest.getTitle() + " (" + longest.getDuration() + " dk)");
        System.out.println("En kısa film: " + shortest.getTitle() + " (" + shortest.getDuration() + " dk)");

        System.out.println();
        System.out.println("Dublajlı film sayısı: " + cinema.getDubbedCount());
        System.out.println("Dublajlı filmlerin ortalama süresi: " + cinema.getAverageDurationOfDubbed() + " dk");
    }
}


