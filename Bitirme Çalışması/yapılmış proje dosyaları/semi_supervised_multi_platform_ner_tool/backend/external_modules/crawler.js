const puppeteer = require('puppeteer');
const fse = require('fs-extra');
const stringOperator = require('./stringOperator');
const dateParser = require('./turkishDateParser');

var newspapers = {
    sozcu : {
        urlBegin : "",
        lastTextUrl : "div.news-body > ul > li:nth-child(1) > a",
        author : "div.hidden-columnist-name",
        authorType : "innerText",
        text : "div.author-the-content.content-element",
        date : "div.editor-col._flex._aic > div > div > span",
    },
    evrensel : {
        urlBegin : "",
        lastTextUrl : "#metin > div > div.haber-metin > div > div > div > div > div > ul > li:nth-child(1) > a",
        author : "h6 > a",
        authorType : "title",
        text : ".haber-metin",
        date : "div.tarih > div:nth-child(1)",
    },
    haberturk : {
        urlBegin : "https://www.haberturk.com/",
        lastTextUrl : "div.author-container.horizontal > div > a",
        author : "#newsWrapper > section > div > div.left > div.info > span.name",
        authorType : "innerText",
        text : "#newsWrapper > article",
        date : "time:nth-child(1)",
    },
    yenicag : {
        urlBegin : "",
        lastTextUrl : "#base_middle > div > ul > li:nth-child(1) > a",
        author : "div.info > h3 > a > span",
        authorType : "innerText",
        text : "#author_article_content",
        date : "div.content-date > span",
    },
    TurkiyeGazetesi : {
        urlBegin : "",
        lastTextUrl : "#contentOrta_ListViewProducts_Label2_0 > a",
        author : "div:nth-child(2) > span > strong",
        authorType : "innerText",
        text : "#article_body",
        date : "#article_holder > p",
    },
    hurriyet : {
        urlBegin : "https://www.hurriyet.com.tr/",
        lastTextUrl : "h2 > a",
        author : "h2 > a",
        authorType : "innerText",
        text : "div.article-content.news-text",
        date : "div.article-date",
    },
    milliyet : {
        urlBegin : "https://www.milliyet.com.tr/",
        lastTextUrl : "h2 > a",
        author : "h5",
        authorType : "innerText",
        text : "div.article__detail",
        date : "div.article__time > time",
    },
    fanatik : {
        urlBegin : "https://www.fanatik.com.tr/",
        lastTextUrl : "ol > li:nth-child(1) > a",
        author : "div.author__name > a",
        authorType : "innerText",
        text : "div.news-detail__body > div",
        date : "h6 > span:nth-child(1)",
    },
    takvim : {
        urlBegin : "https://www.takvim.com.tr/",
        lastTextUrl : "span:nth-child(2) > a",
        author : "div.title > a > span:nth-child(1)",
        authorType : "innerText",
        text : "#haberDescription",
        date : "div.info > ul > li:nth-child(1)",
    },
    sabah : {
        urlBegin : "https://www.sabah.com.tr/",
        lastTextUrl : "div:nth-child(3) > div > div:nth-child(1) > figure > figcaption > a",
        author : "span > strong",
        authorType : "innerText",
        text : "div > div:nth-child(3) > div > div",
        date : "figcaption > span",
    }
}

async function crawler(url,category = "default",newspaper) {
    queryUrl = newspapers[newspaper].lastTextUrl;
    queryAuthor = newspapers[newspaper].author;
    queryText = newspapers[newspaper].text;
    queryDate = newspapers[newspaper].date;
    queryAuthorType = newspapers[newspaper].authorType;

    let browser = await puppeteer.launch();
    let page = await browser.newPage();

    await page.goto(url, { waitUntil: 'networkidle2' });
    
    lastTextUrl = newspapers[newspaper].urlBegin;
    lastTextUrl += await page.evaluate((queryUrl) => {
        return document.querySelector(queryUrl).getAttribute("href");
    },queryUrl)
    
    await page.goto(lastTextUrl, { waitUntil: 'networkidle2' });

    let data = await page.evaluate((queryAuthor,queryAuthorType,queryText,queryDate) => {
        if (queryAuthorType == "title"){
            author = document.querySelector(queryAuthor).getAttribute("title").toLocaleLowerCase('tr-TR');
        } else {
            author = document.querySelector(queryAuthor).innerText.toLocaleLowerCase('tr-TR');
        }
        
        text = document.querySelector(queryText).innerText
        date = document.querySelector(queryDate).innerText
        return {
            author,
            date,
            text
        }
    },queryAuthor,queryAuthorType,queryText,queryDate)

    fse.outputFileSync('texts/' + category + '/' + data.author + '/' + dateParser.convertDate(data.date) + '.txt', stringOperator.replacer(data.text));

    await browser.close();
}

module.exports = {
    crawler
}