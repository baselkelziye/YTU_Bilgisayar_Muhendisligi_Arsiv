<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%--
  Created by IntelliJ IDEA.
  User: mgunes
  Date: 27.01.2017
  Time: 16:44
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
    <head>
        <jsp:include page="html/head.html"></jsp:include>
        <title>Parolamı Unuttum</title>
    </head>
    <body>
        <jsp:include page="html/header.jsp"></jsp:include>
        <div class="row">
            <div class="col-md-4"></div>
            <div class="col-md-4">
                <br/>
                <p>Şifrenizi yenilemeniz için size geçici bir parola göndereceğiz.</p>
                <form method="post" action="sendnewpassword">
                    <div class="form-group">
                        <label for="mail">Mail Adresiniz</label>
                        <input type="text" name="mail" id="mail" class="form-control">
                    </div>

                    <button type="submit" class="btn btn-primary">Gönder</button>
                </form>

                <c:choose>
                    <c:when test="${yeniparola eq 1}">
                        <div class="alert alert-success">
                            Geçici parolanız mail adresinize gönderildi.
                        </div>
                    </c:when>
                    <c:when test="${yeniparola eq 2}">
                        <div class="alert alert-danger">
                            Girdiğiniz mail adresi kayıtlarımızla eşleşmedi.
                        </div>
                    </c:when>
                </c:choose>
            </div>
        </div>
        <jsp:include page="html/footer.html"/>
    </body>
</html>
