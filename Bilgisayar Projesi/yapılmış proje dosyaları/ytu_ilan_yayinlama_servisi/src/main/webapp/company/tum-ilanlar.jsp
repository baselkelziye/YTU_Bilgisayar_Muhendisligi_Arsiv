<%-- 
    Document   : allannouncements
    Created on : 30.Nis.2016, 16:32:48
    Author     : must
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Tüm İlanlar</title>
    </head>
    <body>
        <jsp:include page="html/menu.html"/>
        <div class="jumbotron container-fluid">
            <div class="row">
                <div class="col-md-2"></div>
                <div class="col-md-8">
                    <h1>Tüm ilanlar</h1>
                    <table class="table table-stripped">
                        <thead>
                        <tr>
                            <th>İlan No</th>
                            <th>Başlık</th>
                            <th>Ön Açıklama</th>
                            <th>Durum</th>
                            <th>Başvuru Sayısı</th>
                        </tr>
                        </thead>
                        <tbody>
                        <form action="announcementdetailservlet" method="post">
                            <c:forEach var="item" items="${announcements}">
                                <tr>
                                    <td><input type="radio" name="announcement" value="${item.id}"></td>
                                    <td>${item.id}</td>
                                    <td>${item.title}</td>
                                    <td>${item.brief}</td>
                                    <td>${item.state}</td>
                                    <td>${item.numberOfPageViews}</td>
                                    <td></td>
                                </tr>
                            </c:forEach>
                            <input type="submit" value="Detaya Git"/>
                        </form>
                        </tbody>
                    </table>
                </div>
            </div>
        </div>
    </body>
</html>
