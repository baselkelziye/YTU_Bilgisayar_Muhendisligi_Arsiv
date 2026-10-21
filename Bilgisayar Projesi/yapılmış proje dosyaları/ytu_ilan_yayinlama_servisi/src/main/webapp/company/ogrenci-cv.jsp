<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>
<%--
  Created by IntelliJ IDEA.
  User: mgunes
  Date: 28.01.2017
  Time: 17:58
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
    <head>
        <jsp:include page="html/head.html"/>
        <title>CV</title>
            <script>
                $(document).ready(function(){
                    $('[data-toggle="popover"]').popover();
                });
            </script>
    </head>
    <body>
        <div class="jumbotron container-fluid">
            <div class="row">
                <div class="col-md-3"></div>
                <div class="col-md-5">
                    <div class="panel panel-primary">
                        <div class="panel-heading">
                            <p>${student.name} ${student.surname}</p>
                        </div>
                        <div class="panel-body">
                            <p>Kişisel Bilgiler</p>
                            <b>Adı:</b> ${student.name}<br/>
                            <b>Soyadı:</b> ${student.surname} <br/>
                            <b>Doğum Tarihi:</b> ${student.birthDate}

                            <br/>
                            <br/>
                            <p>İletişim Bilgileri</p>
                            <c:forEach var="item" items="${commWays}">
                                    <b>${item.pk.commType }</b>:  ${item.pk.commValue }<br/>
                            </c:forEach>

                            <br/>
                            <br/>
                            <p>Eğitim Bilgileri</p>
                            <table class="table table-stripped">
                                <thead>
                                    <th>Okul</th>
                                    <th>Derece</th>
                                    <th>Tarih</th>
                                </thead>
                                <tbody>
                                    <c:forEach var="item" items="${educationList}">
                                    <tr>
                                        <td>
                                            ${item.school}
                                            <a href="#" data-toggle="popover" data-placement="left"
                                               title="Okul Bilgisi:" data-content="Okul:${item.school} Bölüm:${item.department}">
                                                <span class="glyphicon glyphicon-info-sign "></span>
                                            </a>
                                        </td>
                                        <td>${item.degree}</td>
                                        <td>
                                                ${item.startDate} -
                                            <c:choose>
                                                <c:when test="${item.endDate eq 0}">
                                                    ?
                                                </c:when>
                                                <c:otherwise>
                                                    ${item.endDate}
                                                </c:otherwise>
                                            </c:choose>
                                        </td>
                                    </tr>
                                </c:forEach>
                                </tbody>
                            </table>
                        </div>
                        <div class="panel-footer">
                            Öğrenci ile iletişim kurmak sizin sorumluluğunuzdadır
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </body>
</html>
