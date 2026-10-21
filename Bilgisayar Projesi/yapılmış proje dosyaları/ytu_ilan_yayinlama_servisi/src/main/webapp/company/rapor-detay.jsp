<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%--
  Created by IntelliJ IDEA.
  User: mgunes
  Date: 23.01.2017
  Time: 18:04
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <jsp:include page="html/head.html"/>
    <title>Ceza Raporu</title>
</head>
<body>
<jsp:include page="html/menu.html"/>
<div class="jumbotron container-fluid">
    <div class="row">
        <div class="col-md-3"></div>
        <div class="col-md-6">
            <a href="../complaintreporttocompany" class="btn btn-primary">
                <span class="glyphicon glyphicon-arrow-left"></span> Listeye Dön
            </a>
            <h4><b>İlan Detayları</b></h4>
            <table class="table table-hovered">
                <tr>
                    <th>Şirket Adı</th>
                    <td>${announcement.ownerCompany.companyName}</td>
                </tr>
                <tr>
                    <th>İlan Başlığı</th>
                    <td>${announcement.title}</td>
                </tr>
                <tr>
                    <th>Kısa Açıklama</th>
                    <td>${announcement.brief}</td>
                </tr>
                <tr>
                    <th colspan="2">Detay</th>
                </tr>
                <tr>
                    <td colspan="2">${announcement.content }</td>
                </tr>
                <tr>
                    <th>Görüntülenme Sayısı</th>
                    <td>${announcement.numberOfPageViews}</td>
                </tr>
                <tr>
                    <th>Başvuru sayısı</th>
                    <td>${fn:length(announcement.appStudentList)}</td>
                </tr>
                <tr>
                    <th>Kategori</th>
                    <td>${announcement.category.categoryName }</td>
                </tr>
                <tr>
                    <th>Yayınlanma Tarihi</th>
                    <td><fmt:formatDate pattern="dd-MM-yyy" value="${announcement.publishDate }"/></td>
                </tr>
            </table>

            <h4><b>Ceza Hareketleri</b></h4>
            <table class="table table-stripped">
                <thead>
                <tr>
                    <th>Durum</th>
                    <th>Tarih</th>
                    <th>Açıklama</th>
                </tr>
                </thead>
                <tbody>
                <c:forEach var="item" items="${reportList}">
                    <tr>
                        <td>${item.currentState}</td>
                        <td><fmt:formatDate pattern="dd-MM-yyyy" value="${item.operationDate}"/></td>
                        <td>${item.description}</td>
                    </tr>
                </c:forEach>
                </tbody>
            </table>

            <h4><b>Şikayet Mesajları</b> <i>${fn:length(announcement.complaintList)} mesaj</i></h4>
            <c:forEach var="item" items="${announcement.complaintList}">
                <b>Mesaj:</b>${item.description}<br/><br/>
            </c:forEach>
        </div>
    </div>
</div>
</body>
</html>
