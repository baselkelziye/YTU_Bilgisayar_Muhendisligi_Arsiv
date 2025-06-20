`/api/movies/front`

Ön sayfadaki filmeri slaytlar halinde çekmek için kullanacaksınız. 
- pageNumber 
- pageSize (max limit 50)
- sortBy (popularity, title, watchCount gibi çeşitli parametreler kullanabilirsiniz)
- sortOrder (asc veya dsc)
- genre (türe göre sınıflandırabilirsiniz. Sadece Action, Comedy gibi baş harfi büyük ingilizce parametreleri kabul eder)
- lanugage (default olarak "en" çağırılır. "tr" kullanarak türkçe veri çekebilirsiniz)

```
{
    "content": [
        {
            "movieId": 85,
            "title": "Raiders of the Lost Ark",
            "poster": "/edtIzvWUuMDG8qsWsYzjMXoXTy2.jpg",
            "watchCount": 0,
            "likeCount": 0,
            "ratingAverage": 0.0
        }
    ],
    "pageNumber": 0,
    "pageSize": 1,
    "totalElements": 17,
    "totalPages": 17,
    "lastPage": false
}
```

Şeklinde response döndürür.

Belirli bir filmin bilgilerini çekmek için aşağıdaki endpointi kullanacaksınız.
`/api/movies/{movieId}`

sadece language parametresi girebilirsiniz
aşağıdaki gibi response döndürür

```
{
    "movieId": 11,
    "originalLanguage": "en",
    "originalTitle": "Star Wars",
    "title": "Yıldız Savaşları: Yeni Umut",
    "overview": "Yıldız Savaşları: Yeni Umut'ta Luke Skywalker, galaksiyi değiştirecek bir yolculuğa çıkar. Luke, İmparatorluğun kuruluşundan 19 yıl sonra çöl gezegen Tatooine'de yıllardır tek başına yaşayan Obi-Wan Kenobi ile karşılaşınca Asiler İttifakı mücadelesinin içine çekilir. Obi-Wan, Luke'u Jedi olarak eğitmeye başlarken Luke da güzel Asi Prenses Leia'yı Darth Vader ve kötü İmparatorluğun pençesinden kurtarmak için Obi-Wan ile zorlu bir göreve girişir.",
    "tagline": "A long time ago in a galaxy far, far away...",
    "releaseDate": "1977-05-25",
    "trailerLink": "https://www.youtube.com/watch?v=XsS1yE2f-hE",
    "runtime": 121,
    "backdrop": "/aAcdWuCyOs3YDNRf5m83CkDZwxn.jpg",
    "poster": "/6FfCtAuVAW8XJjZ7eWeLibRLWTw.jpg",
    "logo": "/dFNzaTlK2kv8UkWjP5tVPd6YwMU.png",
    "genres": [
        {
            "genreId": 28,
            "name": "Aksiyon"
        },
        {
            "genreId": 12,
            "name": "Macera"
        },
        {
            "genreId": 878,
            "name": "Bilim-Kurgu"
        }
    ],
    "watchCount": 0,
    "likeCount": 0,
    "ratingAverage": 0.0,
    "ratingCount": 0,
    "imdbId": "tt0076759",
    "wikidataId": "Q17738",
    "facebookId": "StarWars",
    "instagramId": "starwars",
    "twitterId": "starwars"
}
```

Filmin oyuncularını çekmek için aşağıdaki endpointi kullanacaksınız.

`/api/movies/{movieId}/casts`

pageNumber, pageSize, sortBy, sortOrder paramlarini kabul eder

response:

```
{

    "content": [
        {
            "originalName": "Paul Woodadge",
            "profilePath": null,
            "character": "Germanian Barbarian (uncredited)",
            "personId": "nm0001625"
        }
    ],
    "pageNumber": 0,
    "pageSize": 1,
    "totalElements": 37,
    "totalPages": 37,
    "lastPage": false
}
```

Filmin ekip kadrosunu cekmek icin asagidaki endpointi kullanacaksiniz. 

'/api/movies/{movieId}/crews'

cast ile ayni paramlari kabul eder
response:

```
{
    "content": [
        {
            "originalName": "Vernon L. Walker",
            "profilePath": "/efFZ1KZeJuvE4mWaLrceC9TS3vN.jpg",
            "department": "Crew",
            "job": "Special Effects",
            "personId": null
        }
    ],
    "pageNumber": 0,
    "pageSize": 1,
    "totalElements": 10,
    "totalPages": 10,
    "lastPage": false
}

```
