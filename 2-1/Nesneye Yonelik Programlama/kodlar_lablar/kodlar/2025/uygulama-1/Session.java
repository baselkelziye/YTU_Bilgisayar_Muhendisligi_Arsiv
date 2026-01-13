

public class Session {
    private Movie movie;
    private int hall;
    private String time;
    private boolean dubbed; // true = dublajlı, false = altyazılı

    public Session(Movie movie, int hall, String time, boolean dubbed) {
        this.movie = movie;
        this.hall = hall;
        this.time = time;
        this.dubbed = dubbed;
    }

    public Movie getMovie() {
        return movie;
    }

    public int getHall() {
        return hall;
    }

    public String getTime() {
        return time;
    }

    public boolean isDubbed() {
        return dubbed;
    }
}

