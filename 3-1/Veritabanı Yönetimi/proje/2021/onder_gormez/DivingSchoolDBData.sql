-- Student Information
INSERT INTO Students VALUES(12101, 'Ali',        'Demir',    'Bagcilar',   '5 May 2007');
INSERT INTO Students VALUES(12102, 'Ahmet',      'Babagil',  'Kartal',     '3 November 2002');
INSERT INTO Students VALUES(12103, 'Serkan',     'Kaya',     'Eminonu',    '13 June 2003');
INSERT INTO Students VALUES(12104, 'Veli',       'Ozen',     'Kadikoy',    '19 April 2004');
INSERT INTO Students VALUES(12105, 'Saglim',     'Ucler',    'Uskudar',    '3 July 2009');
INSERT INTO Students VALUES(12106, 'Mehmet',     'Ulker',    'Fatih',      '11 October 2006');
INSERT INTO Students VALUES(12107, 'Hasan',      'Koc',      'Eyup',       '9 September 2008');
INSERT INTO Students VALUES(12108, 'Ibrahim',    'Dogan',    'Besiktas',   '17 August 2007');
INSERT INTO Students VALUES(12109, 'Hakan',      'Ercetin',  'Basaksehir', '27 June 2001');
INSERT INTO Students VALUES(12110, 'Salih',      'Isık',     'Maltepe',    '23 March 2009');
INSERT INTO Students VALUES(12111, 'Mustafa',    'Aksoy',    'Kartal',     '18 November 2000');
INSERT INTO Students VALUES(12112, 'Mahmut',     'Yetim',    'Şile',       '1 May 1997');
INSERT INTO Students VALUES(12113, 'Abdülkadir', 'Çıplak',   'Beylikdüzü', '12 June 2010');
INSERT INTO Students VALUES(12114, 'Erkan',      'Aktemur',  'Bağcılar',   '25 December 1999');
INSERT INTO Students VALUES(12115, 'Hayati',     'Taştekin', 'Sultangazi', '19 August 2003');

-- Teacher Information
INSERT INTO Teachers VALUES(22101, 'Iraz',    'Gürcan',    'Bagcilar',     '5 May 1990');
INSERT INTO Teachers VALUES(22102, 'Sudem',   'Fındık ',   'Bayrampaşa',   '1 March 1991');
INSERT INTO Teachers VALUES(22103, 'Kumru',   'Karadavut', 'Çatalca',      '19 July 1980');
INSERT INTO Teachers VALUES(22104, 'Mehmet',  'Pekcan',    'Güngören',     '23 October 1987');
INSERT INTO Teachers VALUES(22105, 'Sertaç',  'Sökmen',    'Silivri',      '16 January 1992');
INSERT INTO Teachers VALUES(22106, 'Petek',   'Çakal',     'Tuzla',        '7 June 1989');
INSERT INTO Teachers VALUES(22107, 'Demen',   'Üresin',    'Üsküdar ',     '17 May 1995');
INSERT INTO Teachers VALUES(22108, 'Hazal',   'Sağır',     'Sultangazi',   '13 August 1993');
INSERT INTO Teachers VALUES(22109, 'Cem',     'Tan',       'Sultanbeyli',  '21 April 1994');
INSERT INTO Teachers VALUES(22110, 'Zübayda', 'Benekli',   'Eyüpsultan',   '11 February 1983');
INSERT INTO Teachers VALUES(22111, 'Tayyar',  'Nar',       'Güngören',     '18 November 1984');
INSERT INTO Teachers VALUES(22112, 'Hacı',    'Özata',     'Büyükçekmece', '2 September 1991');
INSERT INTO Teachers VALUES(22113, 'Fatma',   'Kuralay',   'Maltepe',      '14 March 1985');
INSERT INTO Teachers VALUES(22114, 'Seda',    'Toy',       'Sancaktepe',   '22 July 1979');
INSERT INTO Teachers VALUES(22115, 'Aydın',   'Emet',      'Kartal',       '15 December 1997');

