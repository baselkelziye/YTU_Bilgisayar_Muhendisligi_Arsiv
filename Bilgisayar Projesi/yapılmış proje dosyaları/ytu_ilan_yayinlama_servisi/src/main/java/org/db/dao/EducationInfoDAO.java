package org.db.dao;

import org.db.model.EducationInfo;

import java.util.List;

/**
 * Created by mgunes on 27.01.2017.
 */
public interface EducationInfoDAO {
    List<EducationInfo> getByStudent(String username);
    boolean saveEducationInfo(EducationInfo info);
}
