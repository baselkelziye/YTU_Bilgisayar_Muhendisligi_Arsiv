<%--
  Created by IntelliJ IDEA.
  User: mgunes
  Date: 08.12.2016
  Time: 20:46
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<html>
    <head>
        <title>Kişisel Bilgilerim</title>
        <jsp:include page="html/head.html"/>
    </head>
    <body>

        <script>
            $(document).on("click", ".open-deleteCommWayDialog", function (e) {
                e.preventDefault();
                var _self = $(this);
                var way = _self.data('commway');
                var value = _self.data('commvalue');
                $("#way").val(way);
                $("#value").val(value);
                $(_self.attr('href')).modal('show');
            });

            $(document).on("click", ".open-editCommWayDialog", function (e) {
                e.preventDefault();
                var _self = $(this);
                var way = _self.data('commway');
                var value = _self.data('commvalue');
                $("#cway").val(way);
                $("#oldway").val(way);
                $("#cvalue").val(value);
                $("#oldvalue").val(value);
                $(_self.attr('href')).modal('show');
            });
        </script>

        <div class="modal fade" id="editCommWayDialog" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
            <div class="modal-dialog">
                <!-- Modal content-->
                <div class="modal-content">
                    <div class="modal-header">
                        <button type="button" class="close" data-dismiss="modal">&times;</button>
                        <h4 class="modal-title">İletişim Bilgisi Düzenle</h4>
                    </div>
                    <div class="modal-body">
                        <p>Lütfen düzenlemek istediğiniz kısımları değiştirin.</p>
                        <form method="post">
                            <input type="hidden" name="oldway" id="oldway">
                            <input type="hidden" name="oldvalue" id="oldvalue">
                            <div class="form-group">
                                <label for="cway">İletişim Tipi</label>
                                <input type="text" id="cway" class="form-control" pattern=".{1,30}" name="cway"
                                       required title="1-30 karekter aralığında olmalıdır">
                            </div>
                            <div class="form-group">
                                <label for="cvalue">İletişim Değeri</label>
                                <input type="text" id="cvalue" class="form-control" pattern=".{1,30}" name="cvalue"
                                       required title="1-30 karekter aralığında olmalıdır">
                            </div>
                            <input formaction="../updatecompanycommway" type="submit" class="btn btn-default" value="Evet">
                            <button type="button" class="btn btn-default" data-dismiss="modal">Hayır</button>
                        </form>
                    </div>
                </div>
            </div>
        </div>

        <div class="modal fade" id="deleteCommWayDialog" tabindex="-1" role="dialog" aria-labelledby="myModalLabel2" aria-hidden="true">
            <div class="modal-dialog">
                <!-- Modal content-->
                <div class="modal-content">
                    <div class="modal-header">
                        <button type="button" class="close" data-dismiss="modal">&times;</button>
                        <h4 class="modal-title">İletişim Bilgisini Silin!</h4>
                    </div>
                    <div class="modal-body">
                        <p>Silmek İstediğinize Emin Misiniz?</p>
                        <form method="post">
                            <input type="hidden" name="commType" id="way">
                            <input type="hidden" name="commValue" id="value">
                            <input formaction="../deletecommway" type="submit" class="btn btn-default" value="Evet">
                            <button type="button" class="btn btn-default" data-dismiss="modal">Hayır</button>
                        </form>
                    </div>
                </div>
            </div>
        </div>

        <jsp:include page="html/menu.html"/>
        <div class="jumbotron container-fluid">
            <div class="row">
                <div class="col-md-1"></div>
                <div class="col-md-3">
                    <div class="panel panel-primary">
                        <div class="panel-heading">
                            <p>Kişisel Bilgileriniz</p>
                        </div>
                        <div class="panel-body">
                            <c:choose>
                                <c:when test="${guncelle eq 1}">
                                    <div class="alert alert-success">
                                        Bilgileriniz başarıyla güncellendi.
                                    </div>
                                </c:when>
                                <c:when test="${guncelle eq 2}">
                                    <div class="alert alert-danger">
                                        Bir hata meydana geldi. Lütfen daha sonra tekrar deneyiniz.
                                    </div>
                                </c:when>
                            </c:choose>
                            <form method="post" action="../updatecompanyuser">
                                <div class="form-group">
                                    <label for="name">Adınız</label>
                                    <input type="text" id="name" name="name" class="form-control" value="${user.name}"
                                           pattern=".{3,40}" required title="İsim 3-40 karakter aralığında olmalıdır">
                                </div>
                                <div class="form-group">
                                    <label for="surname">Soyadınız</label>
                                    <input type="text" id="surname" name="surname" class="form-control" value="${user.surname}"
                                           pattern=".{3,40}" required title="Soyisim 3-40 karakter aralığında olmalıdır">
                                </div>
                                <div class="form-group">
                                    <label for="contactMail">Mail Adresiniz</label>
                                    <input type="email" name="contactMail" id="contactMail" class="form-control" value="${user.contactMail}"
                                           pattern=".{3,40}">
                                </div>
                                <div class="form-group">
                                    <label for="contactTel">Telefon Numaranız</label>
                                    <input type="text" name="contactTel" id="contactTel" class="form-control" value="${user.contactTel}"
                                           pattern=".{11,11}" required title="Telefon numarası 11 karakter aralığında olmalıdır">
                                </div>
                                <button type="submit" class="btn btn-default">Bilgilerimi Güncelle</button>
                            </form>
                        </div>
                    </div>
                </div>
                <div class="col-md-3">
                    <div class="panel panel-primary">
                        <div class="panel-heading">
                            <p>Şirket Bilgileri</p>
                        </div>
                        <div class="panel-body">
                            <form method="post" action=../"updatecompanyinfo">
                                <div class="form-group">
                                    <label for="companyName">Şirket Adı</label>
                                    <input type="text" name="companyName" id="companyName" value="${user.companyName}" class="form-control"
                                           pattern=".{3, 30}" required title="Şirket Adı 3-30 karakter aralığında olmalıdır">
                                </div>
                                <label for="location">Konum</label>
                                <input type="text" name="location" id="location" value="${user.location}" class="form-control"
                                       pattern=".{3, 30}" required title="Konum 3-30 karakter aralığında olmalıdır">
                            </form>
                            <button type="submit" class="btn btn-default">Bilgileri Güncelle</button>
                        </div>
                    </div>
                    <div class="panel panel-primary">
                        <div class="panel-heading">
                            <p>Parola Değiştir</p>
                        </div>
                        <div class="panel-body">
                            <c:choose>
                                <c:when test="${parolaguncelle eq 1}">
                                    <div class="alert alert-success">
                                        Parolanız güncellendi.
                                    </div>
                                </c:when>
                                <c:when test="${parolaguncelle eq 2}">
                                    <div class="alert alert-danger">
                                        Eski parolanızı yanlış girdiniz.
                                    </div>
                                </c:when>
                            </c:choose>

                            <form method="post" action="../updatecompanypassword">
                                <div class="form-group">
                                    <label for="oldPassword">Eski paralonız</label>
                                    <input type="password" name="oldPassword" id="oldPassword"
                                           pattern=".{6,16}" class="form-control"
                                           required title="Parola en az 6 an fazla 16 karakter olabilir."/>
                                </div>
                                <div class="form-group">
                                    <label for="newPassword">Yeni paralonız</label>
                                    <input type="password" name="newPassword" id="newPassword"
                                           pattern=".{6,16}" class="form-control"
                                           required title="Parola en az 6 an fazla 16 karakter olabilir."/>
                                </div>
                                <div class="form-group">
                                    <label for="newPasswordAgain">Yeni paralonız(Tekrar)</label>
                                    <input type="password" name="newPasswordAgain" id="newPasswordAgain"
                                           pattern=".{6,16}" class="form-control"
                                           required title="Parola en az 6 an fazla 16 karakter olabilir."/>
                                </div>
                                <button type="submit" class="btn btn-default">Parolayı Değiştir</button>
                            </form>
                        </div>
                    </div>
                </div>

                <div class="col-md-4">
                    <div class="panel panel-primary">
                        <div class="panel-heading">
                            <p>İletişim Bilgisi Ekle</p>
                        </div>
                        <div class="panel-body">
                            <form method="post" action="../addcommwaytocompany">
                                <div class="form-group">
                                    <label for="newCommType">İletişim Tipi</label>
                                    <input type="text" id="newCommType" class="form-control" pattern=".{1,30}" name="newCommType"
                                           required title="1-30 karekter aralığında olmalıdır">
                                </div>
                                <div class="form-group">
                                    <label for="newCommValue">Değeri</label>
                                    <input type="text" id="newCommValue" class="form-control" pattern=".{1,30}" name="newCommValue"
                                           required title="1-30 karekter aralığında olmalıdır">
                                </div>
                                <button type="submit" class="btn btn-default">Ekle</button>
                            </form>
                        </div>
                    </div>
                    <div class="panel panel-primary">
                        <div class="panel-heading">
                            <p>Şirket İletişim Bilgileri</p>
                        </div>
                        <div class="panel-body">
                            <c:choose>
                                <c:when test="${iletisimsil eq 1}">
                                    <div class="alert alert-success">
                                        İletişim bilgisi silindi.
                                    </div>
                                </c:when>
                                <c:when test="${iletisimsil eq 2}">
                                    <div class="alert alert-danger">
                                        İletişim bilgisi silinemedi.
                                        Lütfen daha sonra tekrar deneyiniz.
                                    </div>
                                </c:when>
                                <c:when test="${iletisimguncelle eq 1}">
                                    <div class="alert alert-success">
                                        İletişim bilgisi güncellendi.
                                    </div>
                                </c:when>
                                <c:when test="${iletisimgunceşşe eq 2}">
                                    <div class="alert alert-danger">
                                        İletişim bilgisi güncellenemedi.
                                        Lütfen daha sonra tekrar deneyiniz.
                                    </div>
                                </c:when>
                            </c:choose>

                            <c:choose>
                                <c:when test="${iletisimeklendi eq 1}">
                                    <div class="alert alert-success">
                                        Yeni iletişim bilginiz eklendi.
                                    </div>
                                </c:when>
                                <c:when test="${iletisimeklendi eq 2}">
                                    <div class="alert alert-danger">
                                        Bir hata meydana geldi.
                                        Lütfen daha sonra tekrar deneyiniz.
                                    </div>
                                </c:when>
                            </c:choose>
                            <table class="table table-stripped">
                                <thead>
                                    <tr>
                                        <th>İletişim Tipi</th>
                                        <th>Değeri</th>
                                        <th>İşlem</th>
                                    </tr>
                                </thead>
                                <tbody>
                                    <c:forEach var="item" items="${user.commWays}">
                                        <tr>
                                            <td>${item.pk.commType}</td>
                                            <td>${item.pk.commValue}</td>
                                            <td>
                                                <a href="#editCommWayDialog"
                                                   title="Düzenle"
                                                   data-commway="${item.pk.commType}"
                                                   data-commvalue="${item.pk.commValue}"
                                                   class="open-editCommWayDialog"
                                                   data-toggle="modal">
                                                    <span style="color:dodgerblue" class="glyphicon glyphicon-pencil"></span>
                                                </a>
                                                <a href="#deleteCommWayDialog"
                                                   title="Sil"
                                                   data-commWay="${item.pk.commType}"
                                                   data-commValue="${item.pk.commValue}"
                                                   class="open-deleteCommWayDialog"
                                                   data-toggle="modal">
                                                    <span style="color:red" class="glyphicon glyphicon-remove" title="Sil"></span>
                                                </a>
                                            </td>
                                        </tr>
                                    </c:forEach>
                                </tbody>
                            </table>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </body>
</html>
