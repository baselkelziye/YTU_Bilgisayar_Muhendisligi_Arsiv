<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="fmt" uri="http://java.sun.com/jsp/jstl/fmt" %>

<!DOCTYPE html>
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-9">
		<jsp:include page="../html/head.html"></jsp:include>
		<title>Başvurular</title>
	</head>
	<body>
		<jsp:include page="html/menu.html"/>
		<div class="jumbotron container-fluid">
			<div class="row">
 				<div class="col-md-3"></div>
 				<div class="col-md-7">
 					<h4>Yapmış Olduğunuz Başvurular</h4>
 					<table class="table table-hover">
 						<thead>
 							<tr>
 								<th>İlan Adı</th>
 								<th>İlanın Durumu</th>
 								<th>Başvuru Zamanı</th>
 								<th>İşlem</th>
 							</tr>
 						</thead>
 						<tbody>
							<c:forEach var="item" items="${student.myApplications }">
								<tr>
									<td>${item.pk.announcement.title }</td>
									<td>${item.pk.announcement.state.title }</td>
									<td><fmt:formatDate pattern="dd-MM-yyyy" value="${item.timeToApplication}"/></td>
									<td>
										<form>
											<input type="hidden" name="deleteUrl" value="myapplications">
											<input type="hidden" name="announcement" value="${item.pk.announcement.id }">
											<input type="submit" class="btn btn-default"
												formaction="../announcementdetailtostudent" value="İlana Git"/>
											<input type="submit" class="btn btn-default"
                                                formaction="../deleteapplication" value="Başvuruyu Geri Çek"/>
										</form>
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