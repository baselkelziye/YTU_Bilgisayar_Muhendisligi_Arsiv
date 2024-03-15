-- Verilen bir id nin okula kayıtlı öğrenciler arasında olup olmadığını bulan fonksiyonu yazınız.
CREATE OR REPLACE FUNCTION is_student_exist(std_id CHAR(5))
RETURNS BOOL AS $$
BEGIN
    IF EXISTS (SELECT 1 FROM Students WHERE id = std_id) THEN
        RETURN TRUE;
    ELSE
        RETURN FALSE;
    END IF;
END; $$
LANGUAGE PLpgSQL;

SELECT is_student_exist('12101');
SELECT is_student_exist('12181');

-- ID'si verilen bir öğrencinin yüzme okuluna ne kadar para ödediğini bulan fonksiyonu yazınız.
-- Tüm aldığı dersler bulunur. Bunların fiyatları toplanır.
CREATE OR REPLACE FUNCTION get_total_paid_amount(std_id CHAR(5))
RETURNS INTEGER AS $$
DECLARE
total_paid INTEGER := 0;
BEGIN

    IF is_student_exist(std_id) = FALSE THEN
        RAISE EXCEPTION 'Student ID (%) not found in the database!', std_id;
        RETURN 0;
    END IF;
    
    SELECT SUM(price) INTO total_paid
    FROM Students AS s, Takes AS t, Prices AS p
    WHERE s.id = t.student_id AND t.lesson_id = p.lesson_id AND t.student_id = std_id
    GROUP BY s.id, s.name, s.surname;
    RETURN total_paid;

END; $$
LANGUAGE PLpgSQL;

SELECT get_total_paid_amount('12101');

-- Yukarıdaki fonksiyonu kursör tanımı kullanarak daha kolay bir şekilde implement edebiliyoruz.
CREATE OR REPLACE FUNCTION get_total_paid_amount(std_id CHAR(5))
RETURNS INTEGER AS $$
DECLARE
total_paid INTEGER := 0;
row_values_record RECORD;
prices_cursor CURSOR FOR (SELECT s.name, s.surname, p.lesson_id, price
                          FROM Students AS s, Takes AS t, Prices AS p
                          WHERE s.id = t.student_id AND t.lesson_id = p.lesson_id AND t.student_id = std_id);
BEGIN

    IF is_student_exist(std_id) = FALSE THEN
      RAISE EXCEPTION 'Student ID (%) not found in the database!', std_id;
      RETURN 0;
    END IF;
    -- prices_cursor den alınan her bir kayıt 
    -- row_values_record RECORD değişkeninin içerisine atanıyor
    FOR row_values_record IN prices_cursor
    LOOP
      total_paid := total_paid + row_values_record.price;
    END LOOP;

    RETURN total_paid;

END; $$
LANGUAGE PLpgSQL;

SELECT get_total_paid_amount('12101');

-- Verilen ilçede oturan öğrenciler listeleyen fonksiyonu yazınız.
CREATE OR REPLACE FUNCTION list_students_at_lives_given_address(std_address VARCHAR(255))
RETURNS VOID AS $$
DECLARE
student_record RECORD;
student_list_cursor CURSOR FOR(
                               SELECT id, name, surname
                               FROM Students
                               WHERE address = std_address);
BEGIN
  FOR student_record IN student_list_cursor
  LOOP
    RAISE EXCEPTION '% % with id % lives %!', student_record.name,
                                           student_record.surname,
                                           student_record.id,
                                           std_address;
  END LOOP;
END; $$
LANGUAGE PLpgSQL;

SELECT list_students_at_lives_given_address('Kartal');

-- Dalış okulunun yıllık kazancını hesaplayan fonksiyonu yazınız.
CREATE OR REPLACE FUNCTION get_annual_revenue()
RETURNS INTEGER AS $$
DECLARE
total_revenue INTEGER := 0;
student_record RECORD;
student_cursor CURSOR FOR (SELECT id FROM Students);
BEGIN
  FOR student_record IN student_cursor
  LOOP
    total_revenue := total_revenue + get_total_paid_amount(student_record.id);
  END LOOP;
  RETURN total_revenue;
END; $$
LANGUAGE PLpgSQL;

SELECT get_annual_revenue();

-- TODO: Yüzme okulu tablolarında öğretmen veya öğrenci tablosunda isim veya soyisim yanlış girildiyse, diğer tabloda da o bilgi tutuluyorsa, ana/birincil öğrenci veya öğretmen tablosu update edildiğinde otomatik olarak 2. tablonunda update edilmesini sağlayacak trigger yazılabilir.  
-- Aynı şekilde öğrencilerin ortalama ödediği paraları tutan bir tablo olduğunu düşünürsek, bu tablodaki tutarlar diğer tablolarda yapılan değişiklikler sonucu (yeni öğrenci eklenmesi, öğrencinin silinmesi, veya aldığı derslerin güncellenmesi gibi durumlar) güncellenecek şekilde trigger lar yazılmalıdır.  