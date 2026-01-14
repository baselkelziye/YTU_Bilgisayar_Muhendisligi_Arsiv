

public class Movie {
    private String title;
    private String director;
    private int duration;   // dakika
    private String genre;

    public Movie(String title, String director, int duration, String genre) {
        this.title = title;
        this.director = director;
        this.duration = duration;
        this.genre = genre;
    }

    public String getTitle() {
        return title;
    }

    public String getDirector() {
        return director;
    }

    public int getDuration() {
        return duration;
    }

    public String getGenre() {
        return genre;
    }

	public void setTitle(String title) {
		this.title = title;
	}

	public void setDirector(String director) {
		this.director = director;
	}

	public void setDuration(int duration) {
		this.duration = duration;
	}

	public void setGenre(String genre) {
		this.genre = genre;
	}
    
}

