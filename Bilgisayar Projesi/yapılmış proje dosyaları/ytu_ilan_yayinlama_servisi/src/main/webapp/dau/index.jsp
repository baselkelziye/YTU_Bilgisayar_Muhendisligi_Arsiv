<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <jsp:include page="html/head.html"></jsp:include>
        <title>BKB Anasayfa</title>
    </head>
    <body>
        <jsp:include page="html/menu.html"></jsp:include>
        <div class="jumbotron container-fluid">
            <div class="row">
                <div class="col-md-3"></div>
                <div class="col-md-6">
                    <p>Bildirimleriniz</p>
                    <c:forEach var="item" items="${notification}">
                        <c:choose>
                            <c:when test="${item.state eq 'positive'}">
                                <div class="alert-success">
                                    <fmt:formatDate pattern="dd-MM-yyyy" value="${item.triggerDate}"/> ${item.description}
                                </div><br/>
                            </c:when>
                            <c:when test="${item.state eq 'negative'}">
                                <div class="alert-danger">
                                    <fmt:formatDate pattern="dd-MM-yyyy" value="${item.triggerDate}"/> ${item.description}
                                </div><br/>
                            </c:when>
                            <c:when test="${item.state eq 'info'}">
                                <div class="alert-info">
                                    <fmt:formatDate pattern="dd-MM-yyyy" value="${item.triggerDate}"/> ${item.description}
                                </div><br/>
                            </c:when>
                        </c:choose>
                    </c:forEach>
                </div>
            </div>
        </div>
    </body>
</html>
