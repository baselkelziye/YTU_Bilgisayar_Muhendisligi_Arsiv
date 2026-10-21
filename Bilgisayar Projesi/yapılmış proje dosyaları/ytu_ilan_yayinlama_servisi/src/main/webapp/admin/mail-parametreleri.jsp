<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%--
  Created by IntelliJ IDEA.
  User: mgunes
  Date: 27.01.2017
  Time: 14:00
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
    <head>
        <jsp:include page="html/head.html"/>
        <title>Mail Parametreleri</title>
    </head>
    <body>
        <jsp:include page="html/menu.html"/>
        <div class="jumbotron container-fluid">
            <div class="row">
                <div class="col-md-2"></div>
                <div class="col-md-4">
                    <div class="panel panel-primary">
                        <div class="panel panel-heading">
                            <p>Mail Parametreleri</p>
                        </div>
                        <div class="panel panel-body">
                            <c:choose>
                                <c:when test="${guncellendi eq 1}">
                                    <div class="alert alert-success">
                                        Parametreler Güncellendi.
                                    </div>
                                </c:when>
                                <c:when test="${guncellendi eq 2}">
                                    <div class="alert alert-danger">
                                        Bir hata meydana geldi.
                                    </div>
                                </c:when>
                            </c:choose>
                            <form method="POST" action="../updatemailparameters">
                                <div class="form-group">
                                    <label>Mail Adresi</label>
                                    <input type="text" class="form-control" name="mailAddress" value="${mailParameters['Mail Adresi']}">
                                </div>
                                <div class="form-group">
                                    <label>Kullanıcı Adı</label>
                                    <input type="text" class="form-control" name="username" value="${mailParameters['Kullanıcı Adı']}">
                                </div>
                                <div class="form-group">
                                    <label>Host</label>
                                    <input type="text" class="form-control" name="host" value="${mailParameters['Host']}">
                                </div>
                                <div class="form-group">
                                    <label>Port</label>
                                    <input type="text" class="form-control" name="port" value="${mailParameters['Port']}">
                                </div>

                                <button type="submit" class="btn btn-success">Güncelle</button>
                            </form>
                        </div>
                    </div>
                </div>
                <div class="col-md-4">
                    <div class="panel panel-primary">
                        <div class="panel panel-heading">
                            <p>Parolayı Değiştir</p>
                        </div>
                        <div class="panel panel-body">
                            <c:choose>
                                <c:when test="${parola eq 1}">
                                    <div class="alert alert-success">
                                        Parola Güncellendi.
                                    </div>
                                </c:when>
                                <c:when test="${parola eq 2}">
                                    <div class="alert alert-danger">
                                        Bir hata meydana geldi.
                                    </div>
                                </c:when>
                            </c:choose>
                            <form method="POST" action="../updatemailpassword">
                                <div class="form-group">
                                    <label>Parola</label>
                                    <input type="password" class="form-control" name="password">
                                </div>
                                <div class="form-group">
                                    <label>Parola (Tekrar)</label>
                                    <input type="password" class="form-control" name="passwordAgain">
                                </div>

                                <button type="submit" class="btn btn-success">Değiştir</button>
                            </form>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </body>
</html>
