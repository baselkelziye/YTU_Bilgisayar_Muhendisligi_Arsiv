$(function () {
    $('#tblUrunler').DataTable({
        "language": {
            "url": "//cdn.datatables.net/plug-ins/9dcbecd42ad/i18n/Turkish.json"
        }
    });
    $('#tblRaflar').DataTable({
        "language": {
            "url": "//cdn.datatables.net/plug-ins/9dcbecd42ad/i18n/Turkish.json"
        }
    });
   
    $("#tblUrunler").on("click", ".btnUrunSil", function () {
        var btn= $(this);
        bootbox.confirm("Ürünü Silmek İstediğinize emin misiniz", function (result) {
            if (result) {
                var id = btn.data("id");
                $.ajax({
                    type: "GET",
                    url: "/Urun/Sil/",
                    data: { id:id },
                    success: function () {
                        btn.parent().parent().remove();
                    }
                });
            }
        }
        )

    });

    $("#tblRaflar").on("click", ".btnRafSil", function () {
        var btn = $(this);
        bootbox.confirm("Rafı Silmek İstediğinize emin misiniz", function (result) {
            if (result) {
                var id = btn.data("id");
                $.ajax({
                    type: "GET",
                    url: "/Raf/Sil/",
                    data: { id: id },
                    success: function () {
                        btn.parent().parent().remove();
                    }
                });
            }
        }
        )

    });



});









//function CheckDataTypeValid(dateElement) {
//    var value = $(dateElement).val();
//    if (value == "") {
//        $(dateElement).valid("false");
//    }
//    else {
//        $(dateElement).valid();
//    }
//}