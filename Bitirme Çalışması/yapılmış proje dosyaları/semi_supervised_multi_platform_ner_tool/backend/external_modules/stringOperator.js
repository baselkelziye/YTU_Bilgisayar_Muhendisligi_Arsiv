String.prototype.replaceAll = function (find, replace) {
    var str = this;
    return str.replace(new RegExp(find.replace(/[-\/\\^$*+?.()|[\]{}]/g, '\\$&'), 'g'), replace);
};

function replacer(text) {
    /*
    letB = [
        "!",
        "\”",
        "#",
        "$",
        "%",
        "&",
        "",
        "(",
        ")",
        "*",
        "+",
        ",",
        "-",
        ".",
        "/",
        "[",
        "\\",
        "]",
        "^",
        "_",
        "`",
        "{",
        "|",
        "}",
        "~",
        "£",
        "₺"
    ]
    for (let index = 0; index < letB.length; index++) {
        text = text.replaceAll(letB[index], " "+letB[index]+" ");
    }
    */

    text = text.replaceAll("!", " ! ");
    text = text.replaceAll("\"", " \" ");
    text = text.replaceAll("#", " # ");
    text = text.replaceAll("$", " $ ");
    text = text.replaceAll("%", " % ");
    text = text.replaceAll("&", " & ");
    text = text.replaceAll("'", " ' ");
    text = text.replaceAll("(", " ( ");
    text = text.replaceAll(")", " ) ");
    text = text.replaceAll("*", " * ");
    text = text.replaceAll("+", " + ");
    text = text.replaceAll(",", " , ");
    text = text.replaceAll("-", " - ");
    text = text.replaceAll(".", " . ");
    text = text.replaceAll("/", " / ");
    text = text.replaceAll("[", " [ ");
    text = text.replaceAll("\\", " \\ ");
    text = text.replaceAll("]", " ] ");
    text = text.replaceAll("^", " ^ ");
    text = text.replaceAll("_", " _ ");
    text = text.replaceAll("`", " ` ");
    text = text.replaceAll("{", " { ");
    text = text.replaceAll("|", " | ");
    text = text.replaceAll("}", " } ");
    text = text.replaceAll("~", " ~ ");
    text = text.replaceAll("?", " ? ");
    text = text.replaceAll(":", " : ");
    text = text.replaceAll(";", " ; ");
    text = text.replaceAll("=", " = ");
    text = text.replaceAll("<", " < ");
    text = text.replaceAll(">", " > ");
    text = text.replaceAll("@", " @ ");
    text = text.replaceAll("…", " . ");
    text = text.replaceAll("‘", "'");
    text = text.replaceAll("’", "'");
    text = text.replaceAll("“", "\"");
    text = text.replaceAll("”", "\"");
    text = text.replace(/([^!-~\s£₺…‘’“”üÜiİşŞöÖçÇğĞı])/g,"");
    return text;
}

module.exports = {
    replacer
}