-- Lesson Information
INSERT INTO Lessons VALUES(32101, 'Serbest dalış');
INSERT INTO Lessons VALUES(32102, 'Skin dalış');
INSERT INTO Lessons VALUES(32103, 'Çan dalış');
INSERT INTO Lessons VALUES(32104, 'Destekli dalış');
INSERT INTO Lessons VALUES(32105, 'Scuba dalış');
INSERT INTO Lessons VALUES(32106, 'Saturasyon dalış');
INSERT INTO Lessons VALUES(32107, 'Kasklı dalış');
INSERT INTO Lessons VALUES(32108, 'Satıhtan dalış');
INSERT INTO Lessons VALUES(32109, 'Aletli dalış');
INSERT INTO Lessons VALUES(32110, 'Aletsiz dalış');

-- Class Information
INSERT INTO Classes VALUES(42101, 'A1');
INSERT INTO Classes VALUES(42102, 'A2');
INSERT INTO Classes VALUES(42103, 'B1');
INSERT INTO Classes VALUES(42104, 'B2');
INSERT INTO Classes VALUES(42105, 'C1');
INSERT INTO Classes VALUES(42106, 'C2');
INSERT INTO Classes VALUES(42107, 'D1');
INSERT INTO Classes VALUES(42108, 'D2');
INSERT INTO Classes VALUES(42109, 'E1');
INSERT INTO Classes VALUES(42110, 'E2');

-- Prices Information
INSERT INTO Prices VALUES(32101, 1000);
INSERT INTO Prices VALUES(32102, 2000);
INSERT INTO Prices VALUES(32103, 3000);
INSERT INTO Prices VALUES(32104, 4000);
INSERT INTO Prices VALUES(32105, 5000);
INSERT INTO Prices VALUES(32106, 6000);
INSERT INTO Prices VALUES(32107, 7000);
INSERT INTO Prices VALUES(32108, 8000);
INSERT INTO Prices VALUES(32109, 9000);
INSERT INTO Prices VALUES(32110, 1001);

-- Takes Information
INSERT INTO Takes VALUES(12108, 32101, 22103, 42101);
INSERT INTO Takes VALUES(12109, 32101, 22103, 42101);
INSERT INTO Takes VALUES(12101, 32101, 22103, 42101);
INSERT INTO Takes VALUES(12102, 32101, 22103, 42101);
INSERT INTO Takes VALUES(12112, 32101, 22103, 42101);

INSERT INTO Takes VALUES(12108, 32102, 22104, 42102);
INSERT INTO Takes VALUES(12103, 32102, 22104, 42102);
INSERT INTO Takes VALUES(12107, 32102, 22104, 42102);
INSERT INTO Takes VALUES(12106, 32102, 22104, 42102);

INSERT INTO Takes VALUES(12115, 32103, 22105, 42103);
INSERT INTO Takes VALUES(12104, 32103, 22105, 42103);
INSERT INTO Takes VALUES(12105, 32103, 22105, 42103);
INSERT INTO Takes VALUES(12110, 32103, 22105, 42103);
INSERT INTO Takes VALUES(12113, 32103, 22105, 42103);
INSERT INTO Takes VALUES(12114, 32103, 22105, 42103);

INSERT INTO Takes VALUES(12115, 32104, 22106, 42104);
INSERT INTO Takes VALUES(12112, 32104, 22106, 42104);
INSERT INTO Takes VALUES(12107, 32104, 22106, 42104);

INSERT INTO Takes VALUES(12101, 32105, 22107, 42105);
INSERT INTO Takes VALUES(12112, 32105, 22107, 42105);
INSERT INTO Takes VALUES(12102, 32105, 22108, 42105);
INSERT INTO Takes VALUES(12109, 32105, 22108, 42105);

INSERT INTO Takes VALUES(12114, 32106, 22111, 42106);
INSERT INTO Takes VALUES(12110, 32106, 22111, 42106);
INSERT INTO Takes VALUES(12104, 32106, 22111, 42106);

-- INSERT INTO Takes VALUES(12101, 32101, 22101, 42107);
INSERT INTO Takes VALUES(12106, 32101, 22101, 42107);

INSERT INTO Takes VALUES(12105, 32104, 22114, 42108);
INSERT INTO Takes VALUES(12111, 32104, 22114, 42108);

INSERT INTO Takes VALUES(12113, 32105, 22113, 42109);
-- INSERT INTO Takes VALUES(12112, 32105, 22113, 42109);

INSERT INTO Takes VALUES(12106, 32103, 22115, 42110);
INSERT INTO Takes VALUES(12107, 32103, 22115, 42110);