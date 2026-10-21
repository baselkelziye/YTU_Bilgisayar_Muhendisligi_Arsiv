<%-- 
    Document   : iletisim
    Created on : 12.May.2016, 01:51:06
    Author     : must
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>


<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html">
        <jsp:include page="html/head.html"></jsp:include>
        <title>İletişim</title>
        <meta charset="UTF-8">
</head>
<body>
    <jsp:include page="html/header.jsp"></jsp:include>
    <div class="container">
        <div class="row">
            <div class="col-md-6">
                inelenen bir sayfa içeriğinin okuyucunun dikkatini dağıttığı 
                bilinen bir gerçektir. Lorem Ipsum kullanmanın amacı, sürekli 
                'buraya metin gelecek, buraya metin gelecek' yazmaya kıyasla 
                daha dengeli bir harf dağılımı sağlayarak okunurluğu artırmasıdır. 
                Şu anda birçok masaüstü yayıncılık paketi ve web sayfa düzenleyicisi,
                varsayılan mıgır metinler olarak Lorem Ipsum kullanmaktadır. 
                Ayrıca arama motorlarında 'lorem ipsu
            </div>
            <div class="col-md-6">
                <h4>İletişime geçmek için lütfen bilgileri eksiksiz doldurun</h4>
                <h5>(Verdiğiniz bilgiler 3. şahıslarla paylaşılmaz)</h5>
                <c:choose>
                    <c:when test="${gonderildi eq 1}">
                       <div class="alert alert-success">
                            <strong>Başarılı!</strong> Mesaj başarıyla iletildi. Sizinle vermiş olduğunuz 
                            mail adresi üzerinden iletişime geçilecektir.
                        </div>
                    </c:when>
                    <c:when test="${gonderildi eq 2}">
                    	<div class="alert alert-danger">
                    		<strong>Başarısız</strong> Mesaj iletilemedi. Lütfen tekrar deneyiniz.
                    	</div>
                    </c:when>
                </c:choose>
                <form id ="form1" method="post" action="sendmessageservlet" accept-charset="UTF-8">
                	<div class="form-group">
                		<label for="name">Adınız</label>
                		<input type="text" class="form-control" name="name" id="name" 
                		required title="Lütfen isminizi giriniz" pattern="[a-zA-Z]{1,30}">
                	</div>
                	<div class="form-group">
                		<label for="surname">Soyadınız</label>
                		<input type="text" class="form-control" name="surname" id="surname"
                		required title="Lütfen soyadınızı giriniz" pattern="[a-zA-ZğĞüÜşŞıİöÖçÇ]{1,30}">
                	</div>
                    <div class="form-group">
	                    <label for="title">Konu</label>
	                    <input type="text" class="form-control" name="title" pattern=".{5,30}" id="title"
	                    required title="Başlık 5-30 karakter aralığında olmalı"/>
                    </div>
                    <div class="form-group">
                    	<label for="message">Mesajınız</label>
                        <textarea class="form-control" name="message" pattern=".{10,300}" id="message"
                        required title="Mesajınız 10-300 karakter aralığında olmalı"> 
                        </textarea>
                    </div>
                    <div class="form-group">
                    	<label for="mail">Mail Adresiniz</label>
                        <input type="email" name="mail" class="form-control"
                        pattern="[a-z0-9._%+-]+@[a-z0-9.-]+\.[a-z]{2,3}$"/>
                    </div>
                    <button type="submit" class="btn btn-default">Mesajı Gönder</button>
                </form>
            </div>
        </div>
    </div>
    <jsp:include page="html/footer.html"/> 
    </body>
</html>
