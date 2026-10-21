<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%--
  Created by IntelliJ IDEA.
  User: mgunes
  Date: 28.01.2017
  Time: 15:35
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
    <head>
        <jsp:include page="html/head.html"/>
        <title>İlanı Düzenleyin</title>
    </head>
    <body>
        <jsp:include page="html/menu.html"/>
        <div class="jumbotron container-fluid">
            <div class="col-md-3"></div>
            <div class="row">
                <div class="col-md-6">
                    <a href="../mypassiveannouncements" class="btn btn-info">
                        <span class="glyphicon glyphicon-arrow-left"></span> Pasif İlanlarım
                    </a>

                    <h4>${announcement.id} nolu ilanınızı düzenleyin</h4>
                    <c:choose>
                        <c:when test="${guncellendi eq 1}">
                            <div class="alert alert-success">
                                <strong>Güncellendi!</strong> İlanınız başarıyla güncellendi.
                            </div>
                        </c:when>
                        <c:when test="${guncellendi eq 2}">
                            <div class="alert alert-danger">
                                Bir hata meydana geldi
                            </div>
                        </c:when>
                    </c:choose>

                    <form method="POST" action="../announcementsave">
                        <div class="form-group">
                            <label for="title">İlan Başlığı</label>
                            <input type="text" name="title" id="title" class="form-control" pattern=".{1,30}"
                                   required title="1-30 karakter aralığında olmalı" value="${announcement.title}"/>
                        </div>
                        <div class="form-group">
                            <label for="brief">Kısa Açıklama</label>
                            <textarea name="brief" id="brief" class="form-control" rows="2" cols="50">${announcement.brief}</textarea>
                        </div>
                        <div class="form-group">
                            <label for="content">İlan Detayları</label>
                            <textarea rows="10" cols="50" name="content" id="content" class="form-control">${announcement.brief}</textarea>
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
                                        <option disabled value="${item.id}">
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
                        <input type="hidden" name="id" value="${announcement.id}">
                        <button type="submit" class="btn btn-success">Oluştur</button>
                    </form>
                </div>
            </div>
        </div>
    </body>
</html>
