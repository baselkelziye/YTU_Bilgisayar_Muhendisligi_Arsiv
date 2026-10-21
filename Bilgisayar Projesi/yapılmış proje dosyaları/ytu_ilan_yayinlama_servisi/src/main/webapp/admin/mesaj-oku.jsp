<%@ page language="java" contentType="text/html; charset=ISO-8859-9"
    pageEncoding="ISO-8859-9"%>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>

<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <jsp:include page="html/head.html"/>
		<title>Mesaj Detayları</title>
	</head>
	<body>
        <jsp:include page="html/menu.html"/>
		<div class="jumbotron container-fluid">
			<div class="row">
                <div class="col-md-3"></div>
				<div class="col-md-9">
                    <c:if test = "${mesajyok == 1 }">
                        <div class  = "alert alert-danger">
                            Mesaj getirilirken bir sorun oluştu
                        </div>
                    </c:if>
					<table class="table table-hover">
						<tr>
							<td>Mesaj No</td>
							<td>${message.messageNo}</td>
						</tr>
						<tr>
							<td>Başlık</td>
							<td>${message.messageTitle}</td>
						</tr>
						<tr>
							<td>İçerik</td>
							<td>${message.messageBody }</td>
						</tr>
						<tr>
							<td>Gönderen</td>
							<td>${message.senderName} ${item.senderSurname}</td>
						</tr>
						<tr>
							<td>Zaman</td>
							<td><fmt:formatDate pattern="dd-MM-yyyy" value="${message.pk.dateTime}" /></td>
						</tr>
						<tr>
							<td>IP Adresi</td>
							<td>${message.IPAddress }
						</tr>
						</tbody>
					</table>

					<a href="../readmessageservlet" class="btn btn-info btn-lg">
					  <span class="glyphicon glyphicon-arrow-left"></span> Mesaj Listesi
					</a>
				</div>
			</div>
		</div>

		<jsp:include page="html/footer.html"/>
	</body>
</html>