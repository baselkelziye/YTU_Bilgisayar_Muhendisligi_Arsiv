countries = ["Almanya", "Amerika Birleşik Devletleri", "Arjantin", "Avustralya", "Avusturya",
		"Azerbaycan", "Bahreyn", "Belçika", "Beyaz Rusya", "Birleşik Arap Emirlikleri", "Bolivya", "Bosna ve Hersek",
		"Brezilya", "Bulgaristan", "Cezayir", "Çekya", "Danimarka", "Dominik Cumhuriyeti", "Ekvador", "El Salvador",
		"Endonezya", "Estonya", "Fas", "Filipinler", "Finlandiya", "Fransa", "Gana", "Guatemala", "Güney Afrika",
		"Güney Kıbrıs Rum Yönetimi", "Güney Kore", "Gürcistan", "Hırvatistan", "Hindistan", "Hollanda", "Honduras",
		"Hong Kong", "Irak", "İngiltere", "İrlanda", "İspanya", "İsrail", "İsveç", "İsviçre", "İtalya", "İzlanda",
		"Jamaika", "Japonya", "Kanada", "Karadağ", "Katar", "Kazakistan", "Kenya", "Kolombiya", "Kosta Rika", "Kuveyt",
		"Kuzey Makedonya", "Letonya", "Libya", "Liechtenstein", "Litvanya", "Lübnan", "Lüksemburg", "Macaristan",
		"Malezya", "Malta", "Meksika", "Mısır", "Nepal", "Nijerya", "Nikaragua", "Norveç", "Pakistan", "Panama",
		"Papua Yeni Gine", "Paraguay", "Peru", "Polonya", "Portekiz", "Porto Riko", "Romanya", "Rusya", "Senegal",
		"Sırbistan", "Singapur", "Slovakya", "Slovenya", "Sri Lanka", "Suudi Arabistan", "Şili", "Tanzanya", "Tayland",
		"Tayvan", "Tunus", "Türkiye", "Uganda", "Ukrayna", "Umman", "Uruguay", "Ürdün", "Venezuela", "Vietnam", "Yemen",
		"Yeni Zelanda", "Yunanistan", "Zimbabve"]

codes = ["DE", "US", "AR", "AU", "AT", "AZ", "BH", "BE", "BY", "AE", "BO", "BA", "BR", "BG",
		"DZ", "CZ", "DK", "DO", "EC", "SV", "ID", "EE", "MA", "PH", "FI", "FR", "GH", "GT", "ZA", "CY", "KR", "GE",
		"HR", "IN", "NL", "HN", "HK", "IQ", "GB", "IE", "ES", "IL", "SE", "CH", "IT", "IS", "JM", "JP", "CA","ME", "QA",
		"KZ", "KE", "CO","CR", "KW", "MK", "LV", "LY", "LI","LT", "LB", "LU", "HU", "MY", "MT", "MX", "EG", "NP", "NG",
		"NI", "NO", "PK", "PA", "PG", "PY", "PE", "PL","PT", "PR", "RO", "RU", "SN", "XS", "SG", "SK", "SI", "LK", "SA",
		"CL", "TZ", "TH", "TW", "TN", "TR", "UG", "UA", "OM", "UY", "JO", "VE", "VN", "YE", "NZ", "GR", "ZW"]

print(len(countries))
print(len(codes))


for i in range(len(countries)):
	try:
		print(countries[i], codes[i])
	except:
		print(countries[i])