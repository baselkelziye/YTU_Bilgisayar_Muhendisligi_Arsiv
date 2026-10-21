package org.algorithm;

import org.db.model.Announcement;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by mgunes on 09.12.2016.
 */
public class FilterAnnouncement {
    public List<Announcement> filterByKeywords(List<Announcement> annList, String[] keywords) {
        List<Announcement> newAnnList = new ArrayList<Announcement>();
        boolean found;

        for(Announcement announcement: annList) {
            found = searchKeywords(announcement, keywords);

            if(found) {
                newAnnList.add(announcement);
            }
        }

        return newAnnList;
    }

    private boolean searchKeywords(Announcement announcement, String[] keywords) {
        boolean found = false;
        int i = 0;

        while(i < keywords.length && !found) {
            if(announcement.getTitle().contains(keywords[i])
                   || announcement.getBrief().contains(keywords[i])
                    || announcement.getContent().contains(keywords[i])) {
                found = true;
            }
            i++;
        }

        return found;
    }
}
