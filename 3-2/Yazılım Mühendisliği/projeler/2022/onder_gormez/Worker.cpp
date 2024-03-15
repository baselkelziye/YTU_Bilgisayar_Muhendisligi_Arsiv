#include "Worker.h"

void Worker::updateSalaryAccordingToInflation(double inflationRate)
{
    m_salary = m_salary + m_salary * inflationRate;
}
