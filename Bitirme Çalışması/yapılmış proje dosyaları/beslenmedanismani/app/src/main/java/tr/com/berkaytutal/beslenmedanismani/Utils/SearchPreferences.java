package tr.com.berkaytutal.beslenmedanismani.Utils;

/**
 * Created by berka on 16.05.2017.
 */

public class SearchPreferences {

    private String query;
    private String trainerQuery;
    private String category;
    private String hardnessLevel;
    private String sortBy;

    public SearchPreferences(String query, String trainerQuery, String category, String hardnessLevel, String sortBy) {
        this.query = query;
        this.trainerQuery = trainerQuery;
        this.category = category;
        this.hardnessLevel = hardnessLevel;
        this.sortBy = sortBy;
    }

    public String getQuery() {
        return query;
    }

    public void setQuery(String query) {
        this.query = query;
    }

    public String getCategory() {
        return category;
    }

    public void setCategory(String category) {
        this.category = category;
    }

    public String getHardnessLevel() {
        return hardnessLevel;
    }

    public void setHardnessLevel(String hardnessLevel) {
        this.hardnessLevel = hardnessLevel;
    }

    public String getSortBy() {
        return sortBy;
    }

    public void setSortBy(String sortBy) {
        this.sortBy = sortBy;
    }

    public String getTrainerQuery() {
        return trainerQuery;
    }

    public void setTrainerQuery(String trainerQuery) {
        this.trainerQuery = trainerQuery;
    }
}
