<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>
<%@ taglib prefix="fn" uri="http://java.sun.com/jsp/jstl/functions" %>
<%--
  Created by IntelliJ IDEA.
  User: mgunes
  Date: 23.01.2017
  Time: 17:45
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
    <head>
        <jsp:include page="html/head.html"/>
        <title>Rapor Al</title>
    </head>
    <body>
        <jsp:include page="html/menu.html"/>
        <div class="jumbotron container-fluid">
            <div class="row">
                <div class="col-md-2"></div>
                <div class="col-md-8">
                    <ul class="nav nav-tabs">
                        <li><a href="../complaintlisttoadmin">Yeni</a></li>
                        <li><a href="../acceptedcomplaintlist">Onaylanan</a></li>
                        <li><a href="../rejectedcomplaintlist">Reddedilen</a></li>
                        <li class="active"><a style="background-color:#b9def0" href="../complaintreporttoadmin">Rapor Al</a></li>
                    </ul>
                    <br>

                    <table class="table table-stripped">
                        <thead>
                            <tr>
                                <th>İlan Adı</th>
                                <th>Yayın Tarihi</th>
                                <th>Şirket</th>
                                <th>Şikayet Sayısı</th>
                                <th>İşlem</th>
                            </tr>
                        </thead>
                        <tbody>
                            <c:if test="${fn:length(annList) eq 0}">
                                <tr><td><i>Rapor almaya uygun ilan yok.</i></td></tr>
                            </c:if>
                            <c:forEach var="item" items="${annList}">
                            <tr>
                                <td>${item.title}</td>
                                <td><fmt:formatDate pattern="dd-MM-yyy" value="${item.publishDate}"/></td>
                                <td>${item.ownerCompany.companyName}</td>
                                <td align="right">${fn:length(item.complaintList)}</td>
                                <td>
                                    <a  href="../reportannouncement?id=${item.id}"
                                        title="Rapor"
                                        class="open-detail btn btn-info">
                                        <span class="glyphicon glyphicon-th-large"></span>
                                    </a>
                                </td>
                            </tr>
                        </c:forEach>
                        </tbody>
                    </table>
                </div>
            </div>
        </div>
    </body>
</html>
