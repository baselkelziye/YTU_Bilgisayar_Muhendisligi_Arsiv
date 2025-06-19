@EnumValidator(enumClass = {ClassIsmi}.class)

Örnek Enum:
UserRole:
{
USER,
STUDENT 
}

Modellerin içerisine Enum classı değil String kaydedilecek ve yukarıdaki validator ile kontrol sağlanacak

private String userRole
