
## Kısıtlamalar
* Tool içi dolu ok çizdiği için türetmelerde kullanılan okların içi dolu olarak gösterilmiştir.
* Tool otomatik olarak çizdiği için görsellerde karmaşık görünüm ortaya çıkabiliyor.

TODO: Dışardan erişilemeyenleri "-" ile ifade et.
TODO: Variable lar ile method lar arasına boşluk koy
TODO: 2 class definition arasına boşluk koy

```mermaid
classDiagram
    Courses o-- Student  : Aggregation
    SchoolBranch *-- Courses : Composition
    Person <|-- Student : Inheritance
    Person <|-- Worker : Inheritance
    Worker <|-- Teacher : Inheritance
    Worker <|-- Registrar : Inheritance
    Courses o-- Teacher  : Aggregation
 
    class Student{
    }

    class Worker{
    }
    
    class Teacher{
    }

    class Registrar{
    }

    class SchoolBranch{
    }

    class Courses{
    }
```
TODO: 
BTool böyle okun içi dolu
classA --|> classB : Inheritance
classC --* classD : Composition
classE --o classF : Aggregation
classG --> classH : Association
classI -- classJ : Link(Solid)
classK ..> classL : Dependency
classM ..|> classN : Realization
classO .. classP : Link(Dashed)

```mermaid
classDiagram
    Person <|-- Student : Inheritance
    Person <|-- Worker : Inheritance
    Worker <|-- Teacher : Inheritance
    Worker <|-- Registrar : Inheritance
    Person : +String m_name
    Person : +String m_surname
    Person : +int m_age
    Person : +String m_gender
    Person : +String m_mobilephone
    Person : +String m_phone
    Person : +String m_email
    Person : +String m_address
    Person: +Person(String name, String surname, String mobilephone, String phone, String email, int age, String gender, String address)
    Person: +setName(String newName) void
    Person: +getName() String

    class Student{
      +vector~String~ m_courses
      +vector~String~ m_courseLevel
      +String m_paymentInfos
      +addToCourse(Course &course) bool
      +deletFromCourse(Course &course) bool
    }

    class Worker{
      +String m_workStartDate
      +String m_workEndDate
      +bool m_isActiveWorker
      +int m_salary
      +updateSalaryAccordingToInflation(double inflationRate) void
    }
    
    class Teacher{
      +vector~String~ m_languages
      +vector~SchoolBranch~ m_classLocations
      +String m_availableDays
      +String m_availableHours
    }

    class Registrar{
      +registerStudentForClass() bool 
    }
```

* Yukarıda detayı verilen sınıfların detayları tekrar yazılmamıştır.

```mermaid
classDiagram
    SchoolBranch *-- Courses : Composition
 
    class SchoolBranch{
        -String m_name
        -String m_address
        -String m_publicTransport
        -String m_privateTransport
        -vector~String~ m_socialBenefits
        -vector~ClassRoom~ m_allClasses
        -bool m_isActiveBranch
        
        +activateBranch() void
        +deactivateBranch() void
    }

    class Courses{
        -String m_name
        -int m_capacity
        -int m_registeredStudentCount
        -String m_level

        +setName(String newName) void
        +getName() String
        +addNewStudent() bool
        +deleteStudent() bool
    }
```

## Kaynaklar
[Class Diagram](https://mermaid-js.github.io/mermaid/#/classDiagram)
