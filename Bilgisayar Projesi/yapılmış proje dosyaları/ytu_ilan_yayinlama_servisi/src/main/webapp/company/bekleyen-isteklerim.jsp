<%--
  Created by IntelliJ IDEA.
  User: mgunes
  Date: 05.12.2016
  Time: 05:39
  To change this template use File | Settings | File Templates.
--%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>
<html>
    <head>
        <title>Bekleyen İstekler</title>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <jsp:include page="html/head.html"/>
    </head>
    <body>
        <jsp:include page="html/menu.html"/>
        <div class="jumbotron container-fluid">
            <div class="row">
                <div class="col-md-3"></div>
                <div class="col-md-6">
                    <h3>Bekleyen İstekleriniz</h3>
                    <c:if test="${fn: length(packetList) eq 0}">
                        <p><i>Bekleyen isteğiniz bulunmamaktadır.</i></p>
                    </c:if>
                    <table class="table table-hovered">
                        <thead>
                            <tr>
                                <th>İstek Tarihi</th>
                                <th>Paket Adı</th>
                                <th>Bağış Kabul Birimi</th>
                                <th>Fiyat(TL)</th>
                            </tr>
                        </thead>
                        <tbody>
                            <c:forEach var="item" items="${packetList}">
                                <tr>
                                    <td><fmt:formatDate pattern="dd-MM-yyyy" value="${item.timeToRequest}"/></td>
                                    <td>${item.packet.title}</td>
                                    <td>${item.packet.accountInfo.ownerUnit.unitName}</td>
                                    <td align="right">${item.packet.price}</td>
                                </tr>
                            </c:forEach>
                        </tbody>
                    </table>
                </div>
            </div>
        </div>
    </body>
</html>
