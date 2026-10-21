<%-- 
    Document   : displaymessage
    Created on : 31.Mar.2016, 02:04:00
    Author     : must
--%>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>
<%@page contentType="text/html" pageEncoding="UTF-8"%>


<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <jsp:include page="html/head.html"/>
        <link rel="stylesheet" type="text/css" href="css/style.css">
        <title>Mesajları Oku</title>
    </head>
    <body>
        <jsp:include page="html/menu.html"/>
        <div class="jumbotron container-fluid">
            <div class="row">
                <div class="col-md-1"></div>
                <div class="col-md-9">
                    <table class="table table-stripped">
                        <thead>
                            <tr>
                                <th>Mesaj No</th>
                                <th>Başlık</th>
                                <th>Gönderen</th>
                                <th>Zaman</th>
                                <th>Okundu</th>
                                <th>İşlem</th>
                            </tr>
                        </thead>
                        <tbody>
                            <c:forEach var="item" items="${message}">
                                <tr>
                                    <td>${item.messageNo}</td>
                                    <td>${item.messageTitle}</td>
                                    <td>${item.senderName} ${item.senderSurname}</td>
                                    <td><fmt:formatDate pattern="dd-MM-yyyy" value="${item.pk.dateTime}" /></td>
                                    <td>${item.isRead}</td>
                                    <td>
                                        <form method="post">
                                            <input type="hidden" name="messagePK" value="${item.messageNo}" />
                                            <input
                                                type="submit" class="btn btn-success"
                                                value="Mesajı Görüntüle" formaction="../messagedetail">
                                            <input type="submit" value="Sil" formaction="#" class="btn btn-danger">
                                        </form>
                                    </td>
                                </tr>
                            </c:forEach>
                        </tbody>
                    </table>
                </div>
            </div>
        </div>
        <jsp:include page="html/footer.html"/>
    </body>
</html>
