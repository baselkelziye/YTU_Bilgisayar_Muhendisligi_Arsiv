

public class Cinema {
    private String name;
    private Session[] sessions;
    private int maxSession;

    public Cinema(String name, int maxSession) {
        this.name = name;
        this.maxSession = maxSession;
        this.sessions = new Session[maxSession];
    }

    public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public Session[] getSessions() {
		return sessions;
	}

	public void setSessions(Session[] sessions) {
		this.sessions = sessions;
	}

	public int getMaxSession() {
		return maxSession;
	}

	public void setMaxSession(int maxSession) {
		this.maxSession = maxSession;
	}

	public boolean addSession(Session s) {
        int i = 0;
        boolean success = false;

        while (i < sessions.length && !success) {
            if (sessions[i] == null) {
                sessions[i] = s;
                success = true;
            }
            i++;
        }
        return success;
    }

    public void printAllSessions() {
        System.out.println(name + " sinemasında bugünkü seanslar:");
        for (int i = 0; i < sessions.length; i++) {
            if (sessions[i] != null) {
                Movie m = sessions[i].getMovie();
                System.out.println("- " + m.getTitle() + " (" + m.getDuration() + " dk, Tür: " + m.getGenre() + ")" +
                    " | Yönetmen: " + m.getDirector() +
                    " | Salon: " + sessions[i].getHall() +
                    " | Saat: " + sessions[i].getTime() +
                    " | Dublajlı: " + (sessions[i].isDubbed() ? "Evet" : "Hayır"));
            }
        }
    }

    public void findByTitle(String title) {
        boolean found = false;
        for (int i = 0; i < sessions.length; i++) {
            if (sessions[i] != null &&
                sessions[i].getMovie().getTitle().equalsIgnoreCase(title)) {
                Movie m = sessions[i].getMovie();
                System.out.println("Bulundu: " + m.getTitle() + " (" + m.getDuration() + " dk, Tür: " + m.getGenre() + ")" +
                    " | Salon: " + sessions[i].getHall() +
                    " | Saat: " + sessions[i].getTime() +
                    " | Dublajlı: " + (sessions[i].isDubbed() ? "Evet" : "Hayır"));
                found = true;
            }
        }
        if (!found)
            System.out.println(title + " adlı film bu sinemada bulunamadı.");
    }

    public double getAverageDuration() {
        double total = 0;
        double avg;
        int count = 0;
        for (int i = 0; i < sessions.length; i++) {
            if (sessions[i] != null) {
                total += sessions[i].getMovie().getDuration();
                count++;
            }
        }
        if (count > 0)
        {
        	avg = total / count;
        }
        else {
        	avg = 0.0;
        }
        return avg;
    }

    public Movie getLongestMovie() {
        Movie longest = null;
        for (int i = 0; i < sessions.length; i++) {
            if (sessions[i] != null) {
                if (longest == null || sessions[i].getMovie().getDuration() > longest.getDuration())
                    longest = sessions[i].getMovie();
            }
        }
        return longest;
    }

    public Movie getShortestMovie() {
        Movie shortest = null;
        for (int i = 0; i < sessions.length; i++) {
            if (sessions[i] != null) {
                if (shortest == null || sessions[i].getMovie().getDuration() < shortest.getDuration())
                    shortest = sessions[i].getMovie();
            }
        }
        return shortest;
    }

    public int getDubbedCount() {
        int count = 0;
        for (int i = 0; i < sessions.length; i++) {
            if (sessions[i] != null && sessions[i].isDubbed())
                count++;
        }
        return count;
    }

    public double getAverageDurationOfDubbed() {
        double total = 0;
        int count = 0;
        double avg;
        for (int i = 0; i < sessions.length; i++) {
            if (sessions[i] != null && sessions[i].isDubbed()) {
                total += sessions[i].getMovie().getDuration();
                count++;
            }
        }
        if (count > 0)
        {
        	avg = total / count;
        }
        else {
        	avg = 0.0;
        }
        return avg;
    }
}
