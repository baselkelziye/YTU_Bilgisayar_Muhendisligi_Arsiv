<%-- 
    Document   : newannouncement
    Created on : 22.Nis.2016, 13:55:41
    Author     : must
--%>

<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<%@page contentType="text/html" pageEncoding="UTF-8"%>

<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <link rel="stylesheet" type="text/css" href="../css/bootstrap.css">
        <jsp:include page="html/head.html"/>
    	<title>İlan Oluştur</title>
	</head>
	<body>
		<jsp:include page="html/menu.html"/>
		<div class="jumbotron container-fluid">
			<div class="row">
                <div class="col-md-3"></div>
				<div class="col-md-5">
                    <div class="panel panel-primary">
                        <div class="panel-heading">
                            <p>Yeni Bir İlan Oluşturun</p>
                        </div>
                        <div class="panel-body">
                            <c:choose>
                                <c:when test="${olusturuldu eq 1}">
                                    <div class="alert alert-success">
                                        <strong>Oluşturuldu!</strong> İlanınız başarıyla oluşturuldu.
                                        İlanınızı <a href="../mypassiveannouncements"><strong>buradan</strong></a> düzenleyebilir veya
                                        aktif hale getirebilirsiniz.
                                    </div>
                                    <div class="alert alert-info">
                                        Oluşturduğunuz ilanları <a href="../searchmyanninit"><strong>buradan</strong></a> görebilirsiniz.
                                    </div>
                                </c:when>
                                <c:when test="${olusturuldu eq 2}">
                                    <div class="alert alert-danger">
                                        <strong>Oluşturulamadı!</strong> İlan oluşturulurken bir hata
                                        meydana geldi. Lütfen tekrar deneyiniz.
                                    </div>
                                </c:when>
                            </c:choose>

                            <form method="POST" action="../announcementcreate">
                                <div class="form-group">
                                    <label for="title">İlan Başlığı</label>
                                    <input type="text" name="title" id="title" class="form-control" pattern=".{1,30}"
                                           required title="1-30 karakter aralığında olmalı"/>
                                </div>
                                <div class="form-group">
                                    <label for="brief">Kısa Açıklama</label>
                                    <textarea name="brief" id="brief" class="form-control"  rows="2" cols="50"></textarea>
                                </div>
                                <div class="form-group">
                                    <label for="content">İlan Detayları</label>
                                    <textarea rows="10" cols="50" name="content" id="content" class="form-control"></textarea>
                                </div>
                                <div class="form-group">
                                    <label for="t">İlan Tipi</label>
                                    <select id="t" name="type" class="form-control">
                                        <c:forEach var="item" items="${annType}">
                                            <c:if test="${item.id ne -1}">
                                                <option value="${item.id}">
                                                    <c:out value="${item.title}"/>
                                                </option>
                                            </c:if>
                                        </c:forEach>
                                    </select>
                                </div>
                                <div class="form-group">
                                    <label for="ct">İlan Kategorisi</label>
                                    <h5>İlanınız herhangi kategoriye girmiyorsa "root-category" olarak seçin.</h5>
                                    <select id="ct" name="category" class="form-control">
                                        <c:forEach var="item" items="${categoryList}">
                                            <c:if test="${item.id ne -1 && item.id ne 0}">
                                                <option selected disabled value="${item.id}">
                                                    <c:out value="${item.categoryName} Alt Kategorileri"/>
                                                </option>
                                                <c:forEach var="childItem" items="${item.children}">
                                                    <option value="${childItem.id}">
                                                        <c:out value="----${childItem.categoryName}"/>
                                                    </option>
                                                </c:forEach>
                                            </c:if>
                                        </c:forEach>
                                    </select>
                                </div>
                                <div class="form-group">
                                    <label for="language">İlanın Dili</label>
                                    <select name="language" class="form-control" id="language">
                                        <option value="türkçe">Türkçe</option>
                                        <option value="ingilizce">İngilizce</option>
                                    </select>
                                </div>
                                <button type="submit" class="btn btn-success">Oluştur</button>
                            </form>
                        </div>
                    </div>
				</div>
			</div>
			<div class="row">
				<jsp:include page="../html/footer.html"></jsp:include>
			</div>
		</div>
	</body>
</html>
