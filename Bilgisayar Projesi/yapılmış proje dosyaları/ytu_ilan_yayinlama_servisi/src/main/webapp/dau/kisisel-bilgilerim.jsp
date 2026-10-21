<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<%--
  Created by IntelliJ IDEA.
  User: mgunes
  Date: 08.12.2016
  Time: 17:05
  To change this template use File | Settings | File Templates.
--%>
<html>
    <head>
        <title>Kişisel Bilgilerim</title>
        <jsp:include page="html/head.html"></jsp:include>
    </head>
    <body>
    <jsp:include page="html/menu.html"></jsp:include>

    <div class="jumbotron container-fluid">
        <div class="row">
            <div class="col-md-1"></div>
            <div class="col-md-2">
                <div class="panel panel-primary">
                    <div class="panel-heading">
                        <p>Genel Bilgiler</p>
                    </div>
                    <div class="panel-body">
                        <b>Birim:</b><p>${user.dau.unitName}</p>
                        <b>Kullanıcı Adı</b><p>${user.userName}</p>
                    </div>
                </div>
            </div>
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
                        <form method="post" action="../updatedaupersonalinfo">
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
                            <button type="submit" class="btn btn-success">Bilgilerimi Güncelle</button>
                        </form>
                    </div>
                </div>
            </div>
            <div class="col-md-1"></div>
            <div class="col-md-3">
                <div class="panel panel-primary">
                    <div class="panel-heading">
                        <p>Parola Değiştir<p>
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
                        <form method="post" action="../updatedaupassword">
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
                            <button type="submit" class="btn btn-success">Parolayı Değiştir</button>
                        </form>
                    </div>
                </div>
            </div>
            </div>
        </div>
    </body>
</html>
