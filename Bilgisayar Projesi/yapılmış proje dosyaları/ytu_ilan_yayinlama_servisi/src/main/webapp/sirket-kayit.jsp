<%-- 
    Document   : sirketkayit
    Created on : 12.May.2016, 02:41:06
    Author     : must
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>

<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Şirket Kayıt</title>
        <jsp:include page="html/head.html"></jsp:include>
    </head>
<body>
    <jsp:include page="html/header.jsp"></jsp:include>
    <div class="container-fluid">
        <div class="row">
            <div class="col-md-4">

            </div>
            <div class="col-md-4">
                <h2>Şirket kayıt</h2>
                <p>Lütfen istenen bilgileri eksiksiz giriniz</p>

                <c:choose>
                    <c:when test="${kayit eq 1}">
                        <div class="alert-success">
                            <strong>Başarılı!</strong> Kullanıcı hesabınız başarıyla oluşturulmuştur.
                        </div>
                        <div class="alert-info">
                            Hesabınıza <strong><a href="logininitializeservlet">buradan</a></strong> giris yapabilrsiniz
                        </div>
                    </c:when>
                    <c:when test="${kayit eq 2}">
                        <div class="alert-danger">
                            Bu kullanıcı adı alınmış. Lütfen başka bir kullanıcı adı seçiniz.
                        </div>
                    </c:when>
                    <c:when test="${kayit eq 3}">
                        <div class="alert-danger">
                            Bir hata meydana geldi.
                        </div>
                    </c:when>
                </c:choose>

                <!-- tüm alanlar dolduruldu mu -->
                <form method="post" action="companysaveservlet">
                    <div class="form-group">
                        <label for="username">Kullanıcı Adı</label> <!-- alınmış mı kontrolü yap -->
                        <input type="text" class="form-control" name="username" id="username" value="${kullaniciAdi}">
                    </div>
                    <div class="form-group">
                        <label for="company_name">Kurum Adı</label>
                        <input type="text" class="form-control" name="company_name" id="company_name" value="${kurumAdi}">
                    </div>
                    <div class="form-group">
                        <label for="telephone_number">Telefon</label> <!-- +90  regex-->
                        <input type="tel" class="form-control" name="telephone_number" id="telephone_number" value="${telefonNumarasi}">
                    </div>
                    <div class="form-group">
                        <label for="email">Mail Adresi</label> <!-- regex -->
                        <input type="email" class="form-control" name="email" id="email" value="${mail}">
                    </div>
                    <div class="form-group">
                        <label for="password">Parola</label>
                        <input type="password" class="form-control" name="password" id="password">
                    </div>
                    <div class="form-group">
                        <label for="password">Parola(Tekrar)</label> <!-- Doğrulama jquery -->
                        <input type="password" class="form-control" id="password" >
                    </div>
                    <div class="form-group">
                        <label for="name">(Yetkilinin) Adı</label>
                        <input type="text" name="name" id="name" class="form-control" value="${name}"
                               pattern=".{3,40}" required title="İsim 3-40 karakter aralığında olmalıdır">
                    </div>
                    <div class="form-group">
                        <label for="surname">(Yetkilinin) Soyadı</label>
                        <input type="text" name="surname" id="surname" class="form-control" value="${surname}"
                               pattern=".{3,40}" required title="Soyisim 3-40 karakter aralığında olmalıdır">
                    </div>
                    <div class="form-group">
                        <label for="contactMail">(Yetkilinin) Mail Adresi</label>
                        <input type="email" name="contactMail" id="contactMail" class="form-control" value="${contactMail}"
                               pattern=".{3,40}" required title="Soyisim 3-70 karakter aralığında olmalıdır">
                    </div>
                    <div class="form-group">
                        <label for="contactTel">(Yetkilinin) Telefon Numarası</label>
                        <input type="text" name="contactTel" id="contactTel" class="form-control" value="${contactTel}"
                               pattern=".{11,11}" required title="Telefon numarası 11 karakter aralığında olmalıdır">
                    </div>
                    <div class="form-group">
                        <label for="kep">Kayıtlı Elektronik E-Posta</label>
                        <input type="text" name="kep" id="kep" class="form-control" value="${kep}"
                               required title="Zorunludur">
                    </div>
                    <div class="form-group">
                        <label for="mersis">Mersis No</label>
                        <input type="text" name="mersis" id="mersis" class="form-control" value="${mersis}"
                               required title="Zorunludur">
                    </div>
                    <input type="submit" value="Kayıt Ol" class="btn btn-default">
                </form>
            </div>
        </div>
    </div>

    <jsp:include page="html/footer.html"/> 
</body>
</html>
