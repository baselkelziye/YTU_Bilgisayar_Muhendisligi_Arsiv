String.prototype.replaceAll = function (find, replace) {
    var str = this;
    return str.replace(new RegExp(find.replace(/[-\/\\^$*+?.()|[\]{}]/g, '\\$&'), 'g'), replace);
};

function convertDate(dateString) {
    dateString = dateString.replaceAll(",", " ");
    dateString = dateString.replaceAll(".", " ");
    dateString = dateString.toLocaleLowerCase('tr-TR');
    dateArray = dateString.split(" ");

    if (dateArray[0] == '') {
        dateArray.shift();
    }

    var months = {
        'ocak': "01",
        'şubat': "02",
        'mart': "03",
        'nisan': "04",
        'mayıs': "05",
        'haziran': "06",
        'temmuz': "07",
        'ağustos': "08",
        'eylül': "09",
        'ekim': "10",
        'kasım': "11",
        'aralık': "12",
        'default': dateArray[1]
    };
    day = {
        '1' : "01",
        '2' : "02",
        '3' : "03",
        '4' : "04",
        '5' : "05",
        '6' : "06",
        '7' : "07",
        '8' : "08",
        '9' : "09",
        'default' : dateArray[0]

    }
    return dateArray[2] + '-' + (months[dateArray[1]] || months["default"]) + '-' + day[dateArray[0] || day["default"]];
}

module.exports = {
    convertDate
}
