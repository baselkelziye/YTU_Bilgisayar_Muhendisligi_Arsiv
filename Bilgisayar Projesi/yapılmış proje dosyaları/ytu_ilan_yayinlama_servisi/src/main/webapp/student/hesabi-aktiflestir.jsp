<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>
<%--
  Created by IntelliJ IDEA.
  User: mgunes
  Date: 25.01.2017
  Time: 10:50
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
    <head>
        <jsp:include page="html/head.html"></jsp:include>
        <title>Hesabınızı Aktifleştirin</title>
    </head>
    <body>
        <jsp:include page="html/menu.html"/>
        <div class="jumbotron container-fluid">
            <div class="row">
                <div class="col-md-4"></div>
                <div class="col-md-4">
                    <c:choose>
                        <c:when test="${yenikod eq 1}">
                            <div class="alert alert-success">
                                Mail adresinize yeni bir kod gönderildi.
                            </div>
                        </c:when>
                        <c:when test="${yenikod eq 2}">
                            <div class="alert alert-danger">
                                Bir hata meydana geldi.<br/>
                                Lütfen daha sonra tekrar deneyin.
                            </div>
                        </c:when>
                    </c:choose>
                    <c:choose>
                        <c:when test="${aktif eq 1}">
                            <div class="alert alert-success">
                                Aktifleştirme işlemi başarılı.
                            </div>
                        </c:when>
                        <c:when test="${aktif eq 0}">
                            <div class="alert alert-warning">
                                Girilen kod yanlış.
                            </div>
                        </c:when>
                        <c:when test="${aktif eq 2}">
                            <div class="alert alert-danger">
                                Bir hata meydana geldi.<br/>
                                Lütfen daha sonra tekrar deneyin.
                            </div>
                        </c:when>
                    </c:choose>
                    <c:choose>
                        <c:when test="${user.status eq 1 }">
                            <div class="alert alert-success">
                                Hesabınız aktif hale getirilmiştir. <br/>
                                İşlem Tarihi : <fmt:formatDate pattern="dd-MM-yyy" value="${operationDate}"/>
                            </div>
                        </c:when>
                        <c:otherwise>
                            <form method="post">
                                <div class="form-group">
                                    <label for="code">Kodu Giriniz</label>
                                    <input type="text" id="code" name="code" class="form-control">
                                </div>
                                <input type="submit" formaction="../sendcodebystudent" class="btn btn-success" value="Aktifleştir">
                                <input type="submit" formaction="../resendcodetostudent" class="btn btn-primary" value="Kodu Yeniden Gönder">
                            </form>
                        </c:otherwise>
                    </c:choose>
                </div>
            </div>
        </div>
    </body>
</html>
