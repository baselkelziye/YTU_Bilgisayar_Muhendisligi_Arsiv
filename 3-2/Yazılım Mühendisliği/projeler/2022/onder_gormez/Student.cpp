#include "Student.h"

bool Student::addToCourse(Course &course)
{
    bool isSuccessful = course.addNewStudent();

    if (!isSuccessful)
        return false;

    return true;
}

bool Student::deleteFromCourse(Course &course)
{
    bool isSuccessful = course.deleteStudent();

    if (!isSuccessful)
        return false;

    return true;
}
