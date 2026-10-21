const crawl = require("./external_modules/crawler");

async function alfa() {
    await(crawl.crawler("http://www.hurriyet.com.tr/yazarlar/gila-benmayor/", "test", "hurriyet"));
    /*await(crawl.crawler("https://www.sozcu.com.tr/kategori/yilmaz-ozdil/", "test", "sozcu"));
    await(crawl.crawler("https://www.haberturk.com/htyazar/guntay-simsek-1019/", "test", "haberturk"));
    await(crawl.crawler("https://www.yenicaggazetesi.com.tr/esfender-korkmaz-18022y-p1.htm", "test", "yenicag"));
    await(crawl.crawler("http://www.milliyet.com.tr/yazarlar/attila-gokce/", "test", "milliyet"));
    await(crawl.crawler("https://www.fanatik.com.tr/yazarlar/mehmet-demirkol", "test", "fanatik"));
    await(crawl.crawler("https://www.takvim.com.tr/yazarlar/hakki_yalcin/arsiv?tc=4214&page=1", "test", "takvim"));
    await(crawl.crawler("https://www.sabah.com.tr/yazarlar/salih-tuna/arsiv?getall=true", "test", "sabah"));
    await(crawl.crawler("https://www.evrensel.net/yazar/65/i-sabri-durmaz/", "test", "evrensel"));
    await(crawl.crawler("https://www.turkiyegazetesi.com.tr/yazarlar/batuhan-yasar", "test", "TurkiyeGazetesi"));*/
};

alfa();